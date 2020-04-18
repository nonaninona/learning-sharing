#include<iostream>
using namespace std;

int result(int n, int minus) {
	int	n_low = n - minus, copy, num = 0, sum = 0;
	for (; n_low < n; n_low++) {
		for (copy = n_low; copy > 0; copy /= 10) {
			num++;
		}
		for (copy = n_low; copy > 0; copy /= 10) {
			int s = copy % 10;
			sum += s;
		}
		if (n_low + sum == n) break;
		sum = 0;
	}
	return n_low;
}
int main() {
	int n, copy, num = 0;
	cin >> n;
	for (copy = n; copy > 0; copy /=10) {
		num++;
	}
	int minus = 0;
	for (int iter = 0; iter < num - 1; iter++) {
		minus = minus * 10 + 9;
	}
	int m = result(n, minus);
	if (m == n) cout << '0' << endl;
	else cout << m << endl;
}