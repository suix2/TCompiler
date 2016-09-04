%{
#include <string>
#include <FlexLexer.h>
#include "util.h"
#include "tokens.h"
#include "errormsg.h"

int charPos=1;

int yyFlexLexer::yywrap(void)
{
    charPos=1;
    return 1;
}


void yyFlexLexer::adjust(void)
{
    errormsg::EM_tokPos=charPos;
    charPos+=yyleng;
}

%}

%%
" "         {adjust(); continue;}
\n          ;
\/\/.*      {adjust(); continue;}
"/*"((\*+[^/*])|([^*]))*\**"*/"  {adjust(); continue;}
\"((\\\")*[^\"]*)*\"      {adjust(); *yylval.sval=std::string(yytext); return STRING;}
[0-9]+	    {adjust(); yylval.ival=std::stoi(yytext); return INT;}
","         {adjust(); return COMMA;}
":"         {adjust(); return COLON;}
";"         {adjust(); errormsg::EM_newline(); return SEMICOLON;}
"("         {adjust(); return LPAREN;}
")"         {adjust(); return RPAREN;}
"["         {adjust(); return LBRACK;}
"]"         {adjust(); return RBRACK;}
"{"         {adjust(); return LBRACE;}
"}"         {adjust(); return RBRACE;}
"."         {adjust(); return DOT;}
"+"         {adjust(); return PLUS;}
"-"         {adjust(); return MINUS;}
"*"         {adjust(); return TIMES;}
"/"         {adjust(); return DIVIDE;}
"=="        {adjust(); return EQ;}
"!="        {adjust(); return NEQ;}
"<"         {adjust(); return LT;}
"<="        {adjust(); return LE;}
">"         {adjust(); return GT;}
">="        {adjust(); return GE;}
"&&"        {adjust(); return AND;}
"||"        {adjust(); return OR;}
"="         {adjust(); return ASSIGN;}
\[[1-9]+[0-9]*\] {adjust(); yylval.ival=std::stoi(yytext+1); return ARRAY;}
"if"        {adjust(); return IF;}
"continue"  {adjust(); return CONTINUE;}
"else"      {adjust(); return ELSE;}
"while"     {adjust(); return WHILE;}
"for"  	    {adjust(); return FOR;}
"return"    {adjust(); return RETURN;}
"'.'"       {adjust(); yylval.cval=yytext[1]; return CHAR;}
"sizeof"    {adjust(); return SIZEOF;}
"typedef"   {adjust(); return TYPEDEF;}
"struct"    {adjust(); return STRUCT;}
"switch"    {adjust(); return SWITCH;}
"case"      {adjust(); return CASE;}
"break"     {adjust(); return BREAK;}
"default"   {adjust(); return DEFAULT;}
"#define"   {adjust(); return DEFINE;}
"#include"  {adjust(); return INCLUDE;}
"!"         {adjust(); return NOT;}
[a-zA-Z_][a-zA-Z0-9_]*    {adjust(); *yylval.sval=std::string(yytext); return ID;}

.	        {adjust(); errormsg::EM_error(errormsg::EM_tokPos,{"illegal token"});}
%%