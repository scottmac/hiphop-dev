/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010 Facebook, Inc. (http://www.facebook.com)          |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/

#ifndef __ANALYSIS_RESULT_H__
#define __ANALYSIS_RESULT_H__

#include <compiler/code_generator.h>
#include <compiler/analysis/code_error.h>
#include <compiler/option.h>
#include <compiler/analysis/block_scope.h>
#include <compiler/analysis/function_container.h>
#include <compiler/package.h>
#include <boost/graph/adjacency_list.hpp>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////


DECLARE_BOOST_TYPES(ClassScope);
DECLARE_BOOST_TYPES(FileScope);
DECLARE_BOOST_TYPES(FunctionScope);
DECLARE_BOOST_TYPES(DependencyGraph);
DECLARE_BOOST_TYPES(CodeError);
DECLARE_BOOST_TYPES(Location);
DECLARE_BOOST_TYPES(AnalysisResult);
DECLARE_BOOST_TYPES(ScalarExpression);

class AnalysisResult : public BlockScope, public FunctionContainer {
public:
  /**
   * There are multiple passes over our syntax trees. This lists all of them.
   */
  enum Phase {
    // analyzeProgram
    AnalyzeInclude,
    AnalyzeTopLevel,
    AnalyzeAll,
    AnalyzeFinal,

    // pre-optimize
    FirstPreOptimize,
    SecondPreOptimize,

    // inferTypes
    FirstInference,
    SecondInference,
    MoreInference,
    LastInference,

    // post-optimize
    PostOptimize,
  };

  enum FindClassBy {
    ClassName,
    MethodName,
    PropertyName
  };

public:
  AnalysisResult();
  AnalysisResult(FileScopePtr file);

  void setPackage(Package *package) { m_package = package;}
  void setParseOnDemand(bool v) { m_parseOnDemand = v;}
  bool isParseOnDemand() { return m_package && m_parseOnDemand;}

  /**
   * create_function() generates extra PHP code that defines the lambda.
   * Stores the code in a temporary string, so we can parse this as an
   * extra file appended to parsed code.
   */
  void appendExtraCode(const std::string &code);

  Phase getPhase() const { return m_phase;}
  void setPhase(Phase phase) { m_phase = phase;}
  bool isFirstPass() const {
    return m_phase == AnalyzeInclude || m_phase == FirstInference;
  }
  bool isSecondPass() const {
    return m_phase == SecondInference;
  }

  DependencyGraphPtr getDependencyGraph() {
    return m_dependencyGraph;
  }
  CodeErrorPtr getCodeError() {
    if (!m_codeError) {
      m_codeError = CodeErrorPtr(new CodeError(shared_from_this()));
    }
    return m_codeError;
  }
  int getFunctionCount() const;
  int getClassCount() const;
  void countReturnTypes(std::map<std::string, int> &counts);

  void addEntryPoint(const std::string &name);
  void addEntryPoints(const std::vector<std::string> &names);

  void loadBuiltins();
  void analyzeProgram();
  void analyzeProgramFinal();
  void inferTypes(int maxPass = 100);
  void dump();
  void visitFiles(void (*cb)(AnalysisResultPtr, StatementPtr, void*),
                  void *data);
  void preOptimize(int maxPass = 100);
  void postOptimize(int maxPass = 100);
  void incOptCounter() { m_optCounter++; }
  template<typename T>
  bool preOptimize(boost::shared_ptr<T> &before) {
    if (before) {
      boost::shared_ptr<T> after = boost::dynamic_pointer_cast<T>
        (before->preOptimize(shared_from_this()));
      if (after) {
        before = after;
        m_optCounter++;
        return true;
      }
    }
    return false;
  }
  template<typename T>
  bool postOptimize(boost::shared_ptr<T> &before) {
    if (before) {
      boost::shared_ptr<T> after = boost::dynamic_pointer_cast<T>
        (before->postOptimize(shared_from_this()));
      if (after) {
        before = after;
        m_optCounter++;
        return true;
      }
    }
    return false;
  }

  /**
   * When types are newly inferred, we need more passes, until no new types
   * are inferred.
   */
  void incNewlyInferred() {
    m_newlyInferred++;
  }

  void containsDynamicFunctionCall() { m_dynamicFunction = true;}
  void containsDynamicClass() { m_dynamicClass = true;}

  /**
   * Scalar array handling.
   */
  int registerScalarArray(ExpressionPtr pairs);

  void setInsideScalarArray(bool flag);
  bool getInsideScalarArray();
  std::string getScalarArrayCompressedText();

  /**
   * Force all class variables to be variants, since l-val or reference
   * of dynamic properties are used.
   */
  void forceClassVariants();

  /**
   * Force specified variable of all classes to be variants.
   */
  void forceClassVariants(const std::string &name);

  /**
   * Code generation functions.
   */
  bool outputAllPHP(CodeGenerator::Output output);
  void outputAllCPP(CodeGenerator::Output output, int clusterCount,
                    const std::string *compileDir);
  void outputAllCPP(CodeGenerator &cg); // mainly for unit test

  void outputCPPSystemImplementations(CodeGenerator &cg);
  void outputCPPFileRunDecls(CodeGenerator &cg);
  void outputCPPFileRunImpls(CodeGenerator &cg);
  void outputCPPRedeclaredFunctionDecl(CodeGenerator &cg);
  void outputCPPRedeclaredFunctionImpl(CodeGenerator &cg);
  void outputCPPRedeclaredClassDecl(CodeGenerator &cg);
  void outputCPPRedeclaredClassImpl(CodeGenerator &cg);
  void outputCPPDynamicConstantDecl(CodeGenerator &cg);
  void outputCPPDynamicConstantImpl(CodeGenerator &cg);
  void outputCPPScalarArrayDecl(CodeGenerator &cg);
  void outputCPPScalarArrayImpl(CodeGenerator &cg);
  void outputCPPScalarArrayInit(CodeGenerator &cg, int fileCount, int part);
  void outputCPPClassStaticInitializerFlags(CodeGenerator &cg,
                                            bool constructor);
  void outputCPPClassDeclaredFlags(CodeGenerator &cg);
  bool inExpression() { return m_inExpression; }
  void setInExpression(bool in) { m_inExpression = in; }
  bool wrapExpressionBegin(CodeGenerator &);
  bool wrapExpressionEnd(CodeGenerator &);

  /**
   * Parser creates a FileScope upon parsing a new file.
   */
  void setFileScope(FileScopePtr fileScope);
  FileScopePtr getFileScope() { return m_file;}
  FileScopePtr findFileScope(const std::string &name, bool parseOnDemand);
  const StringToFileScopePtrMap &getAllFiles() { return m_files;}
  const std::vector<FileScopePtr> &getAllFilesVector() {
    return m_fileScopes;
  }

  /**
   * When inferring types, it's important to push/pop correct a BlockScope
   * that has the right variable and constant symbol tables to look up and
   * check their types.
   */
  void pushScope(BlockScopePtr scope);
  void popScope();
  BlockScopePtr getScope() const { return m_scope;}
  ClassScopePtr getClassScope() const;
  FunctionScopePtr getFunctionScope() const;

  /**
   * To implement the silence operator correctly, we need to keep trace
   * of the current statement being parsed.
   */
  void pushStatement(StatementPtr stmt);
  void popStatement();
  StatementPtr getStatement() const { return m_stmt; }
  StatementPtr getStatementForSilencer() const;

  /**
   * Declarations
   */
  bool declareFunction(FunctionScopePtr funcScope);
  bool declareClass(ClassScopePtr classScope);
  bool declareConst(FileScopePtr fs, const std::string& name);

  /**
   * Dependencies
   */
  bool addClassDependency(FileScopePtr usingFile,
                          const std::string &className);
  bool addFunctionDependency(FileScopePtr usingFile,
                             const std::string &functionName);
  bool addIncludeDependency(FileScopePtr usingFile,
                            const std::string &includeFilename);
  bool addConstantDependency(FileScopePtr usingFile,
                             const std::string &constantName);
  void addCallee(StatementPtr stmt);

  /**
   * Find class by that name, and update class name if it's "self" or
   * "parent".
   */
  ClassScopePtr resolveClass(std::string &className);
  ClassScopePtr findClass(const std::string &className,
                          FindClassBy by = ClassName);
  const ClassScopePtrVec &findClasses(const std::string &className);
  bool classMemberExists(const std::string &name, FindClassBy by);
  bool checkClassPresent(const std::string &name);
  FunctionScopePtr findFunction(const std::string &funcName);
  FunctionScopePtr findHelperFunction(const std::string &funcName);
  BlockScopePtr findConstantDeclarer(const std::string &constName);
  bool isConstantDeclared(const std::string &constName);
  bool isConstantRedeclared(const std::string &constName);
  bool isBaseSysRsrcClass(const std::string &className);

  /**
   * For function declaration parsing.
   */
  FunctionContainerPtr getFunctionContainer();
  static std::string prepareFile(const char *root,
                                 const std::string &fileName, bool chop);

  void setOutputPath(const std::string &path) {
    m_outputPath = path;
  }
  const std::string &getOutputPath() {
    return m_outputPath;
  }

  /**
   * PHP source info functions.
   */
  void recordSourceInfo(const std::string &fileline, LocationPtr loc);
  void recordClassSource(const std::string &clsname,
                         const std::string &filename);
  void recordFunctionSource(const std::string &funcname,
                            const std::string &filename);

  /**
   * Literal string to String precomputation
   */
  void addLiteralString(const std::string s, ScalarExpressionPtr sc);
  int getLiteralStringId(const std::string &s);
  void getLiteralStringCompressed(std::string &zsdata, std::string &zldata);

  /**
   * Profiling runtime parameter type
   */
  std::string getFuncId(ClassScopePtr cls, FunctionScopePtr func);
  std::string getParamRTTIEntryKey(ClassScopePtr cls,
                                   FunctionScopePtr func,
                                   const std::string &paramName);
  void addParamRTTIEntry(ClassScopePtr cls,
                         FunctionScopePtr func,
                         const std::string &paramName);
  int getParamRTTIEntryId(ClassScopePtr cls,
                          FunctionScopePtr func,
                          const std::string &paramName);
  void addRTTIFunction(const std::string &id);
  void cloneRTTIFuncs(const char *RTTIDirectory);

  /**
   * For global state output
   */
  void outputCPPGlobalStateBegin(CodeGenerator &cg, const char *section);
  void outputCPPGlobalStateEnd(CodeGenerator &cg, const char *section);

  std::vector<const char *> &getFuncTableBucket(FunctionScopePtr func);

  /**
   * Generate default implementation for separable extension classes.
   */
  void outputCPPSepExtensionImpl(const std::string &filename);

private:
  Package *m_package;
  bool m_parseOnDemand;
  Phase m_phase;
  int m_newlyInferred;
  DependencyGraphPtr m_dependencyGraph;
  CodeErrorPtr m_codeError;
  StringToFileScopePtrMap m_files;
  FileScopePtrVec m_fileScopes;
  FileScopePtr m_file;
  std::string m_extraCode;

  StringToClassScopePtrMap m_systemClasses;
  StringToFunctionScopePtrVecMap m_functionDecs;
  StringToClassScopePtrVecMap m_classDecs;
  StringToClassScopePtrVecMap m_methodToClassDecs;
  StringToFileScopePtrMap m_constDecs;
  std::set<std::string> m_constRedeclared;
  std::set<std::string> m_baseSysRsrcClasses;

  bool m_dynamicClass;
  bool m_dynamicFunction;
  bool m_classForcedVariants;

  BlockScopePtrVec m_scopes;
  BlockScopePtr m_scope;

  StatementPtrVec m_stmts;
  StatementPtr m_stmt;

  StatementPtrVec m_callees;
  StatementPtrSet m_calleesAdded;
  std::string m_outputPath;
  int m_optCounter;

  std::map<std::string, int> m_scalarArrays;
  int m_scalarArraysCounter;
  std::vector<ExpressionPtr> m_scalarArrayIds;
  std::map<std::string, int> m_paramRTTIs;
  std::set<std::string> m_rttiFuncs;
  int m_paramRTTICounter;

  bool m_insideScalarArray;
  bool m_inExpression;
  bool m_wrappedExpression;
public:
  struct ScalarArrayExp {
    int id;
    int len;
    ExpressionPtr exp;
  };
private:
  int m_scalarArraySortedAvgLen;
  int m_scalarArraySortedIndex;
  int m_scalarArraySortedSumLen;
  std::vector<ScalarArrayExp> m_scalarArraySorted;
  int m_scalarArrayCompressedTextSize;

  typedef boost::adjacency_list<boost::setS, boost::vecS> Graph;
  typedef boost::graph_traits<Graph>::vertex_descriptor vertex_descriptor;
  typedef boost::graph_traits<Graph>::adjacency_iterator adjacency_iterator;
  Graph m_depGraph;
  typedef std::map<vertex_descriptor, FileScopePtr> VertexToFileScopePtrMap;
  VertexToFileScopePtrMap m_fileVertMap;
  void link(FileScopePtr user, FileScopePtr provider);
  void getTrueDeps(FileScopePtr f,
                   std::map<std::string, FileScopePtr> &trueDeps);
  void clusterByFileSizes(StringToFileScopePtrVecMap &clusters,
                          int clusterCount);

  std::map<std::string, LocationPtr> m_sourceInfos;
  std::map<std::string, std::set<std::string> > m_clsNameMap;
  std::map<std::string, std::set<std::string> > m_funcNameMap;

  std::map<std::string,
           std::pair<int, ScalarExpressionPtr> > m_stringLiterals;

  int m_funcTableSize;
  CodeGenerator::MapIntToStringVec m_funcTable;

  /**
   * Creates the global function table. Needs to be called before generating
   * cpp code for each toplevel function.
   */
  void createGlobalFuncTable();

  void outputCPPGlobalDeclarations();
  void outputCPPMain();
  void outputCPPScalarArrays(bool system);
  void outputCPPScalarArrays(CodeGenerator &cg, int fileCount, int part);
  void outputCPPGlobalVariablesMethods(int part);
  void outputCPPGlobalStateDynamicConstants(CodeGenerator &cg);
  void outputCPPGlobalStatePseudoMainVariables(CodeGenerator &cg);
  void outputCPPGlobalStateRedeclaredFunctions(CodeGenerator &cg);
  void outputCPPGlobalStateRedeclaredClasses(CodeGenerator &cg);
  void outputCPPGlobalState();
  void outputCPPClassStaticInitializerDecls(CodeGenerator &cg);
  void outputCPPClassIncludes(CodeGenerator &cg);
  void outputCPPExtClassImpl(CodeGenerator &cg);
  void outputCPPDynamicTables(CodeGenerator::Output output);
  void outputCPPDynamicTablesHeader(CodeGenerator &cg,
                                    bool includeGlobalVars = true,
                                    bool includes = true,
                                    bool noNamespace = false);
  void outputCPPClassMapFile();
  void outputCPPSourceInfos();
  void outputCPPNameMaps();
  void outputRTTIMetaData(const char *filename);
  void outputCPPClassMap(CodeGenerator &cg);
  void outputCPPSystem();
  void outputCPPGlobalImplementations(CodeGenerator &cg);
  void outputCPPClusterImpl(CodeGenerator &cg, const FileScopePtrVec &files);
  void outputCPPClassDeclaredFlagsLookup(CodeGenerator &cg);

  void repartitionCPP(const std::string &filename, int64 targetSize,
                      bool insideHPHP);
  void repartitionLargeCPP(const std::vector<std::string> &filenames,
                           const std::vector<std::string> &additionals);

  void outputCPPFFIStubs();
  void outputHSFFIStubs();

  /**
   * Outputs Java stubs.
   *
   * Each PHP file becomes a Java package, in which the HphpMain class
   * contains all the toplevel function definitions, and the rest of the
   * classes are one-to-one corresponding to the php classes declared in
   * that file.
   */
  void outputJavaFFIStubs();
  /**
   * Outputs one .h file that declares all the Java native method stubs,
   * avoiding javah for performance reason.
   */
  void outputJavaFFICppDecl();
  /**
   * Outputs one .cpp file that implements all the native methods declared
   * in the Java classes generated by outputJavaFFIStubs().
   */
  void outputJavaFFICppImpl();

  void outputSwigFFIStubs();

  void outputHexBuffer(CodeGenerator &cg, const char *name,
                       const char *buf, int len);
  void outputCPPLiteralStringPrecomputation();
  void outputCPPSepExtensionMake();

  void cloneRTTIFuncs(ClassScopePtr cls,
                      const StringToFunctionScopePtrVecMap &functions);

  AnalysisResultPtr shared_from_this() {
    return boost::static_pointer_cast<AnalysisResult>
      (BlockScope::shared_from_this());
  }
};

///////////////////////////////////////////////////////////////////////////////
}
#endif // __ANALYSIS_RESULT_H__
