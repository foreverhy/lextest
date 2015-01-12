#ifndef VLEX_UTILS_H
#define VLEX_UTILS_H 1

#include <cassert>
#include <string>


//void *checked_malloc(int);
//std::string String(char *);
namespace vlex{

struct U_boolList{
    bool head_;
    U_boolList  *tail_;
    U_boolList(bool head, U_boolList *tail = nullptr):head_(head), tail_(tail){
    }
};

}// namespace vlex


#endif
