/*#include <iostream>
using namespace std;


int main(void)
{
	int n;
	cin >> n;
	int Q = n; //퀸 개수
	int result = 0;
	int** arr = new int*[n];//2차원 배열
	int* Qarr = new int[n]; //퀸 배열
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
	}

	for (int i = 0; i < n; i++)      //0으로 초기화
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = 0;
		}
	}

	

	for (int i = 0; i < n; i++)//메모리 해제
	{
		delete[] arr[i];
	}
	delete[] arr;
}*/
#include <iostream>
#include <math.h>
using namespace std;

int queen[16]; //각 줄의 퀸을 저장
int N;
int cnt;

void backtrack(int x);

void main()
{
	int i, j;

	cin >> N;

	for (i = 0; i < N; i++) //0번째 줄에 하나씩 퀸을 놓아본다
	{
		queen[0] = i;
		backtrack(0);
	}
	cout<< cnt << endl;
}

void backtrack(int x) //파라매터는 퀸을 놓을 좌표
{
	int i, j;

	//이자리에 퀸을 놓을 수 있는가?
	for (i = 0; i < x; i++)
	{
		if ((queen[i] == queen[x]) || (abs(queen[i] - queen[x]) == abs(i - x)))
		{
			return;
		}
	}

	if (x == N - 1) 
	{

		cnt++; //퀸을 다 놓은 경우

		return;

	}

	for (i = 0; i < N; i++) //x+1번째 줄에 하나씩 퀸을 놓아본다
	{
		queen[x + 1] = i;
		backtrack(x + 1);
	}
}
