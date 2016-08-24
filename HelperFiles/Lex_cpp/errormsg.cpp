/*
 * errormsg.cpp - functions used in all phases of the compiler to give
 *              error messages about the Tiger program.
 *
 */
#include "errormsg.h"

using namespace util;
using namespace std;

namespace errormsg
{
    bool anyErrors=false;
    int EM_tokPos=0;
    extern FILE *yyin;
    static char *fileName=nullptr;
    static int lineNum =1;
    static SP_IntList linePos();
    
    SP_IntList get_intList(int i, SP_IntList rest)
    {
        SP_IntList l(new IntList());
        l->i=i;
        l->rest=rest;
        return l;
    }
    
    void EM_newline()
    {
        lineNum++;
        linePos=get_intList(EM_tokPos, linePos);
    }
    
    void EM_reset(string fname)
    {
        anyErrors=false;
        fileName=fname.c_str();
        lineNum=1;
        linePos=get_intList(0, SP_IntList());
        yyin=fopen(fname, "r");
        if(!yyin)
        {
            EM_error(0, "cannot open");
            throw runtime_error("");
        }
        
    }
    
    void EM_error(int pos, string message, initializer_list<string> ap)
    {
        SP_IntList lines=linePos;
        int num=lineNum;
        anyErrors=true;
        while(lines && lines->i >= pos)
        {
            lines=lines->rest;
            num--;
        }
        if(fileName)
            cerr<<fileName;
        if(lines)
            cerr<<num<<pos-lines->i;
        for(const auto &s: ap)
            cerr<<s;
        cerr<<endl;
    }
    
}
