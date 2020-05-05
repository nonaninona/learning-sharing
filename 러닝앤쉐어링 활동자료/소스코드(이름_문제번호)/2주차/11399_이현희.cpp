//#include <iostream>
//
//int N;
//int P[1000];
//int T[1000];
//
//void Sort() {
//	
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < N - 1; j++)
//			if (P[j] > P[j + 1]) {
//				int temp = P[j];
//				P[j] = P[j + 1];
//				P[j + 1] = temp;
//			}
//
//}
//
//int main() {
//
//	std::cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		std::cin >> P[i];
//	}
//
//	Sort();
//
//	int result;
//
//	T[0] = P[0];
//	result = T[0];
//	for (int i = 0; i < N-1; i++) {
//		T[i + 1] = T[i] + P[i + 1];
//		result += T[i+1];
//	}
//
//	std::cout << result;
//
//}