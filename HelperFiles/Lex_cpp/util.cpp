/*
 * util.cpp - commonly used utility functions.
 */

#include <iostream>
#include "util.h"

// this line is used to test comment
/* this line is also used to test comment*/

namespace util
{
    SP_U_BoolList get_U_BoolList(bool head, SP_U_BoolList tail)
    {
        SP_U_BoolList list(new U_BoolList());
        list->head=head;
        list->tail=tail;
        return list;
    }
    
}
