#pragma once
#ifndef SORTUTILITY_BINSORT_H
#define SORTUTILITY_BINSORT_H
#include "baseSort.h"
template <typename E>
class binSort : public baseSort<E> {
public:
	E bin[MAXLENGTH];
	E maxNumber = -1;
	int k = 0;
	binSort() {
		memset(bin, 0, sizeof(bin));
	}
	~binSort() {}
	void sort(int size)
	{
		for (int i = 0; i <= size-1; i++)
		{
			if (maxNumber < baseSort<E>::result[i])
			{
				maxNumber = baseSort<E>::result[i];
			}
			bin[baseSort<E>::result[i]]++;
		}
		for (int i = 0; i <= maxNumber; i++)
		{
			while (bin[i] > 0)
			{
				baseSort<E>::result[k] = i;
				k++;
				bin[i]--;
			}
		}
	}
	std::string getName()
	{
		return "binSort";
	}
};


#endif