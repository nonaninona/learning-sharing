#include <stdio.h>
#include <stdlib.h>
#define max 10

void QuickSort(int A[], int start, int end) //재귀함수를 이용함
{
	int index;
	int i;
	if (start < end) //end가 start보다 큰 경우
	{
		printf("\n");
		for (i = 0; i < max; i++)
			printf("%d ", A[i]);
		printf("\n");
		index = Partition(A,start,end); 
		QuickSort(A, start, index - 1); 
		QuickSort(A, index + 1,end);
	}
	else
	{
		return ;
	}
}

int Partition(int A[], int start, int end) //pivot 왼쪽 오른쪽으로 나누는 함수
{
	int pivot = A[end];
	int i;
	int index = start; //index는 pivot보다 작은 것은 왼쪽에다가 넣기 위해 위치를 기억하는 정수
	int temp; //swap을 위한 변수
	for (i = start; i < end; i++)
	{
		if (A[i] <= pivot) //pivot보다 작은 놈이 있다면
		{
			printf("\n Swap됨!! %d %d", A[i], A[index]);
			temp = A[i];
			A[i] = A[index];
			A[index] = temp;
			index++; //index 증가
		}
	}
	//pivot을 옮겨준다. 밑 과정을 거치면 pivot을 기준으로 왼쪽은 pivot보다 모두 작은 수가 되고, 오른쪽은 pivot보다 모두 큰 수가 된다.
	printf("\n Swap됨!! %d %d", A[index], A[end]);
	temp = A[index];
	A[index] = A[end];
	A[end] = temp;
	return index;
}

int main()
{
	int A[max] = {40, 30, 100, 60, 70, 80, 90, 10, 20, 50};
	int i;

	printf("\n정렬하기 전\n");
	for (i = 0; i < max; i++)
	{
		printf("%d ", A[i]);
	}
	QuickSort(A, 0, max - 1);
	printf("\n\n정렬한 후\n");
	for (i = 0; i < max; i++)
	{
		printf("%d ", A[i]);
	}
}