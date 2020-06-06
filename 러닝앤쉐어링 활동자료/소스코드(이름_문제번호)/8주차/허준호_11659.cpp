#include <iostream>
#include <cstdio>

using namespace std;

int arr[100000] = { 0, };
int sum[100000] = { 0, };
int sum2[100000] = { 0, };

int main()
{
	int i, j;
	int N, M; //N은 수의 개수, M은 합을 구해야 하는 횟수
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) //배열에 입력받기
		scanf("%d", &arr[i]);

	for (int i = 0; i < N; i++)
	{
		if (i == 0) {
			sum[i] = arr[i];
			continue;
		}
		sum[i] = sum[i-1] + arr[i];
	}

	for (int k = 0; k < M; k++) //i, j 각각 넣기
	{
		scanf("%d %d",&i,&j);
		if (i == 1) //구간의 첫번째 값이 1인 경우
		{
			sum2[k] = sum[j - 1];
		}
		else //구간의 첫번째 값이 1이 아닌 경우
		{
			sum2[k] = sum[j - 1] - sum[i - 2];
		}
	}
	
	for (int i = 0; i < M; i++) //구간 합 구하기
	{
		printf("%d\n", sum2[i]);
	}
}