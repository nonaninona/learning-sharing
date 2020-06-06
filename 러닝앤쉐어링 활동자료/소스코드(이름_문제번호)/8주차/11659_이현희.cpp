//#include <cstdio>
//
//int N;
//int M;
//int Start[100000];
//int End[100000];
//int n[100000];
//int pSum[100001];
//
//int main() {
//	scanf("%d", &N);
//	scanf("%d", &M);
//	for (int i = 0; i < N; i++) {
//		scanf("%d",&n[i]);
//	}
//	for (int i = 0; i < M; i++) {
//		scanf("%d",&Start[i]);
//		scanf("%d", &End[i]);
//	}
//	int sum = 0;
//	pSum[0] = sum;
//	for (int i = 0; i < N; i++) {
//		sum += n[i];
//		pSum[i+1] = sum;
//	}
//
//	for (int i = 0; i < M; i++) {
//		printf("%d\n", pSum[End[i]] - pSum[Start[i] - 1]);
//	}
//}