#include <iostream>

using namespace std;

int main()
{
	int N, K, temp1, temp2;
	int count = 0;
	int* a = nullptr;
	cin >> N >> K;
	a = new int[N];
	for (size_t i = 0; i < N; i++)
		cin >> a[i];
	temp2 = K;
	for (int i = N - 1; i >= 0; i--)
	{
		if (a[i] > K) //������ ���� ���� ���� 0�� ���
			continue;
		temp1 = temp2 / a[i];
		temp2 = temp2 % a[i]; //������ �� ����
		count = count + temp1;
	}
	cout << count;
	delete[] a;
}