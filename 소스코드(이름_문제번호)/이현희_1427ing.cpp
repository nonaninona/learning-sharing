#include <iostream>

int doQuickSort(int A[], int start, int end) {

	int length = end + 1 - start;
	int pivot = end;
	int index = start;
	int temp;

	for (int i = start; i < end; i++) {
		if (A[i] <= pivot) {
			temp = A[i];
			A[i] = A[index];
			A[index] = temp;
			index++;
		}
	}
	temp = A[end];
	A[end] = A[index];
	A[index] = temp;

	doQuickSort(A, start, start + index + 1);
	doQuickSort(A, end - index + 1, end);

}

int getSquare(int N, int times) {

	int result = 1;

	for (int i = 0; i < times; i++) {
		result *= N;
	}

	return result;
}

int main() {
	int input;
	std::cin >> input;
	int length;
	int 

	for (int i = 0; i < 10; i++) {
		input
	}
}