//#include <iostream>
//
////���� ������ �̿��Ͽ� �����غ� ����
//using namespace std;
//
//int main()
//{
//	int input,temp2;
//	cin >> input;
//	int k[10]{ -1 };
//	int i = 0;
//	int j = 0;
//	int temp = 10000;
//	temp2 = input;
//	while (temp2 != 0) //�� �ڸ��� ����
//	{
//		temp = temp2 % 10;
//		temp2 = temp2 / 10;
//		k[i] = temp; //���� ����
//		i++;
//	}
//	j = i - 1;
//	
//	for (int i = 0; i < j; i++) //���� ���� ����
//	{
//		for (int z = i+1; z <= j; z++)
//		{
//			if (k[i] < k[z]) //�ڿ� ���� ���� �ͺ��� ũ�� ��ȯ�ؾ���
//			{
//				temp = k[i];
//				k[i] = k[z];
//				k[z] = temp;
//			}
//		}
//	}
//
//	for (int i = 0; i <= j; i++) //���
//		cout << k[i];
//}