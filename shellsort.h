//
// Created by Zhw on 2021/11/18.
//

#ifndef SORTUTILITY_SHELLSORT_H
#define SORTUTILITY_SHELLSORT_H
#include "baseSort.h"
template <typename E>
class shellSort : public baseSort<E> {
public:
    shellSort() {}
    ~shellSort() {}
    void sort(int size)
    {

        int gap = size / 2;

        do {
            int temp = 0;
            for (int i = gap; i < size; i++) {
                for (int j = i; j >= gap; j -= gap) {
                    if (baseSort<E>::result[j - gap] > baseSort<E>::result[j]) {
                        temp = baseSort<E>::result[j - gap];
                        baseSort<E>::result[j - gap] = baseSort<E>::result[j];
                        baseSort<E>::result[j] = temp;

                    }
                }
            }
            gap /= 2;
        } while (gap != 0);
    }


    std::string getName() {
        return "shellSort";
    }
    //E* result=


};



#endif //SORTUTILITY_SHELLSORT_H
