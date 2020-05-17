#include <iostream>
using namespace std;

int main(void)
{
	long long n;
	int mResult, m, temp=0,tempM=0;//나무 수, 가져가려 하는 나무 길이
	int* nArr;
	int allLen = 0;
	int l, r;//왼쪽 오른쪽;
	int Max,a;
	
	cin >> n >> mResult;
	nArr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin>>nArr[i];
	}

	Max = nArr[0];
	for (int i = 0; i < n-1; i++)
	{
		if (Max < nArr[i + 1])
		{
			Max = nArr[i + 1];
			
		}
	}
	l = 0;
	r = Max;

	
	while (1)
	{
		m = (l + r) / 2;
		temp = 0;
		
		//톱날 넣어서 조건 만족하는지
		for (int i = 0; i < n; i++)
		{
			a = nArr[i] - m;
			if (a < 0)
				a = 0;
			temp += a;
			
		}
		if (temp == mResult)
		{
			cout << m;
			break;
		}
		else if (temp > mResult)
		{
			l = m;
			continue;
		}
		else if (temp < mResult)
		{
			r = m;
			continue;
		}
		if(l)
	}
}