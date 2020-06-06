#include<iostream>
using namespace std;

/*int main() {
	int* bracket_int, * bracket_sum, * result;
	int N, M;
	cin >> N >> M;
	bracket_int = new int[N];
	bracket_sum = new int[N + 1];
	result = new int[M];
	bracket_sum[0] = 0;

	for (int i = 0; i < N; i++) {
		cin >> bracket_int[i];
		bracket_sum[i + 1] = bracket_sum[i] + bracket_int[i];
	}// 모든 수를 넣어줌

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		result[i] = bracket_sum[b] - bracket_sum[a-1];
	}
	for (int i = 0; i < M; i++) {
		cout << result[i] << "\n";
	}
	delete [] bracket_int;
	delete [] bracket_sum;
	delete [] result;
}*/
int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);

	int* bracket_sum, * result;
	int N, M;
	cin >> N >> M;
	bracket_sum = new int[N + 1];
	result = new int[M];
	bracket_sum[0] = 0;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		bracket_sum[i + 1] = bracket_sum[i] + a;
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		result[i] = bracket_sum[b] - bracket_sum[a - 1];
	}

	for (int i = 0; i < M; i++) {
		cout << result[i] << "\n";
	}

	delete[] bracket_sum;
	delete[] result;
}