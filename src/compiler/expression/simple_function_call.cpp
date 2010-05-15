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

#include <compiler/expression/simple_function_call.h>
#include <compiler/analysis/dependency_graph.h>
#include <compiler/analysis/file_scope.h>
#include <compiler/analysis/function_scope.h>
#include <compiler/analysis/class_scope.h>
#include <compiler/analysis/code_error.h>
#include <compiler/expression/expression_list.h>
#include <compiler/statement/statement_list.h>
#include <compiler/expression/scalar_expression.h>
#include <compiler/expression/constant_expression.h>
#include <compiler/analysis/constant_table.h>
#include <compiler/analysis/variable_table.h>
#include <util/util.h>
#include <compiler/option.h>
#include <compiler/expression/simple_variable.h>
#include <compiler/parser/parser.h>
#include <runtime/base/type_string.h>
#include <runtime/base/type_variant.h>

using namespace HPHP;
using namespace std;
using namespace boost;

///////////////////////////////////////////////////////////////////////////////
// statics

std::map<std::string, int>SimpleFunctionCall::FunctionTypeMap;

#define CHECK_HOOK(n) \
do { \
  if (SimpleFunctionCall::m_hookHandler) { \
    SimpleFunctionCall::m_hookHandler(ar, this, n); \
  } \
} while (0)

void (*SimpleFunctionCall::m_hookHandler)
  (AnalysisResultPtr ar, SimpleFunctionCall *call, HphpHookUniqueId id);

void SimpleFunctionCall::InitFunctionTypeMap() {
  if (FunctionTypeMap.empty()) {
    FunctionTypeMap["define"]               = DefineFunction;
    FunctionTypeMap["create_function"]      = CreateFunction;

    FunctionTypeMap["func_get_arg"]         = VariableArgumentFunction;
    FunctionTypeMap["func_get_args"]        = VariableArgumentFunction;
    FunctionTypeMap["func_num_args"]        = VariableArgumentFunction;

    FunctionTypeMap["extract"]              = ExtractFunction;
    FunctionTypeMap["compact"]              = CompactFunction;

    FunctionTypeMap["shell_exec"]           = ShellExecFunction;
    FunctionTypeMap["exec"]                 = ShellExecFunction;
    FunctionTypeMap["passthru"]             = ShellExecFunction;
    FunctionTypeMap["system"]               = ShellExecFunction;

    FunctionTypeMap["defined"]              = DefinedFunction;
    FunctionTypeMap["function_exists"]      = FunctionExistsFunction;
    FunctionTypeMap["class_exists"]         = ClassExistsFunction;
    FunctionTypeMap["interface_exists"]     = InterfaceExistsFunction;
    FunctionTypeMap["constant"]             = ConstantFunction;

    FunctionTypeMap["unserialize"]          = UnserializeFunction;

    FunctionTypeMap["get_defined_vars"]     = GetDefinedVarsFunction;
  }
}

///////////////////////////////////////////////////////////////////////////////
// constructors/destructors

SimpleFunctionCall::SimpleFunctionCall
(EXPRESSION_CONSTRUCTOR_PARAMETERS,
 const std::string &name, ExpressionListPtr params,
 const std::string *classname)
  : FunctionCall(EXPRESSION_CONSTRUCTOR_PARAMETER_VALUES,
                 ExpressionPtr(), name, params, classname),
    m_type(UnknownType), m_dynamicConstant(false),
    m_parentClass(false), m_builtinFunction(false), m_noPrefix(false),
    m_invokeFewArgsDecision(true),
    m_dynamicInvoke(false),
    m_hookData(NULL) {

  m_dynamicInvoke = Option::DynamicInvokeFunctions.find(m_name) !=
    Option::DynamicInvokeFunctions.end();

  if (m_className.empty()) {
    if (FunctionTypeMap.empty()) InitFunctionTypeMap();
    map<string, int>::const_iterator iter =
      FunctionTypeMap.find(m_name);
    if (iter != FunctionTypeMap.end()) {
      m_type = iter->second;
    }
  }
}

SimpleFunctionCall::~SimpleFunctionCall() {
  if (m_hookData) {
    ASSERT(m_hookHandler);
    m_hookHandler(AnalysisResultPtr(), this, hphpUniqueDtor);
  }
}

ExpressionPtr SimpleFunctionCall::clone() {
  SimpleFunctionCallPtr exp(new SimpleFunctionCall(*this));
  FunctionCall::deepCopy(exp);
  exp->m_params = Clone(m_params);
  return exp;
}

///////////////////////////////////////////////////////////////////////////////
// parser functions

void SimpleFunctionCall::onParse(AnalysisResultPtr ar) {
  FileScopePtr fs = ar->getFileScope();
  ConstructPtr self = shared_from_this();
  if (m_className.empty()) {
    CodeErrorPtr codeError = ar->getCodeError();
    switch (m_type) {
    case CreateFunction:
      if (m_params->getCount() == 2 &&
          (*m_params)[0]->isLiteralString() &&
          (*m_params)[1]->isLiteralString()) {
        FunctionScopePtr func = ar->getFunctionScope();
        if (func) func->disableInline();
        string params = (*m_params)[0]->getLiteralString();
        string body = (*m_params)[1]->getLiteralString();
        m_lambda = CodeGenerator::GetNewLambda();
        string code = "function " + m_lambda + "(" + params + ") "
          "{" + body + "}";
        ar->appendExtraCode(code);
      }
      break;
    case VariableArgumentFunction:
      ar->getFileScope()->setAttribute(FileScope::VariableArgument);
      break;
    case ExtractFunction:
      ar->getCodeError()->record(self, CodeError::UseExtract, self);
      ar->getFileScope()->setAttribute(FileScope::ContainsLDynamicVariable);
      ar->getFileScope()->setAttribute(FileScope::ContainsExtract);
      break;
    case CompactFunction:
      ar->getFileScope()->setAttribute(FileScope::ContainsDynamicVariable);
      ar->getFileScope()->setAttribute(FileScope::ContainsCompact);
      break;
    case ShellExecFunction:
      ar->getCodeError()->record(self, CodeError::UseShellExec, self);
      break;
    case GetDefinedVarsFunction:
      ar->getFileScope()->setAttribute(FileScope::ContainsGetDefinedVars);
      ar->getFileScope()->setAttribute(FileScope::ContainsCompact);
      break;
    default:
      CHECK_HOOK(onSimpleFunctionCallFuncType);
      break;
    }
  }

  string call = getText();
  string name = m_name;
  if (!m_className.empty()) {
    name = m_className + "::" + name;
  }
  ar->getDependencyGraph()->add(DependencyGraph::KindOfFunctionCall, call,
                                shared_from_this(), name);
}

///////////////////////////////////////////////////////////////////////////////
// static analysis functions

void SimpleFunctionCall::analyzeProgram(AnalysisResultPtr ar) {
  if (m_className.empty()) {
    addUserFunction(ar, m_name);
  } else if (m_className != "parent") {
    addUserClass(ar, m_className);
  } else {
    m_parentClass = true;
  }

  if (ar->getPhase() == AnalysisResult::AnalyzeInclude) {

    CHECK_HOOK(onSimpleFunctionCallAnalyzeInclude);

    ConstructPtr self = shared_from_this();

    // We need to know the name of the constant so that we can associate it
    // with this file before we do type inference.
    if (m_className.empty() && m_type == DefineFunction) {
      ScalarExpressionPtr name =
        dynamic_pointer_cast<ScalarExpression>((*m_params)[0]);
      string varName;
      if (name) {
        varName = name->getIdentifier();
        if (!varName.empty()) {
          ar->getFileScope()->declareConstant(ar, varName);
        }
      }
      // handling define("CONSTANT", ...);
      if (m_params && m_params->getCount() >= 2) {
        ScalarExpressionPtr name =
          dynamic_pointer_cast<ScalarExpression>((*m_params)[0]);
        string varName;
        if (name) {
          varName = name->getIdentifier();
          if (!varName.empty()) {
            ExpressionPtr value = (*m_params)[1];
            ConstantTablePtr constants =
              ar->findConstantDeclarer(varName)->getConstants();
            if (constants != ar->getConstants()) {
              constants->add(varName, NEW_TYPE(Some), value, ar, self);

              if (name->hasHphpNote("Dynamic")) {
                constants->setDynamic(ar, varName);
              }
            }
          }
        }
      }
    }

    if (m_type == UnserializeFunction) {
      ar->forceClassVariants();
    }
  }

  if (ar->getPhase() == AnalysisResult::AnalyzeAll) {
    // Look up the corresponding FunctionScope and ClassScope
    // for this function call
    {
      FunctionScopePtr func;
      ClassScopePtr cls;
      if (m_className.empty()) {
        func = ar->findFunction(m_name);
      } else {
        cls = ar->resolveClass(m_className);
        if (cls) {
          if (m_name == "__construct") {
            func = cls->findConstructor(ar, true);
          } else {
            func = cls->findFunction(ar, m_name, true, true);
          }
        }
      }
      if (func && !func->isRedeclaring()) {
        if (m_funcScope != func) {
          m_funcScope = func;
          Construct::recomputeEffects();
        }
      }
      if (cls && !cls->isRedeclaring())
        m_classScope = cls;
    }
    // check for dynamic constant and volatile function/class
    if (m_className.empty() &&
      (m_type == DefinedFunction ||
       m_type == FunctionExistsFunction ||
       m_type == ClassExistsFunction ||
       m_type == InterfaceExistsFunction) &&
      m_params && m_params->getCount() >= 1) {
      ExpressionPtr value = (*m_params)[0];
      if (value->isScalar()) {
        ScalarExpressionPtr name =
          dynamic_pointer_cast<ScalarExpression>(value);
        if (name && name->isLiteralString()) {
          string symbol = name->getLiteralString();
          switch (m_type) {
          case DefinedFunction: {
            ConstantTablePtr constants = ar->getConstants();
            if (!constants->isPresent(symbol)) {
              // user constant
              BlockScopePtr block = ar->findConstantDeclarer(symbol);
              if (block) { // found the constant
                constants = block->getConstants();
                // set to be dynamic
                constants->setDynamic(ar, symbol);
              }
            }
            break;
          }
          case FunctionExistsFunction: {
            FunctionScopePtr func = ar->findFunction(Util::toLower(symbol));
            if (func && func->isUserFunction()) {
              func->setVolatile();
            }
            break;
          }
          case InterfaceExistsFunction:
          case ClassExistsFunction: {
            ClassScopePtr cls = ar->findClass(Util::toLower(symbol));
            if (cls && cls->isUserClass()) {
              cls->setVolatile();
            }
            break;
          }
          default:
            ASSERT(false);
          }
        }
      }
    }
  }
  if (m_params) {
    if (ar->getPhase() == AnalysisResult::AnalyzeAll) {
      if (m_funcScope) {
        ExpressionList &params = *m_params;
        int mpc = m_funcScope->getMaxParamCount();
        for (int i = params.getCount(); i--; ) {
          ExpressionPtr p = params[i];
          if (i < mpc ? m_funcScope->isRefParam(i) :
              m_funcScope->isReferenceVariableArgument()) {
            p->setContext(Expression::RefValue);
          } else if (!(p->getContext() & Expression::RefParameter)) {
            p->clearContext(Expression::RefValue);
          }
        }
      } else {
        FunctionScopePtr func = ar->findFunction(m_name);
        if (func && func->isRedeclaring()) {
          FunctionScope::RefParamInfoPtr info =
            FunctionScope::GetRefParamInfo(m_name);
          if (info) {
            for (int i = m_params->getCount(); i--; ) {
              if (info->isRefParam(i)) {
                m_params->markParam(i, canInvokeFewArgs());
              }
            }
          }
        } else {
          m_params->markParams(false);
        }
      }
    }

    m_params->analyzeProgram(ar);
  }
}

bool SimpleFunctionCall::isDefineWithoutImpl(AnalysisResultPtr ar) {
  if (!m_className.empty()) return false;
  if (m_type == DefineFunction && m_params && m_params->getCount() >= 2) {
    if (m_dynamicConstant) return false;
    ScalarExpressionPtr name =
      dynamic_pointer_cast<ScalarExpression>((*m_params)[0]);
    if (!name) return false;
    string varName = name->getIdentifier();
    if (varName.empty()) return false;
    if (ar->getConstants()->isSystem(varName)) return true;
    ExpressionPtr value = (*m_params)[1];
    return (!ar->isConstantRedeclared(varName)) && value->isScalar();
  } else {
    return false;
  }
}

ExpressionPtr SimpleFunctionCall::preOptimize(AnalysisResultPtr ar) {
  ar->preOptimize(m_nameExp);
  ar->preOptimize(m_params);
  if (ar->getPhase() != AnalysisResult::SecondPreOptimize) {
    return ExpressionPtr();
  }
  // optimize away various "exists" functions, this may trigger
  // dead code elimination and improve type-inference.
  if (m_className.empty() &&
      (m_type == DefinedFunction ||
       m_type == FunctionExistsFunction ||
       m_type == ClassExistsFunction ||
       m_type == InterfaceExistsFunction) &&
      m_params && m_params->getCount() == 1) {
    ExpressionPtr value = (*m_params)[0];
    if (value->isScalar()) {
      ScalarExpressionPtr name = dynamic_pointer_cast<ScalarExpression>(value);
      if (name && name->isLiteralString()) {
        string symbol = name->getLiteralString();
        switch (m_type) {
        case DefinedFunction: {
          ConstantTablePtr constants = ar->getConstants();
          // system constant
          if (constants->isPresent(symbol)) {
            return CONSTANT("true");
          }
          // user constant
          BlockScopePtr block = ar->findConstantDeclarer(symbol);
          // not found (i.e., undefined)
          if (!block) {
            if (symbol.find("::") == std::string::npos) {
              return CONSTANT("false");
            } else {
              // e.g., defined("self::ZERO")
              return ExpressionPtr();
            }
          }
          constants = block->getConstants();
          // already set to be dynamic
          if (constants->isDynamic(symbol)) return ExpressionPtr();
          ConstructPtr decl = constants->getValue(symbol);
          ExpressionPtr constValue = dynamic_pointer_cast<Expression>(decl);
          if (constValue->isScalar()) {
            return CONSTANT("true");
          } else {
            return ExpressionPtr();
          }
          break;
        }
        case FunctionExistsFunction: {
          const std::string &lname = Util::toLower(symbol);
          if (Option::DynamicInvokeFunctions.find(lname) ==
              Option::DynamicInvokeFunctions.end()) {
            FunctionScopePtr func = ar->findFunction(lname);
            if (!func) {
              return CONSTANT("false");
            } else if (!func->isVolatile()) {
              return CONSTANT("true");
            }
          }
          break;
        }
        case InterfaceExistsFunction: {
          ClassScopePtr cls = ar->findClass(Util::toLower(symbol));
          if (!cls || !cls->isInterface()) {
            return CONSTANT("false");
          } else if (!cls->isVolatile()) {
            return CONSTANT("true");
          }
          break;
        }
        case ClassExistsFunction: {
          ClassScopePtr cls = ar->findClass(Util::toLower(symbol));
          if (!cls || cls->isInterface()) {
            return CONSTANT("false");
          } else if (!cls->isVolatile()) {
            return CONSTANT("true");
          }
          break;
        }
        default:
          ASSERT(false);
        }
      }
    }
  }
  return ExpressionPtr();
}

ExpressionPtr SimpleFunctionCall::postOptimize(AnalysisResultPtr ar) {
  if (!Option::KeepStatementsWithNoEffect && isDefineWithoutImpl(ar)) {
    Construct::recomputeEffects();
    return CONSTANT("true");
  }
  return FunctionCall::postOptimize(ar);
}

int SimpleFunctionCall::getLocalEffects() const {
  if (!m_params || m_params->isNoObjectInvolved()) {
    // Check if this function is known to have no side effects
    if (m_funcScope && !m_funcScope->hasEffect())
      return 0;
  }

  return UnknownEffect;
}

TypePtr SimpleFunctionCall::inferTypes(AnalysisResultPtr ar, TypePtr type,
                                       bool coerce) {
  ASSERT(false);
  return TypePtr();
}

TypePtr SimpleFunctionCall::inferAndCheck(AnalysisResultPtr ar, TypePtr type,
                                          bool coerce) {
  reset();

  ConstructPtr self = shared_from_this();

  // handling define("CONSTANT", ...);
  if (m_className.empty()) {
    if (m_type == DefineFunction && m_params && m_params->getCount() >= 2) {
      ScalarExpressionPtr name =
        dynamic_pointer_cast<ScalarExpression>((*m_params)[0]);
      string varName;
      if (name) {
        varName = name->getIdentifier();
        if (!varName.empty()) {
          ExpressionPtr value = (*m_params)[1];
          TypePtr varType = value->inferAndCheck(ar, NEW_TYPE(Some), false);
          ar->getDependencyGraph()->
            addParent(DependencyGraph::KindOfConstant,
                      ar->getName(), varName, self);
          ConstantTablePtr constants =
            ar->findConstantDeclarer(varName)->getConstants();
          if (constants != ar->getConstants()) {
            if (value && !value->isScalar()) {
              constants->setDynamic(ar, varName);
              varType = Type::Variant;
            }
            if (constants->isDynamic(varName)) {
              m_dynamicConstant = true;
              ar->getScope()->getVariables()->
                setAttribute(VariableTable::NeedGlobalPointer);
            } else {
              constants->setType(ar, varName, varType, true);
            }
            // in case the old 'value' has been optimized
            constants->setValue(ar, varName, value);
          }
          return checkTypesImpl(ar, type, Type::Boolean, coerce);
        }
      }
      if (varName.empty() && ar->isFirstPass()) {
        ar->getCodeError()->record(self, CodeError::BadDefine, self);
      }
    } else if (m_type == ExtractFunction) {
      ar->getScope()->getVariables()->forceVariants(ar);
    }
  }

  FunctionScopePtr func;

  // avoid raising both MissingObjectContext and UnknownFunction
  bool errorFlagged = false;

  if (m_className.empty()) {
    func = ar->findFunction(m_name);
  } else {
    ClassScopePtr cls = ar->resolveClass(m_className);
    if (cls && cls->isVolatile()) {
      ar->getScope()->getVariables()
        ->setAttribute(VariableTable::NeedGlobalPointer);
    }
    if (!cls || cls->isRedeclaring()) {
      if (cls) {
        m_redeclaredClass = true;
      }
      if (!cls && ar->isFirstPass()) {
        ar->getCodeError()->record(self, CodeError::UnknownClass, self);
      }
      if (m_params) {
        m_params->inferAndCheck(ar, NEW_TYPE(Some), false);
      }
      return checkTypesImpl(ar, type, Type::Variant, coerce);
    }
    m_derivedFromRedeclaring = cls->derivesFromRedeclaring();
    m_validClass = true;

    if (m_name == "__construct") {
      // if the class is known, php will try to identify class-name ctor
      func = cls->findConstructor(ar, true);
    }
    else {
      func = cls->findFunction(ar, m_name, true, true);
    }

    if (func && !func->isStatic()) {
      ClassScopePtr clsThis = ar->getClassScope();
      FunctionScopePtr funcThis = ar->getFunctionScope();
      if (!clsThis ||
          (clsThis->getName() != m_className &&
           !clsThis->derivesFrom(ar, m_className)) ||
          funcThis->isStatic()) {
        // set the method static to avoid "unknown method" runtime exception
        if (Option::StaticMethodAutoFix && !func->containsThis()) {
          func->setStatic();
        }
        if (ar->isFirstPass()) {
          ar->getCodeError()->record(self, CodeError::MissingObjectContext,
                                     self);
          errorFlagged = true;
        }
        func.reset();
      }
    }
  }
  if (!func || func->isRedeclaring()) {
    if (func) {
      m_redeclared = true;
      ar->getScope()->getVariables()->
        setAttribute(VariableTable::NeedGlobalPointer);
    }
    if (!func && !errorFlagged && ar->isFirstPass()) {
      ar->getCodeError()->record(self, CodeError::UnknownFunction, self);
    }
    if (m_params) {
      if (func) {
        FunctionScope::RefParamInfoPtr info =
          FunctionScope::GetRefParamInfo(m_name);
        ASSERT(info);
        for (int i = m_params->getCount(); i--; ) {
          if (info->isRefParam(i)) {
            m_params->markParam(i, canInvokeFewArgs());
          }
        }
      }
      m_params->inferAndCheck(ar, NEW_TYPE(Some), false);
    }
    return checkTypesImpl(ar, type, Type::Variant, coerce);
  }
  m_builtinFunction = !func->isUserFunction();

  if (m_redeclared) {
    if (m_params) {
      m_params->inferAndCheck(ar, NEW_TYPE(Some), false);
    }
    return checkTypesImpl(ar, type, type, coerce);
  }

  CHECK_HOOK(beforeSimpleFunctionCallCheck);

  m_valid = true;
  type = checkParamsAndReturn(ar, type, coerce, func);

  if (!m_valid && m_params) {
    m_params->markParams(false);
  }

  CHECK_HOOK(afterSimpleFunctionCallCheck);

  return type;
}

///////////////////////////////////////////////////////////////////////////////
// code generation functions

void SimpleFunctionCall::outputPHP(CodeGenerator &cg, AnalysisResultPtr ar) {
  outputLineMap(cg, ar);

  if (!m_className.empty()) {
    cg.printf("%s::%s(", m_className.c_str(), m_name.c_str());
  } else {

    if (cg.getOutput() == CodeGenerator::InlinedPHP ||
        cg.getOutput() == CodeGenerator::TrimmedPHP) {

      if (cg.getOutput() == CodeGenerator::TrimmedPHP &&
          cg.usingStream(CodeGenerator::PrimaryStream) &&
          Option::DynamicFunctionCalls.find(m_name) !=
          Option::DynamicFunctionCalls.end()) {
        int funcNamePos = Option::DynamicFunctionCalls[m_name];
        if (m_params && m_params->getCount() &&
            m_params->getCount() >= funcNamePos + 1) {
          if (funcNamePos == -1) funcNamePos = m_params->getCount() - 1;
          ExpressionPtr funcName = (*m_params)[funcNamePos];
          if (!funcName->is(Expression::KindOfScalarExpression)) {

            cg.printf("%s(", m_name.c_str());
            for (int i = 0; i < m_params->getCount(); i++) {
              if (i > 0) cg.printf(", ");
              if (i == funcNamePos) {
                cg.printf("%sdynamic_load(", Option::IdPrefix.c_str());
                funcName->outputPHP(cg, ar);
                cg.printf(")");
              } else {
                ExpressionPtr param = (*m_params)[i];
                if (param) param->outputPHP(cg, ar);
              }
            }
            cg.printf(")");
            return;
          }
        }
      }
      /* simptodo: I dunno
      if (m_type == RenderTemplateFunction && !m_template.empty()) {
        cg.printf("%s_%s(", m_name.c_str(),
                  Util::getIdentifier(m_template).c_str());
      } else if (m_type == RenderTemplateIncludeFunction) {
        string templateName = ar->getProgram()->getCurrentTemplate();
        cg.printf("%s_%s(", m_name.c_str(),
                  Util::getIdentifier(templateName).c_str());
      } else {
      */
        cg.printf("%s(", m_name.c_str());
        //}

    } else {
      cg.printf("%s(", m_name.c_str());
    }
  }

  if (m_params) m_params->outputPHP(cg, ar);
  cg.printf(")");
}

void SimpleFunctionCall::outputCPPParamOrderControlled(CodeGenerator &cg,
                                                       AnalysisResultPtr ar) {
  if (m_className.empty()) {
    switch (m_type) {
    case ExtractFunction:
      cg.printf("extract(variables, ");
      FunctionScope::outputCPPArguments(m_params, cg, ar, 0, false);
      cg.printf(")");
      return;
    case CompactFunction:
      cg.printf("compact(variables, ");
      FunctionScope::outputCPPArguments(m_params, cg, ar, -1, true);
      cg.printf(")");
      return;
    default:
      break;
    }
  }
  bool volatileCheck = false;
  ClassScopePtr cls;
  if (!m_className.empty()) {
    cls = ar->findClass(m_className);
    if (cls && !ar->checkClassPresent(m_origClassName)) {
      volatileCheck = true;
      cls->outputVolatileCheckBegin(cg, ar, cls->getOriginalName());
    }
  }
  if (m_valid) {
    bool tooManyArgs =
      (m_params && m_params->outputCPPTooManyArgsPre(cg, ar, m_name));
    if (!m_className.empty()) {
      cg.printf("%s%s::", Option::ClassPrefix, m_className.c_str());
      if (m_name == "__construct" && cls) {
        FunctionScopePtr func = cls->findConstructor(ar, true);
        cg.printf("%s%s(", Option::MethodPrefix, func->getName().c_str());
      } else {
        cg.printf("%s%s(", Option::MethodPrefix, m_name.c_str());
      }
    } else {
      int paramCount = m_params ? m_params->getCount() : 0;
      if (m_name == "get_class" && ar->getClassScope() && paramCount == 0) {
        cg.printf("(\"%s\"", ar->getClassScope()->getOriginalName());
      } else if (m_name == "get_parent_class" && ar->getClassScope() &&
                 paramCount == 0) {
        const std::string parentClass = ar->getClassScope()->getParent();
        if (!parentClass.empty()) {
          cg.printf("(\"%s\"", ar->getClassScope()->getParent().c_str());
        } else {
          cg.printf("(false");
        }
      } else {
        if (m_noPrefix) {
          cg.printf("%s(", m_name.c_str());
        }
        else {
         cg.printf("%s%s(", m_builtinFunction ? Option::BuiltinFunctionPrefix :
                   Option::FunctionPrefix, m_name.c_str());
        }
      }
    }
    FunctionScope::outputCPPArguments(m_params, cg, ar, m_extraArg,
                                      m_variableArgument, m_argArrayId);
    cg.printf(")");
    if (tooManyArgs) {
      m_params->outputCPPTooManyArgsPost(cg, ar, m_voidReturn);
    }
  } else {
    if (m_className.empty()) {
      if (m_redeclared && !m_dynamicInvoke) {
        if (canInvokeFewArgs()) {
          cg.printf("%s->%s%s_few_args(", cg.getGlobals(ar),
                    Option::InvokePrefix, m_name.c_str());
          int left = Option::InvokeFewArgsCount;
          if (m_params && m_params->getCount()) {
            left -= m_params->getCount();
            cg.printf("%d, ", m_params->getCount());
            FunctionScope::outputCPPArguments(m_params, cg, ar, 0, false);
          } else {
            cg.printf("0");
          }
          for (int i = 0; i < left; i++) {
            cg.printf(", null_variant");
          }
          cg.printf(")");
          return;
        } else {
          cg.printf("%s->%s%s(", cg.getGlobals(ar), Option::InvokePrefix,
                    m_name.c_str());
        }
      } else {
        cg.printf("invoke(\"%s\", ", m_name.c_str());
      }
    } else {
      bool inObj = m_parentClass && ar->getClassScope() &&
        !dynamic_pointer_cast<FunctionScope>(ar->getScope())->isStatic();
      if (m_redeclaredClass) {
        if (inObj) {  // parent is redeclared
          cg.printf("parent->%sinvoke(\"%s\",", Option::ObjectPrefix,
                    m_name.c_str());
        } else {
          cg.printf("%s->%s%s->%sinvoke(\"%s\", \"%s\",",
                    cg.getGlobals(ar),
                    Option::ClassStaticsObjectPrefix,
                    m_className.c_str(), Option::ObjectStaticPrefix,
                    m_className.c_str(),
                    m_name.c_str());
        }
      } else if (m_validClass) {
        if (inObj) {
          cg.printf("%s%s::%sinvoke(\"%s\",",
                    Option::ClassPrefix, m_className.c_str(),
                    Option::ObjectPrefix, m_name.c_str());
        } else {
          cg.printf("%s%s::%sinvoke(\"%s\", \"%s\",",
                    Option::ClassPrefix, m_className.c_str(),
                    Option::ObjectStaticPrefix,
                    m_className.c_str(),
                    m_name.c_str());
        }
      } else {
        cg.printf("invoke_static_method(\"%s\", \"%s\",",
                  m_className.c_str(), m_name.c_str());
      }
    }
    if ((!m_params) || (m_params->getCount() == 0)) {
      cg.printf("Array()");
    } else {
      FunctionScope::outputCPPArguments(m_params, cg, ar, -1, false);
    }
    bool needHash = true;
    if (m_className.empty()) {
      needHash = !(m_redeclared && !m_dynamicInvoke);
    } else {
      needHash = m_validClass || m_redeclaredClass;
    }
    if (!needHash) {
      cg.printf(")");
    } else {
      cg.printf(", 0x%.16lXLL)", hash_string_i(m_name.data(), m_name.size()));
    }
  }
  if (volatileCheck) {
    cls->outputVolatileCheckEnd(cg);
  }
}

void SimpleFunctionCall::outputCPPImpl(CodeGenerator &cg,
                                       AnalysisResultPtr ar) {
  bool linemap = outputLineMap(cg, ar, true);

  if (!m_lambda.empty()) {
    cg.printf("\"%s\"", m_lambda.c_str());
    if (linemap) cg.printf(")");
    return;
  }

  if (m_className.empty()) {
    if (m_type == DefineFunction && m_params && m_params->getCount() >= 2) {
      ScalarExpressionPtr name =
        dynamic_pointer_cast<ScalarExpression>((*m_params)[0]);
      string varName;
      if (name) {
        varName = name->getIdentifier();
        ExpressionPtr value = (*m_params)[1];
        if (varName.empty()) {
          cg.printf("throw_fatal(\"bad define\")");
        } else if (m_dynamicConstant) {
          cg.printf("g->declareConstant(\"%s\", g->%s%s, ",
                    varName.c_str(), Option::ConstantPrefix,
                    varName.c_str());
          value->outputCPP(cg, ar);
          cg.printf(")");
        } else {
          bool needAssignment = true;
          bool isSystem = ar->getConstants()->isSystem(varName);
          if (isSystem ||
              ((!ar->isConstantRedeclared(varName)) && value->isScalar())) {
            needAssignment = false;
          }
          if (needAssignment) {
            cg.printf("%s%s = ", Option::ConstantPrefix, varName.c_str());
            value->outputCPP(cg, ar);
          }
        }
      } else {
        cg.printf("throw_fatal(\"bad define\")");
      }
      if (linemap) cg.printf(")");
      return;
    }
    if (m_name == "func_num_args") {
      cg.printf("num_args");
      if (linemap) cg.printf(")");
      return;
    }

    switch (m_type) {
    case VariableArgumentFunction:
      {
        FunctionScopePtr func =
          dynamic_pointer_cast<FunctionScope>(ar->getScope());
        if (func) {
          cg.printf("%s(", m_name.c_str());
          func->outputCPPParamsCall(cg, ar, true);
          if (m_params) {
            cg.printf(",");
            m_params->outputCPP(cg, ar);
          }
          cg.printf(")");
          if (linemap) cg.printf(")");
          return;
        }
      }
      break;
    case FunctionExistsFunction:
    case ClassExistsFunction:
    case InterfaceExistsFunction:
      {
        bool literalString = false;
        string symbol;
        if (m_params && m_params->getCount() == 1) {
          ExpressionPtr value = (*m_params)[0];
          if (value->isScalar()) {
            ScalarExpressionPtr name =
              dynamic_pointer_cast<ScalarExpression>(value);
            if (name && name->isLiteralString()) {
              literalString = true;
              symbol = name->getLiteralString();
            }
          }
        }
        if (literalString) {
          switch (m_type) {
          case FunctionExistsFunction:
            {
              const std::string &lname = Util::toLower(symbol);
              bool dynInvoke = Option::DynamicInvokeFunctions.find(lname) !=
                Option::DynamicInvokeFunctions.end();
              if (!dynInvoke) {
                FunctionScopePtr func = ar->findFunction(lname);
                if (func) {
                  if (!func->isDynamic()) {
                    if (func->isRedeclaring()) {
                      const char *name = func->getName().c_str();
                      cg.printf("(%s->%s%s != invoke_failed_%s)",
                                cg.getGlobals(ar), Option::InvokePrefix,
                                name, name);
                      break;
                    }
                    cg.printf("true");
                    break;
                  }
                } else {
                  cg.printf("false");
                  break;
                }
              }
              cg.printf("f_function_exists(\"%s\")", lname.c_str());
            }
            break;
          case ClassExistsFunction:
            {
              ClassScopePtr cls = ar->findClass(Util::toLower(symbol));
              if (cls && !cls->isInterface()) {
                const char *name = cls->getName().c_str();
                cg.printf("f_class_exists(\"%s\")", name);
              } else {
                cg.printf("false");
              }
            }
            break;
          case InterfaceExistsFunction:
            {
              ClassScopePtr cls = ar->findClass(Util::toLower(symbol));
              if (cls && cls->isInterface()) {
                const char *name = cls->getName().c_str();
                cg.printf("f_interface_exists(\"%s\")", name);
              } else {
                cg.printf("false");
              }
            }
            break;
          default:
            break;
          }
          if (linemap) cg.printf(")");
          return;
        }
      }
      break;
    case GetDefinedVarsFunction:
      cg.printf("get_defined_vars(variables)");
      if (linemap) cg.printf(")");
      return;
    default:
      break;
    }
  }

  outputCPPParamOrderControlled(cg, ar);
  if (linemap) cg.printf(")");
}

bool SimpleFunctionCall::canInvokeFewArgs() {
  // We can always change out minds about saying yes, but once we say
  // no, it sticks.
  if (m_dynamicInvoke ||
      (m_invokeFewArgsDecision && m_params &&
       m_params->getCount() > Option::InvokeFewArgsCount)) {
    m_invokeFewArgsDecision = false;
  }
  return m_invokeFewArgsDecision;
}
