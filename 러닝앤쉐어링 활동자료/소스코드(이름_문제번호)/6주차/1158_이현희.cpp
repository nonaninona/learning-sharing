#include <iostream>

int N;
int K;
int n[5000];
int result[5000];

int main() {
	std::cin >> N;
	std::cin >> K;

	int now = -1;
	for (int j = 0; j < N; j++) {
	
		for (int i = 0; i < K; i++) {
			now++;
			now %= N;
			if (n[now] == 1)
				i--;
		}
		result[j] = now;
		n[now] = 1;
	}

	std::cout << "<";

	for (int i = 0; i < N; i++) {
		if (i == 0) {
			std::cout << result[0] + 1;
			continue;
		}
		std::cout << ", " << result[i] + 1;
	}

	std::cout << ">";
}