#ifndef UTIL_H

#include <iostream>
#include <memory>

namespace util
{
    class U_BoolList
    {
        using SP_U_BoolList=std::shared_ptr<U_BoolList>;
        friend SP_U_BoolList get_U_BoolList(bool head, SP_U_BoolList tail);
        
        private:
            U_BoolList(){}
        
        public:
            bool head;
            SP_U_BoolList tail;
            SP_U_BoolList get_U_BoolList(bool head, SP_U_BoolList tail);
    };
    
    using SP_U_BoolList=std::shared_ptr<U_BoolList>;
    
    SP_U_BoolList get_U_BoolList(bool head, SP_U_BoolList tail);
    
}

#define UTIL_H
#endif
