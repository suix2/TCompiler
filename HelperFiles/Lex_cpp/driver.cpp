#include "util.h"
#include "errormsg.h"
#include "tokens.h"

using namespace std;
using namespace util;
using namespace errormsg;

YYSTYPE yylval;

int yylex(void); /* prototype for the lexing function */

string toknames[] = {
"ID", "STRING", "INT", "COMMA", "COLON", "SEMICOLON", "LPAREN",
"RPAREN", "LBRACK", "RBRACK", "LBRACE", "RBRACE", "DOT", "PLUS",
"MINUS", "TIMES", "DIVIDE", "EQ", "NEQ", "LT", "LE", "GT", "GE",
"AND", "OR", "ASSIGN", "ARRAY", "IF", "CONTINUE", "ELSE", "WHILE", "FOR",
"RETURN", "CHAR", "SIZEOF", "TYPEDEF", "STRUCT", "SWITCH", "CASE", "BREAK",
"DEFAULT", "DEFINE", "INCLUDE", "NOT"
};


string tokname(tok) {
    return tok<257 || tok>300 ? "BAD_TOKEN" : toknames[tok-257];
}

int main(int argc, char **argv) {
    string fname;
    int tok;
    if(argc!=2)
    {
        cerr<<"usage: a.out filename"<<endl;
        return 1;
    }
    fname=argv[1];
    EM_reset(fname);
    for(;;)
    {
        tok=yylex();
        if (tok==0) break;
        switch(tok) {
            case ID: case STRING:
            cout<<tokname(tok)<<"\t"<<EM_tokPos<<"\t"<<yylval.sval<<endl;
            break;
            case INT:
            cout<<tokname(tok)<<"\t"<<EM_tokPos<<"\t"<<yylval.ival<<endl;
            break;
            case CHAR:
            cout<<tokname(tok)<<"\t"<<EM_tokPos<<"\t"<<yylval.cval<<endl;
            default:
            cout<<tokname(tok)<<"\t"<<EM_tokPos;
        }
    }
    return 0;
}


