//#include <iostream>
//long long N;
//long long H[1000000];
//long long M;
//
//long long BinarySearch(long long start, long long end, long long v) {
//	long long mid = (start + end) / 2;
//
//	long long sum = 0;
//	for (long long i = 0; i < N; i++) {
//		if (H[i] > mid)
//			sum += H[i] - mid;
//	}
//
//	if (sum >= v) {
//		if (end - start <= 1)
//			return start;
//		else
//			return BinarySearch(mid, end, v);
//	}
//	else {
//		return BinarySearch(start, mid, v);
//	}
//}
//
//int main() {
//	std::cin >> N;
//	std::cin >> M;
//	for (long long i = 0; i < N; i++) {
//		std::cin >> H[i];
//	}
//
//	long long start = 0;
//	long long end = 2000000000;
//	long long h = BinarySearch(start, end, M);
//
//	std::cout << h;
//	
//}