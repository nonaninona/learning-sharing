#include <iostream>

int arr[1000000];

int getMin(int a, int b, int c) {

	if (a == -1 && b == -1) {
		return arr[c];
	}
	else if (a == -1 && b != -1) {
		if (arr[b] < arr[c])
			return arr[b];
		else
			return arr[c];
	}
	else if (a != -1 && b == -1) {
		if (arr[a] < arr[c])
			return arr[a];
		else
			return arr[c];
	}
	else {
		if (arr[a] < arr[b]) {
			if (arr[a] < arr[c])
				return arr[a];
			else
				return arr[c];
		}
		else {
			if (arr[b] < arr[c])
				return arr[b];
			else
				return arr[c];
		}
	}
}

int main() {
	int N;
	std::cin >> N;

	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 1;

	for (int i = 3; i < N; i++) {
		int value = i + 1;

		int a;
		if (value % 2 == 0) a = value / 2 - 1;
		else a = -1;
		int b;
		if (value % 3 == 0) b = value / 3 - 1;
		else b = -1;
		int c = value - 1 - 1;

		arr[i] = getMin(a, b, c) + 1;
	}

	std::cout << arr[N - 1];
}