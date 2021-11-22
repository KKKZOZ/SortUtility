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
        
        int count[10]; //������
        int radix = 1;
        int k;
        for (int i = 1; i <= d; i++) //����d������
        {
            for (int j = 0; j < 10; j++)
                count[j] = 0; //ÿ�η���ǰ��ռ�����
            for (int j = 0; j < size; j++)
            {
                k = (baseSort<E>::result[j] / radix) % 10; //ͳ��ÿ��Ͱ�еļ�¼��
                count[k]++;
            }
            for (int j = 1; j < 10; j++)
                count[j] = count[j - 1] + count[j]; //��tmp�е�λ�����η����ÿ��Ͱ
            for (int j = size - 1; j >= 0; j--) //������Ͱ�м�¼�����ռ���tmp��
            {
                k = (baseSort<E>::result[j] / radix) % 10;
                tmp[count[k] - 1] = baseSort<E>::result[j];
                count[k]--;
            }
            for (int j = 0; j < size; j++) //����ʱ��������ݸ��Ƶ�data��
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
        int d = 1; //��������λ��
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