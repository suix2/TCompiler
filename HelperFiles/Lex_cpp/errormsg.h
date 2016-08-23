#include <iostream>
#include "util.h"

namespace errormsg
{
    extern bool EM_anyErrors;

    void EM_newline(void);

    extern int EM_tokPos;

    void EM_error(int, string,...);
    void EM_impossible(string,...);
    void EM_reset(string filename);
    
    class IntList
    {
        private:
            int i;
            std::shared_ptr<IntList> rest;
            IntList(){};
        
        public:
            std::shared_ptr<IntList> get_intList
                (int i, std::shared_ptr<IntList> rest);
            
            
    }
    
}
