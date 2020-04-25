//#include <iostream>
//
//int N;
//int A[10];
//int K;
//
//int main() {
//
//	std::cin >> N;
//	std::cin >> K;
//	
//	for (int i = 0; i < N; i++)
//		std::cin >> A[i];
//
//	int countedCoin = 0;
//	int selectedCoin = N-1;
//
//	while (true) {
//		if (K == 0)
//			break;
//
//		if (K - A[selectedCoin] >= 0) {
//			K -= A[selectedCoin];
//			countedCoin++;
//		}
//		else
//			selectedCoin--;
//			
//	}
//
//	std::cout << countedCoin;
//
//}