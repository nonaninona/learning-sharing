#include <iostream>

long long gcd(long long N, long long A) {

	long long q = N / A;
	long long r = N % A;
	if (r == 0)
		return A;
	return gcd(A, r);
}
int main() {
	long long N;
	long long A;
	long long X[3];
	long long Y[3];
	long long R[3];
	long long Q;
	std::cin >> N;
	std::cin >> A;

	long long addR = N - A;
	std::cout << addR << " ";
	long long mulR;
	long long intersection = gcd(N, A);
	if (intersection != 1) {
		std::cout << -1;
		return 0;
	}
	X[0] = 1;
	Y[0] = 0;
	X[1] = 0;
	Y[1] = 1;
	R[0] = A;
	R[1] = N;
	while (true) {
		Q = R[0] / R[1];
		R[2] = R[0] % R[1];
		if (R[2] == 0) {
			mulR = X[1];
			break;
		}
		X[2] = X[0] - X[1] * Q;
		Y[2] = Y[0] - Y[1] * Q;

		R[0] = R[1];
		R[1] = R[2];

		X[0] = X[1];
		X[1] = X[2];

		Y[0] = Y[1];
		Y[1] = Y[2];
	}
	if (mulR < 0)
		mulR += N;
	std::cout << mulR;

}
