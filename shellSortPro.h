#pragma once

#ifndef SORTUTILITY_SHELLSORTPRO_H
#define SORTUTILITY_SHELLSORTPRO_H
#include "baseSort.h"
template <typename E>
class shellSortPro : public baseSort<E> {
public:
    shellSortPro() {}
    ~shellSortPro() {}
    void sort(int size)
    {
        //int gap = length(a)/2 ;
        int gap = 1;
        while (gap < length(a) / 3) {
            gap = 3 * gap + 1;  // 1 , 4 , 13 , 40 , 121 , 364 , 1093...
        }
        int temp = 0;
        int ex = 0;
        for (int i = length(a); i > 0; i--) {
            if (a[i] < a[i - 1])
            {
                temp = a[i];
                a[i] = a[i - 1];
                a[i - 1] = temp;
                ex++;
            }

        }
        if (ex == 0)
        {
            return;
        }

        do {
            int temp = 0;
            for (int i = gap; i <= length(a); i++) {
                for (int j = i; j >= gap; j -= gap) {
                    if (a[j - gap] > a[j]) {
                        temp = a[j - gap];
                        a[j - gap] = a[j];
                        a[j] = temp;
                    }
                }
            } 
            gap /= 3;
        } while (gap != 0); 
    }


    std::string getName() {
        return "shellSortPro";
    }



};



#endif //SORTUTILITY_SHELLSORTPRO_H
