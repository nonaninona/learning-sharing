#include <iostream>
#include <algorithm>
using namespace std;

int dpArr[1000001];//n번째 숫자를 1로만드는데 걸리는 최소 횟수

int dp(int n)
{
	if (n == 1) return 0; 
	if (dpArr[n] != -1) return dpArr[n];

	int result = dp(n - 1) + 1;
	if (n % 3 == 0) result = min(result, dp(n / 3)+1); 
	if (n % 2 == 0) result = min(result, dp(n / 2)+1); 
	dpArr[n] = result;
	return result;
}

int main(void)
{
	int n;//연산할 거
	cin >> n;
	fill(dpArr, dpArr + 1000001, -1);
	cout << dp(n);
	
}