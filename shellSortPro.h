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
        while (gap < size / 4) {
            gap = 4 * gap + 1;  // 1 , 4 , 13 , 40 , 121 , 364 , 1093...
        }
        E temp;
        int ex = 0;
        for (int i = size - 1; i > 0; i--) {
            if (baseSort<E>::result[i] < baseSort<E>::result[i - 1])
            {
                temp = baseSort<E>::result[i];
                baseSort<E>::result[i] = baseSort<E>::result[i - 1];
                baseSort<E>::result[i - 1] = temp;
                ex++;
            }

        }
        if (ex == 0)
        {
            return;
        }

        do {
            E temp;
            for (int i = gap; i < size; i++) {
                for (int j = i; j >= gap; j -= gap) {
                    if (baseSort<E>::result[j - gap] > baseSort<E>::result[j]) {
                        temp = baseSort<E>::result[j - gap];
                        baseSort<E>::result[j - gap] = baseSort<E>::result[j];
                        baseSort<E>::result[j] = temp;
                    }
                }
            }
            gap /= 4;
        } while (gap != 0);
    }


    std::string getName() {
        return "shellSortPro";
    }



};



#endif //SORTUTILITY_SHELLSORTPRO_H
