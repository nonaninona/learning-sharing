#include <iostream>

int K[1000];
int TriangleNumber[44];

int main() {

	//Input
	int N;

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> K[i];
	}

	//Set Triangle Number Table
	TriangleNumber[0] = 1;
	for (int i = 1; i < 44; i++) {
		TriangleNumber[i] = TriangleNumber[i - 1] + i+1;
	}

	//Find 3 Triangle Number for Input
	int number = 0;
	bool did_find = false;

	for (int i = 0; i < N; i++) {
		did_find = false;
		for (int j = 0; j < 44; j++) {
			for (int k = 0; k < 44; k++) {
				for (int l = 0; l < 44; l++) {
					if (K[i] == TriangleNumber[j] + TriangleNumber[k] + TriangleNumber[l]) {
						did_find = true;
						break;
					}
				}
				if (did_find)
					break;
			}
			if (did_find)
				break;
		}
		if (did_find)
			K[i] = 1;
		else
			K[i] = 0;
	}

	for (int i = 0; i < N; i++) {
		std::cout << K[i] << std::endl;
	}

}