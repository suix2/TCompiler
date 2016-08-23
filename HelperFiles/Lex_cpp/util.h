#ifndef UTIL_H
namespace util
{
    using SP_U_BoolList=std::shared_ptr<U_BoolList>;

    class U_BoolList
    {
        private:
            U_BoolList(){};
        
        public:
            bool head;
            SP_U_BoolList tail;
            SP_U_BoolList get_U_BoolList(bool head, SP_U_BoolList tail);
    }
}

#define UTIL_H
