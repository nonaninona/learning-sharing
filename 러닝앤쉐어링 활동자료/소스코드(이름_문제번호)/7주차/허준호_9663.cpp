#include <iostream>

using namespace std;

int N;
int answer;
int board[15] = { 0, };

bool check(int row)
{
	for (int i = 0; i < row; i++) //i는 0행부터 마지막 여왕이 위치한 곳 바로 윗 행까지
	{ //같은 열에 있거나 대각선에 위치한다면
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

	//첫 번째 행에 놓이는 돌의 위치를 i가 정함
	for (int i = 0; i < N; i++) //i가 열의 위치
	{
		board[row] = i;
		if (check(row)) //check한 게 통과하면
			run(row + 1);
		//통과한 거 다 끝내고 나면
		board[row] = 0;
	}
}


int main()
{
	cin >> N;
	run(0);
	cout << answer << endl;
}