#include<iostream>
using namespace std;
int* point;

void put_zero(int* p, int size) {
	for (int i = 0; i < size; i++) {
		p[i] = 0;
	}
}

void make_point(int n) {
	point = new int[n];
	put_zero(point, n);
}

int minimum(int* arr, int size) {
	int min = 0;
	for (int i = 0; i < size; i++) {
		if (min == 0 && arr[i] != 0) {
			min = arr[i];
		}
		else if (min > arr[i] && arr[i] != 0) {
			min = arr[i];
		}
	}
	return min;
}

int result(int n) {
	int num = 0;
	int arr[3] = { 0, 0, 0 };
	if (n == 2 || n == 3) { return 1; }
	if (point[n - 1] != 0) {
		return point[n - 1];
	}
	if (n % 3 == 0) {
		arr[0] = result(n / 3);
	}
	if (n % 2 == 0) {
		arr[1] = result(n / 2);
	}
	arr[2] = result(n - 1);
	
	int min = minimum(arr, 3);
	point[n - 1] = min + 1;
	num = min + 1;
	return num;
}

int main() {
	int n = 0;
	cin >> n;
	make_point(n);
	cout << result(n) << endl;
	delete[] point;
}