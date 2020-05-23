#include <iostream>

using namespace std;

void save(int* now, int* result, int N, int K)
{
	int count = 0, i = 0, j = 0;
	while (j <= N-1) //result�� index���� ��ȿ�� ������ ����
	{
		count = 0; //���ڸ� ���� �� �׻� 0���� �ʱ�ȭ
		while (count < K)
		{
			if (i > N - 1) //now �迭���� ��ȿ index�� �ʰ��� ���
			{
				i = 0; //ó������ ���ư���
			}

			if (now[i] == 0)//�ش� ĭ�� �̹� ���� ���� ���
			{ 
				i++; //�ε����� ����
				continue;
			}

			else //���� �� ���� ��쿡��
			{
				count++; //count ����
				i++; //now �ε��� ����
			}
		}

		//�� while���� �� ��� ������ ĭ�� ������ i�� ��������� ���̴�
		now[i-1] = 0; //�� ����
		result[j] = i; //�� ���� ����
		j++;
	}

	//��� ���
	cout << "<";
	for (int z = 0; z < N; z++)
	{
		if (z == N - 1) //�������� ���
			cout << result[z];
		else //��������..
			cout << result[z] << ", ";
	}
	cout << ">" << endl;
}

int main()
{
	int N, K;
	cin >> N >> K;
	int* now = new int[N]; //���� ���¸� �����ϴ� �迭
	int* result = new int[N]; //����� �����ϴ� �迭
	for (int i = 0; i < N; i++) //���� ���¸� �����ϴ� �迭���� ��� 1�� ä���
		now[i] = 1;

	for (int i = 0; i < N; i++) //����� �����ϴ� �迭���� ��� 0���� ä���
		result[i] = 0;


	save(now, result, N, K);
	delete[] now;
	delete[] result;
}