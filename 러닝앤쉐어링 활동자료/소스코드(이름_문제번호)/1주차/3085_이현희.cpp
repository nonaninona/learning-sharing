#include <iostream>

int N;
int count = 1;
int maxCount = 1;
char board[50][50];

void swap(char& num1, char& num2) {

	char temp = num1;
	num1 = num2;
	num2 = temp;

}

void countBoard() {

	for (int m = 0; m < N; m++) {	//가로로 세기
		count = 1;
		for (int n = 0; n < N-1; n++) {
			if (board[m][n] == board[m][n + 1]) {
				count++;
				if (count > maxCount)
					maxCount = count;
			}
			else
				count = 1;
		}
	}
	for (int m = 0; m < N; m++) {	//가로로 세기
		count = 1;
		for (int n = 0; n < N-1; n++) {
			if (board[n][m] == board[n + 1][m]) {
				count++;
				if (count > maxCount)
					maxCount = count;
			}
			else
				count = 1;
		}
	}
}

int main() {
	
	std::cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			std::cin >> board[i][j];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N - 1; j++)
			if (board[i][j] != board[i][j + 1]) {
				swap(board[i][j], board[i][j + 1]);
				countBoard();
				swap(board[i][j], board[i][j + 1]);				//바꾼 거 원위치
			}

	//세로로 바꾸고 세기
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N - 1; j++)
			if (board[j][i] != board[j + 1][i]) {
				swap(board[j][i], board[j+1][i]);
				countBoard();
				swap(board[j][i], board[j+1][i]);
			}

	std::cout << maxCount;
}