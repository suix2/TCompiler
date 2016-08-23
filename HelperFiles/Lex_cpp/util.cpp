/*
 * util.cpp - commonly used utility functions.
 */

#include <iostream>
#include "util.h"

// this line is used to test comment
/* this line is also used to test comment*/

U_boolList U_BoolList(bool head, U_boolList tail)
{ U_boolList list = checked_malloc(sizeof(*list));
  list->head = head;
  list->tail = tail;
  return list;
}
