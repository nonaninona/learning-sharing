#include <iostream>
#include <cstdio>

using namespace std;

int arr[100000] = { 0, };
int sum[100000] = { 0, };
int sum2[100000] = { 0, };

int main()
{
	int i, j;
	int N, M; //N�� ���� ����, M�� ���� ���ؾ� �ϴ� Ƚ��
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) //�迭�� �Է¹ޱ�
		scanf("%d", &arr[i]);

	for (int i = 0; i < N; i++)
	{
		if (i == 0) {
			sum[i] = arr[i];
			continue;
		}
		sum[i] = sum[i-1] + arr[i];
	}

	for (int k = 0; k < M; k++) //i, j ���� �ֱ�
	{
		scanf("%d %d",&i,&j);
		if (i == 1) //������ ù��° ���� 1�� ���
		{
			sum2[k] = sum[j - 1];
		}
		else //������ ù��° ���� 1�� �ƴ� ���
		{
			sum2[k] = sum[j - 1] - sum[i - 2];
		}
	}
	
	for (int i = 0; i < M; i++) //���� �� ���ϱ�
	{
		printf("%d\n", sum2[i]);
	}
}