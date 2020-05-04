#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	int num, temp;//만약에 4000이야 10으로 나눠
	int size = 0;
	int arr[10];

	cin >> num;
	for (int i = 0; i < 10; i++)
	{
		if (num == 0)
			break;
		arr[i] = num % 10;
		num /= 10;
		size++;
	}
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i; j < size - 1; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		cout<<arr[i];
	}
}