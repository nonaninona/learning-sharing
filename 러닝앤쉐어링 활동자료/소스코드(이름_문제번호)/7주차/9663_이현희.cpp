//#include <iostream>
//#include <time.h>
//
//int initialBoard[15][15];
//int N;
//int count = 0;
//
//void copyBoard(int preBoard[15][15], int board[15][15]) {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			board[i][j] = preBoard[i][j];
//		}
//	}
//}
//void setBoard(int x, int y, int board[15][15]) {
//	for (int i = 0; i < N; i++) {
//		board[x][i] = 1;
//	}
//	for (int i = 0; i < N; i++) {
//		board[i][y] = 1;
//	}
//	for (int i = 1; x - i >= 0 && y - i >= 0; i++) {
//		board[x - i][y - i] = 1;
//	}
//	for (int i = 1; x - i >= 0 && y + i < N; i++) {
//		board[x - i][y + i] = 1;
//	}
//	for (int i = 1; x + i < N && y - i >= 0; i++) {
//		board[x + i][y - i] = 1;
//	}
//	for (int i = 1; x + i < N && y + i < N; i++) {
//		board[x + i][y + i] = 1;
//	}
//}
//
//void find(int row, int preBoard[15][15]) {
//	if (row == N) {
//		count++;
//		return; 
//	}
//	
//	int	board[15][15];
//	for (int i = 0; i < N; i++) {
//		if (preBoard[row][i] == 0) {
//			copyBoard(preBoard, board);
//			setBoard(row, i, board);
//			find(row+1, board);
//		}
//	}
//
//	return;
//}
//
//int main() {
//
//	std::cin >> N;
//
//	find(0, initialBoard);
//
//	std::cout << count;
//}