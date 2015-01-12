%{
#include <string.h>
#include "util.h"
#include "tokens.h"
#include "errormsg.h"

using vlex::errormsg;
using vlex::yylval;


int charpos=1;

/*int yywrap(){*/
    /*charpos=1;*/
    /*return 1;*/
/*}*/


void adjust(){
    errormsg::tokpos = charpos; 
    charpos += vlex::lexer->YYLeng();
}

%}

%option noyywrap

%%
" "	 {adjust(); continue;}
\n	 {adjust(); errormsg::newline(); continue;}
","	 {adjust(); return vlex::COMMA;}
for  	 {adjust(); return vlex::FOR;}
[0-9]+	 {adjust(); yylval.ival = std::atoi(yytext); return vlex::INT;}
.	 {adjust(); errormsg::error(errormsg::tokpos,"illegal token");}


