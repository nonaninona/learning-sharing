#include<iostream>
#include<malloc.h>
using namespace std;

int algorithm(int A, int B, int C) {
	int* div_point;
	int* before_div;
	div_point = (int*)malloc(sizeof(int) * 100);
	before_div = (int*)malloc(sizeof(int) * 100);
	int div = A % C;
	int result = div;
	int num = 1, key = 0;
	div_point[0] = div;
	for (int i = 1; i < B; i++) {
		key = 0;
		before_div[i-1] = result;
		num = i + 1;
		result *= div;
		result %= C;
		for(int j=0; j<=i; j++){
			if (result == before_div[j]) {
				key = j;
				num--;
				break;
			}
		}
		if (num > 100) {
			div_point = (int*)realloc(div_point, sizeof(int) * num);
			before_div = (int*)realloc(div_point, sizeof(int) * num);
		}
		if (key > 0) break;
		div_point[i] = result;
	}
	int iter = B%num;
	if (B == num) {
		result = div_point[num - 1];
	}
	else if (B!=num&&iter == 0) result = div_point[num - 1];
	else result = div_point[iter-1+key];
	return result;
}

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	cout << algorithm(A, B, C) << endl;
}