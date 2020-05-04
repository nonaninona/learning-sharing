//#include <iostream>
//
//
//long long Calc(long long A, long long B, long long C) {
//
//	long long result;
//
//	A %= C;
//
//	if (B == 1)
//		return A;
//
//	if (B % 2 == 0) {
//		B /= 2;
//		A *= A;
//		A %= C;
//		result = Calc(A, B, C);
//		result %= C;
//	}
//	else {
//		B /= 2;
//		long long oldA = A;
//		A *= A;
//		A %= C;
//		result = (oldA%C) * Calc(A, B, C);
//		result %= C;
//	}
//
//	return result;
//}
//
//int main() {
//	long long A;
//	long long B;
//	long long C;
//	long long result;
//
//	std::cin >> A;
//	std::cin >> B;
//	std::cin >> C;
//
//	result = Calc(A, B, C);
//
//	std::cout << result%C;
//}