#include <iostream>
using namespace std;

int main(void)
{
	int n,a;
	int aCnt = 0;//a번째 사람 구하기위해 피료한 변수
	int cnt = 0;//현재 주소
	cin >> n;
	cin >> a;
	int* arr = new int[n];
	//1은 사람 있음 0은 죽음
	for (int i = 0; i < n; i++)
	{
		arr[i] = 1;
	}
	cout << "<";
	//전체루프
	for (int i = 0; i<n; i++)
	{
		//죽은 사람은 건너뛰기 루프
		for(int j=cnt; ; j++)
		{
			//여기 사람 안 쥬금
			if (arr[j%n] == 1)
			{
				
				aCnt++;
			}
			if (aCnt == a)//종료조건
			{
				arr[j%n] = 0;
				cnt = j % n;
				aCnt = 0;
				if(i == n-1)
					cout << j % n + 1;
				else
					cout << j % n + 1<<", ";
			
				break;
			}
		}
	}
	cout << ">";
	delete[] arr;
}