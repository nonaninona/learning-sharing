#include <iostream>

using namespace std;

//일곱난쟁이 키의 합이 100cm

/*20
7
23
19
10
15
25
8
13*/


int main(void)s
{
	int nanjang[9];
	int realnanjang[7];
	int no1=0, no2=0;
	int sum = 0, temp=0;
	int idx = 0;

	for (int i = 0; i < 9; i++)
	{
		cin >> nanjang[i];
	}

	//뺄거 두개 고르기
	for (int i1 = 0; i1 < 9; i1++)
	{
		for (int i2 = 0; i2 < 9; i2++)
		{
			if (i1 == i2)
				continue;

			no1 = nanjang[i1];
			no2 = nanjang[i2];
			for (int j = 0; j < 9; j++)
			{
				if (nanjang[j] != no1 && nanjang[j] != no2)
				{
					realnanjang[idx] = nanjang[j];
					sum += realnanjang[idx++];
				}
			}
			idx = 0;
				//정렬
				if (sum == 100)
				{
					for (int k = 0; k < 6; k++)//정렬
					{
						for (int l = 0; l < 6; l++)//횟수 맞는지 화긴해********
						{
							if (realnanjang[l + 1] < realnanjang[l])
							{
								temp = realnanjang[l];
								realnanjang[l] = realnanjang[l + 1];
								realnanjang[l + 1] = temp;
							}
						}
					}
					for (int i = 0; i < 7; i++)
					{
						cout << realnanjang[i] << endl;
					}
					return 0;
				}

				sum = 0;
		}
	}
}