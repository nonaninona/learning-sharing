#include <iostream>
using namespace std;

int main(void)
{
	int n,a;
	int aCnt = 0;//a��° ��� ���ϱ����� �Ƿ��� ����
	int cnt = 0;//���� �ּ�
	cin >> n;
	cin >> a;
	int* arr = new int[n];
	//1�� ��� ���� 0�� ����
	for (int i = 0; i < n; i++)
	{
		arr[i] = 1;
	}
	cout << "<";
	//��ü����
	for (int i = 0; i<n; i++)
	{
		//���� ����� �ǳʶٱ� ����
		for(int j=cnt; ; j++)
		{
			//���� ��� �� ���
			if (arr[j%n] == 1)
			{
				
				aCnt++;
			}
			if (aCnt == a)//��������
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