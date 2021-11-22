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
		
	}
	std::string getName()
	{
		return "txzzxzSort";
	}
	
};


#endif