#include <iostream>

int arr[30] = { 0, };

int main() {

	int N;
	std::cin >> N;
	arr[0] = 0;
	arr[1] = 3;

	for (int i = 2; i < N; i++) {

		int value = i + 1;

		if (value % 2 == 0) {
			int k = arr[i - 2];

			int s = 0;
			for (int j = 1; j < i; j = j + 2) {
				s += arr[j];
			}

			k += 2 * s;
			k += 2;
			arr[i] = k;
		}
		else
			arr[i] = 0;

	}

	std::cout << arr[N - 1];
}