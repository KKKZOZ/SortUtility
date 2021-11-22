#pragma once
#ifndef SORTUTILITY_RADIXSORTDEC_H
#define SORTUTILITY_RADIXSORTDEC_H
#include "baseSort.h"

template <typename E>
class radixSortDec :public baseSort<E> {
public:
    int tmp[MAXLENGTH];
	radixSortDec() {}
	~radixSortDec() {}
	void sort(int size)
	{
        
        int d = maxbit(size);
        
        int count[10]; //计数器
        int radix = 1;
        int k;
        for (int i = 1; i <= d; i++) //进行d次排序
        {
            for (int j = 0; j < 10; j++)
                count[j] = 0; //每次分配前清空计数器
            for (int j = 0; j < size; j++)
            {
                k = (baseSort<E>::result[j] / radix) % 10; //统计每个桶中的记录数
                count[k]++;
            }
            for (int j = 1; j < 10; j++)
                count[j] = count[j - 1] + count[j]; //将tmp中的位置依次分配给每个桶
            for (int j = size - 1; j >= 0; j--) //将所有桶中记录依次收集到tmp中
            {
                k = (baseSort<E>::result[j] / radix) % 10;
                tmp[count[k] - 1] = baseSort<E>::result[j];
                count[k]--;
            }
            for (int j = 0; j < size; j++) //将临时数组的内容复制到data中
                baseSort<E>::result[j] = tmp[j];
            radix = radix * 10;
        }
	}

	std::string getName()
	{
		return "radixSortDec";
	}

private:
    int maxbit(int size)
    {
        int d = 1; //保存最大的位数
        int p = 10;
        for (int i = 0; i < size; ++i)
        {
            while (baseSort<E>::result[i] >= (E)p)
            {
                p *= 10;
                ++d;
            }
        }
        return d;
    }

};


#endif