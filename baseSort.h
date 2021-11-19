//
// Created by KKKZOZ on 2021/11/18.
//

#ifndef SORTUTILITY_BASESORT_H
#define SORTUTILITY_BASESORT_H
#include <algorithm>
#define MAXLENGTH 1000001
template <typename E>
class baseSort {
public:
    E result[MAXLENGTH];
	void prepare(E* array, int size)
	{
		memset(result, 0, size * sizeof(E));
		memcpy(result, array + 1, size * sizeof(E));
	}
    virtual void sort(int size) = 0;
    virtual std::string getName() = 0;
	E* getResult()
	{
		return baseSort<E>::result;
	}
};

#endif //SORTUTILITY_BASESORT_H
