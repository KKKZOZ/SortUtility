#pragma once
#ifndef SORTUTILITY_TESTSORT_H
#define SORTUTILITY_TESTSORT_H
#include "baseSort.h"

template <typename E>
class testSort : public baseSort<E> {
public:
	testSort() {}
	~testSort() {}
	void sort(int size)
	{
		std::cout << "Sorting..." << std::endl;
		for (int i = 0; i <= size-1; i++) {
			std::cout << baseSort<E>::result[i] << std::endl;
		}
	}
	std::string getName()
	{
		return "testSort";
	}
	
};


#endif