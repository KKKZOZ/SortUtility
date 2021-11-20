#pragma once
#ifndef SORTUTILITY_HEAPSORT_H
#define SORTUTILITY_HEAPSORT_H
#include "baseSort.h"
#include <utility>

template <typename E>
class heapSort : public baseSort<E> {
public:
	heapSort() {}
	~heapSort(){}
	void sort(int size)
	{
		buildMaxHeap(baseSort<E>::result, size);  //�Ƚ�����

		for (int i = size - 1; i > 0; i--)

		{
			// �����ڵ�(���ֵ)����������򲿷ֵ����һ��Ԫ�ؽ���,�������յõ����ǵ�������
			//std::swap(baseSort<E>::result[0], baseSort<E>::result[i]);
			E temp=baseSort<E>::result[i];
			baseSort<E>::result[i] = baseSort<E>::result[0];
			baseSort<E>::result[0] = temp;
			// ���������鳤�ȼ�һ,ֻҪ�Ի������ڵ��Ԫ�ؽ������򣬽����³��ͺ��ˡ�
			maxHeapIfy(baseSort<E>::result, 0, i);
		}
	}
	std::string getName() {
		return "heapSort";
	}
private:
	void buildMaxHeap(E A[], int n)  //��������

	{
		// �����һ����Ҷ�ӽڵ㣨n/2-1����ʼ�Ե����Ϲ�����
		for (int i = n / 2 - 1; i >= 0; i--)  //�ӣ�n/2-1������һ��maxHeapIfy�Ϳ��Եõ�����
			maxHeapIfy(A, i, n);
	}
	void maxHeapIfy(E A[], int i, int n)  //��i�ڵ�Ϊ���Ķ���С������������,n��ʾ���е����ݸ���

	{
		int l = 2 * i + 1;   //i�������
		int r = 2 * i + 2;  //i���Ҷ���
		int largest = i;   //�����ø��ڵ���ӽڵ������ڵ������ֵ��λ��Ϊ���ڵ��±�
		if (l < n && A[l] > A[largest])
			largest = l;
		if (r < n && A[r] > A[largest])
			largest = r;
		if (largest != i)    //���ֵ���Ǹ��ڵ㣬����
		{
			//swap(A[i], A[largest]);
			E temp = A[largest];
			A[largest] = A[i];
			A[i] = temp;
			maxHeapIfy(A, largest, n);  //�ݹ���ã���֤����Ҳ������
		}
	}

};

#endif