//#include <iostream>
//
////선택 정렬을 이용하여 정렬해볼 것임
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
//	while (temp2 != 0) //각 자리수 추출
//	{
//		temp = temp2 % 10;
//		temp2 = temp2 / 10;
//		k[i] = temp; //원소 삽입
//		i++;
//	}
//	j = i - 1;
//	
//	for (int i = 0; i < j; i++) //선택 정렬 조져
//	{
//		for (int z = i+1; z <= j; z++)
//		{
//			if (k[i] < k[z]) //뒤에 것이 앞의 것보다 크면 교환해야지
//			{
//				temp = k[i];
//				k[i] = k[z];
//				k[z] = temp;
//			}
//		}
//	}
//
//	for (int i = 0; i <= j; i++) //출력
//		cout << k[i];
//}