#include <stdio.h>
#include <stdlib.h>
#define max 10

void QuickSort(int A[], int start, int end) //����Լ��� �̿���
{
	int index;
	int i;
	if (start < end) //end�� start���� ū ���
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

int Partition(int A[], int start, int end) //pivot ���� ���������� ������ �Լ�
{
	int pivot = A[end];
	int i;
	int index = start; //index�� pivot���� ���� ���� ���ʿ��ٰ� �ֱ� ���� ��ġ�� ����ϴ� ����
	int temp; //swap�� ���� ����
	for (i = start; i < end; i++)
	{
		if (A[i] <= pivot) //pivot���� ���� ���� �ִٸ�
		{
			printf("\n Swap��!! %d %d", A[i], A[index]);
			temp = A[i];
			A[i] = A[index];
			A[index] = temp;
			index++; //index ����
		}
	}
	//pivot�� �Ű��ش�. �� ������ ��ġ�� pivot�� �������� ������ pivot���� ��� ���� ���� �ǰ�, �������� pivot���� ��� ū ���� �ȴ�.
	printf("\n Swap��!! %d %d", A[index], A[end]);
	temp = A[index];
	A[index] = A[end];
	A[end] = temp;
	return index;
}

int main()
{
	int A[max] = {40, 30, 100, 60, 70, 80, 90, 10, 20, 50};
	int i;

	printf("\n�����ϱ� ��\n");
	for (i = 0; i < max; i++)
	{
		printf("%d ", A[i]);
	}
	QuickSort(A, 0, max - 1);
	printf("\n\n������ ��\n");
	for (i = 0; i < max; i++)
	{
		printf("%d ", A[i]);
	}
}