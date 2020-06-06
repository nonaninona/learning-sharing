//#include <cstdio>
//
//int N;
//int M;
//int board[1024][1024];
//int pSum[1024][1025]; 
//int x_1[100000];
//int y_1[100000];
//int x_2[100000];
//int y_2[100000];
//
//int main() {
//	scanf("%d", &N);
//	scanf("%d", &M);
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < N; j++)
//			scanf("%d", &board[i][j]);
//
//	int sum = 0;
//
//	for (int i = 0; i < N; i++) {
//		sum = 0;
//		pSum[i][0] = 0;
//		for (int j = 0; j < N; j++) {
//			sum += board[i][j];
//			pSum[i][j + 1] = sum;
//		}
//	}
//
//	for (int i = 0; i < M; i++) {
//		scanf("%d", &x_1[i]);
//		scanf("%d", &y_1[i]);
//		scanf("%d", &x_2[i]);
//		scanf("%d", &y_2[i]);
//	}
//	
//	int result = 0;
//	for (int i = 0; i < M; i++) {
//		result = 0;
//		for (int j = 0; j < x_2[i] - x_1[i] + 1; j++) {
//			result += pSum[x_1[i] + j - 1][y_2[i]] - pSum[x_1[i] + j - 1][y_1[i]-1];
//		}
//		printf("%d\n", result);
//	}
//}