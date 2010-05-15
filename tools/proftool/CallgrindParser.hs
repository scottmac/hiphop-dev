module CallgrindParser (HeaderLine, Part(Part), Record(Leaf, Assoc), parseData) where
import Text.Parsec
import Text.Parsec.Char
import Text.Parsec.String
import Text.Parsec.Combinator

(<||>) p1 p2 = try p1 <|> p2

tok s v = do
  string s
  return v

data HeaderLine = Events [String]
  deriving Show
data BodyLine = PosSpecLine PosType String
              | AssocSpecLine [Int] [Int]
              | CostLine [Int]
              | EmptyBodyLine
  deriving Show

data Record = Leaf String String [Int]
            | Assoc String String String String [Int] [Int]
  deriving Show

bodyLinesToRecords [] fl fn cfl cfn acc = acc
bodyLinesToRecords (ln:t) fl fn cfl cfn acc =
  case ln of
    PosSpecLine Fl s -> bodyLinesToRecords t s fn cfl cfn acc
    PosSpecLine Fn s -> bodyLinesToRecords t fl s cfl cfn acc
    PosSpecLine Cfl s -> bodyLinesToRecords t fl fn s cfn acc
    PosSpecLine Cfn s -> bodyLinesToRecords t fl fn cfl s acc
    AssocSpecLine n1 n2 -> bodyLinesToRecords t "" "" "" ""
                             ((Assoc fl fn cfl cfn n1 n2):acc)
    CostLine n -> bodyLinesToRecords t "" "" "" "" ((Leaf fl fn n):acc)
    EmptyBodyLine -> bodyLinesToRecords t fl fn cfl cfn acc

data PosType = Fl | Fn | Cfl | Cfn
  deriving Show

data Part = Part [HeaderLine] [Record]
  deriving Show

profileDataFile :: Parser [Part]
profileDataFile = do
  pdata <- many partData
  return pdata

partData :: Parser Part
partData = do
  hl <- many1 (do{ hl <- headerLine; newline; return hl})
  bl <- many1 (do{ bl <- bodyLine; newline; return bl})
  return $ Part hl (bodyLinesToRecords bl "" "" "" "" [])

headerLine = costLineDef

costLineDef = do
  string "events:"
  spacs
  n <- name
  ns <- many (many1 spac >> name)
  return $ Events (n:ns)

bodyLine = assocSpec <||> posSpec <||> costLine <||> return EmptyBodyLine

costLine = do
  nl <- numberList
  return $ CostLine nl

posSpec = do
  p <- position
  char '='
  spacs
  name <- positionName
  return $ PosSpecLine p name

position = tok "fl" Fl <||> tok "fn" Fn <||> tok "cfl" Cfl <||>
  tok "cfn" Cfn

positionName = many noNewLineChar

assocSpec = do
  string "calls="
  spacs
  nl <- numberList
  newline
  cl <- numberList
  return $ AssocSpecLine nl cl

spac = oneOf " \t"
spacs = many spac

name = do
 l <- letter
 ls <- many alphaNum
 return $ l:ls

number :: Parser Int
number = hexNumber <||> baseTenNumber
baseTenNumber = do
  ds <- many1 digit
  return (read ds)
hexNumber = do
  string "0x"
  ds <- many1 hexDigit
  return (read $ "0x" ++ ds)

numberList = sepBy1 number (many1 spac)

noNewLineChar = noneOf "\n"

test = do
  c <- readFile "test.cg"
  parseTest profileDataFile c

parseData = parseFromFile profileDataFile
