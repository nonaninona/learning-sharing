/*#include <iostream>
using namespace std;


int main(void)
{
	int n;
	cin >> n;
	int Q = n; //�� ����
	int result = 0;
	int** arr = new int*[n];//2���� �迭
	int* Qarr = new int[n]; //�� �迭
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
	}

	for (int i = 0; i < n; i++)      //0���� �ʱ�ȭ
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = 0;
		}
	}

	

	for (int i = 0; i < n; i++)//�޸� ����
	{
		delete[] arr[i];
	}
	delete[] arr;
}*/
#include <iostream>
#include <math.h>
using namespace std;

int queen[16]; //�� ���� ���� ����
int N;
int cnt;

void backtrack(int x);

void main()
{
	int i, j;

	cin >> N;

	for (i = 0; i < N; i++) //0��° �ٿ� �ϳ��� ���� ���ƺ���
	{
		queen[0] = i;
		backtrack(0);
	}
	cout<< cnt << endl;
}

void backtrack(int x) //�Ķ���ʹ� ���� ���� ��ǥ
{
	int i, j;

	//���ڸ��� ���� ���� �� �ִ°�?
	for (i = 0; i < x; i++)
	{
		if ((queen[i] == queen[x]) || (abs(queen[i] - queen[x]) == abs(i - x)))
		{
			return;
		}
	}

	if (x == N - 1) 
	{

		cnt++; //���� �� ���� ���

		return;

	}

	for (i = 0; i < N; i++) //x+1��° �ٿ� �ϳ��� ���� ���ƺ���
	{
		queen[x + 1] = i;
		backtrack(x + 1);
	}
}
