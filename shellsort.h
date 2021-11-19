//
// Created by Zhw on 2021/11/18.
//

#ifndef SORTUTILITY_SHELLSORT_H
#define SORTUTILITY_SHELLSORT_H
#include "baseSort.h"
template <typename E>
class shellsort : public baseSort<E> {
public:
    shellsort() {}
    ~shellsort() {}
    E result[MAXLENGTH];
    int size = 0;
    void sort(int size)
    {
       
    }
    std::string getName() {
        return "shellSort";
    }
    //E* result=


};



#endif //SORTUTILITY_SHELLSORT_H
