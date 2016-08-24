#ifndef ERRORMSG_H

#include <cstdlib>
#include <stdexcept>
#include "util.h"

namespace errormsg
{
    extern bool EM_anyErrors;

    void EM_newline(void);

    extern int EM_tokPos;

    void EM_error(int, std::string, std::initializer_list<std::string>);
    //void EM_impossible(string,...);
    void EM_reset(std::string filename);
    
    class IntList
    {
        using SP_IntList=std::shared_ptr<IntList>;
        friend SP_IntList get_intList (int i, SP_IntList rest);
        
        private:
            IntList(){}
        
        public:
            int i;
            SP_IntList rest;
    };
    
    using SP_IntList=std::shared_ptr<IntList>;
    
    SP_IntList get_intList(int i, SP_IntList rest);
    
}

#define ERRORMSG_H
#endif
