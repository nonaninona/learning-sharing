#include <iostream>

int arr[1000];

int fillTile(int n) {

	if (n == 0)
		return arr[0];
	else if (n == 1)
		return arr[1];

	if (arr[n] != -1)
		return arr[n];
	else {
		int a = fillTile(n - 2) % 10007;
		int b = fillTile(n - 1) % 10007;
		a = (2 * a) % 10007;
		int k = (a + b)%10007;
		arr[n] = k%10007;
		return k;
	}
}

int main() {
	for (int i = 0; i < 1000; i++) {
		arr[i] = -1;
	}
	int N;
	std::cin >> N;
	arr[0] = 1;
	arr[1] = 3;

	for (int i = 2; i < N; i++) {
		fillTile(i);
	}

	std::cout << arr[N - 1];
}