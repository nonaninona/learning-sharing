#include <iostream>
using namespace std;
long long check_Max(long long* point, long long size) {
	long long max;
	if (size > 0) {
		max = point[0];
	}// point의 크기가 0이 아니면 올바르게 동작
	else {
		cerr << "포인터의 크기가 0입니다." << endl;
		return -1;
	}// point의 크기가 0이면 함수 종료
	
	for (long long index = 1; index < size; index++) {
		if (max < point[index]) {
			max = point[index];
		}//max값보다 해당 인덱스 값이 더 크다면 max값을 바꾸어줌
	}//반복문은 index=1부터 시작해서 index=(크기)-1까지 반복(size-1번)

	return max;
}

long long sum_CutTree(long long value, long long* tree, long long tree_Size) {
	//value=설정한 높이, tree=나무의 길이를 저장한 포인터, tree_Size=나무의 개수
	long long sum = 0;

	for (long long index = 0; index < tree_Size; index++) {
		if (tree[index] > value) {
			sum += tree[index] - value;
			// 나무에 설정한 높이를 빼주고 자른 길이를 sum에 더해줌.
		}//해당 index의 나무 길이가 설정한 높이보다 클때 조건문 실행
	}//나무의 개수만큼 반복.

	return sum;
}

long long check_height(long long max_height, long long* tree, long long tree_Size, long long M) {
	long long right_Value = max_height, left_Value = 0;
	// 이분 탐색을 위해 가장 오른쪽 값과 왼쪽 값을 설정
	long long result=0, m;

	while (left_Value<=right_Value) {
		long long mid = (left_Value + right_Value) / 2;//left+right가 홀수면 소숫점 이하 버림.
		m = sum_CutTree(mid, tree, tree_Size);
		if (m == M) {
			return mid;
		}
		else if (m > M) {
			if (result < mid) {
				result = mid;
			}
			left_Value = mid + 1;
		}//자른 나무의 합이 구하려는 나무 길이보다 작다면, 설정 높이(result)를 줄여야 함.
		else {
			right_Value = mid - 1;
		}//자른 나무의 합이 구하려는 나무 길이보다 크다면, 설정 높이(result)를 늘려야 함.
	}
	return result;
}

int main() {
	long long N; long long M; // N = '나무의 수', M = '가져가려고 하는 나무의 길이'
	cin >> N >> M; // 나무의 수(N)와 가져가려고 하는 나무 길이(M)을 입력받음
	long long* tree = new long long[N]; // 나무의 수만큼 동적할당
	for (int i = 0; i < N; i++) {
		cin >> tree[i]; // 각 나무의 높이를 입력받음
	}
	long long max_height = check_Max(tree, N);
	cout << check_height(max_height, tree, N, M) << endl;
	delete[]tree;
}