#include <iostream>

using namespace std;

int N;
int answer;
int board[15] = { 0, };

bool check(int row)
{
	for (int i = 0; i < row; i++) //i�� 0����� ������ ������ ��ġ�� �� �ٷ� �� �����
	{ //���� ���� �ְų� �밢���� ��ġ�Ѵٸ�
		if (board[row] == board[i] || abs(row - i) == abs(board[row] - board[i])) 
			return false;
	}
	return true;
}

void run(int row)
{
	if (row == N)
	{
		answer++;
		return;
	}

	//ù ��° �࿡ ���̴� ���� ��ġ�� i�� ����
	for (int i = 0; i < N; i++) //i�� ���� ��ġ
	{
		board[row] = i;
		if (check(row)) //check�� �� ����ϸ�
			run(row + 1);
		//����� �� �� ������ ����
		board[row] = 0;
	}
}


int main()
{
	cin >> N;
	run(0);
	cout << answer << endl;
}