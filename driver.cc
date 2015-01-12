#include <stdio.h>
#include <FlexLexer.h>
#include "util.h"
#include "errormsg.h"
#include "tokens.h"


//int yylex(void); [> prototype for the lexing function <]


std::string toknames[] = {
    "ID", "STRING", "INT", "COMMA", "COLON", "SEMICOLON", "LPAREN",
    "RPAREN", "LBRACK", "RBRACK", "LBRACE", "RBRACE", "DOT", "PLUS",
    "MINUS", "TIMES", "DIVIDE", "EQ", "NEQ", "LT", "LE", "GT", "GE",
    "AND", "OR", "ASSIGN", "ARRAY", "IF", "THEN", "ELSE", "WHILE", "FOR",
    "TO", "DO", "LET", "IN", "END", "OF", "BREAK", "NIL", "FUNCTION",
    "VAR", "TYPE"
};



std::string tokname(int tok) {
    return tok<257 || tok>299 ? "BAD_TOKEN" : toknames[tok-257];
}

vlex::YYSTYPE vlex::yylval;
yyFlexLexer* vlex::lexer = nullptr;

int main(int argc, char **argv) {
    if (argc!= 2) {
        fprintf(stderr,"usage: lextest inputfile < inputfile\n");
        exit(1);
    }
    using vlex::errormsg;

    std::string fname=argv[1];
    errormsg::reset(fname);
    vlex::lexer = new yyFlexLexer;
    for(;;) {
        int tok = vlex::lexer->yylex();
        if (0 == tok) break;
        switch(tok) {
            case vlex::ID: 
            case vlex::STRING:
                printf("%10s %4d %s\n",tokname(tok).data(),errormsg::tokpos, vlex::yylval.sval.data());
                break;
            case vlex::INT:
                printf("%10s %4d %d\n",tokname(tok).data(),errormsg::tokpos, vlex::yylval.ival);
                break;
            default:
                printf("%10s %4d\n",tokname(tok).data(), errormsg::tokpos);
        }
    }

    delete vlex::lexer;
    return 0;
}


