#include<iostream>
using namespace std;
void sort(int arr[], int size) {
	int n, m;
	for (n = 0; n < size; n++) {
		for (m = n + 1; m < size; m++) {
			if (arr[n] > arr[m]) {
				int c = arr[m];
				arr[m] = arr[n];
				arr[n] = c;
			}
		}
	}
}

int main() {
	int arr[9], trash[2];
	int all_sum = 0;
	for (int i = 0; i < 9; i++) {cin >> arr[i];}
	for (int i = 0; i < 9; i++) {all_sum += arr[i];}
	sort(arr, 9);
	for (int i = 0; i < 9; i++) {
		int check = 0;
		for (int j = i + 1; j < 9; j++) {
			int minus = arr[i];
			minus += arr[j];
			if (all_sum - minus == 100) {
				trash[0] = i;
				trash[1] = j;
				check = 1;
				break;
			}
			if (check == 1) break;
		}
	}
	cout << endl;
	for (int i = 0; i < 9; i++) {
		int check=0;
		for (int j = 0; j < 2; j++) {
			if (i == trash[j]) {
				check = 1;
				break;
			}
		}
		if (check == 1) {continue;}
		cout << arr[i] << endl;
		check = 0;
	}
}