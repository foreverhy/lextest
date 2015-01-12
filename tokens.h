#ifndef VLEX_TOKEN_H
#define VLEX_TOKEN_H 1

#include <string>
#include <FlexLexer.h>

namespace vlex{

struct YYSTYPE{
	int pos;
	int ival;
    std::string sval;
};

extern YYSTYPE yylval;
extern yyFlexLexer *lexer;

const int ID   = 257;
const int STRING  = 258;
const int INT = 259;
const int COMMA = 260;
const int COLON = 261;
const int SEMICOLON = 262;
const int LPAREN = 263;
const int RPAREN = 264;
const int LBRACK = 265;
const int RBRACK = 266;
const int LBRACE = 267;
const int RBRACE = 268;
const int DOT = 269;
const int PLUS = 270;
const int MINUS = 271;
const int TIMES = 272;
const int DIVIDE = 273;
const int EQ = 274;
const int NEQ = 275;
const int LT = 276;
const int LE = 277;
const int GT = 278;
const int GE = 279;
const int AND = 280;
const int OR = 281;
const int ASSIGN = 282;
const int ARRAY = 283;
const int IF = 284;
const int THEN = 285;
const int ELSE = 286;
const int WHILE = 287;
const int FOR = 288;
const int TO = 289;
const int DO = 290;
const int LET = 291;
const int IN = 292;
const int END = 293;
const int OF = 294;
const int BREAK = 295;
const int NIL = 296;
const int FUNCTION = 297;
const int VAR = 298;
const int TYPE = 299;


}// namespace vlex

#endif
