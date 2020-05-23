#include <iostream>
using namespace std;
long long check_Max(long long* point, long long size) {
	long long max;
	if (size > 0) {
		max = point[0];
	}// point�� ũ�Ⱑ 0�� �ƴϸ� �ùٸ��� ����
	else {
		cerr << "�������� ũ�Ⱑ 0�Դϴ�." << endl;
		return -1;
	}// point�� ũ�Ⱑ 0�̸� �Լ� ����
	
	for (long long index = 1; index < size; index++) {
		if (max < point[index]) {
			max = point[index];
		}//max������ �ش� �ε��� ���� �� ũ�ٸ� max���� �ٲپ���
	}//�ݺ����� index=1���� �����ؼ� index=(ũ��)-1���� �ݺ�(size-1��)

	return max;
}

long long sum_CutTree(long long value, long long* tree, long long tree_Size) {
	//value=������ ����, tree=������ ���̸� ������ ������, tree_Size=������ ����
	long long sum = 0;

	for (long long index = 0; index < tree_Size; index++) {
		if (tree[index] > value) {
			sum += tree[index] - value;
			// ������ ������ ���̸� ���ְ� �ڸ� ���̸� sum�� ������.
		}//�ش� index�� ���� ���̰� ������ ���̺��� Ŭ�� ���ǹ� ����
	}//������ ������ŭ �ݺ�.

	return sum;
}

long long check_height(long long max_height, long long* tree, long long tree_Size, long long M) {
	long long right_Value = max_height, left_Value = 0;
	// �̺� Ž���� ���� ���� ������ ���� ���� ���� ����
	long long result=0, m;

	while (left_Value<=right_Value) {
		long long mid = (left_Value + right_Value) / 2;//left+right�� Ȧ���� �Ҽ��� ���� ����.
		m = sum_CutTree(mid, tree, tree_Size);
		if (m == M) {
			return mid;
		}
		else if (m > M) {
			if (result < mid) {
				result = mid;
			}
			left_Value = mid + 1;
		}//�ڸ� ������ ���� ���Ϸ��� ���� ���̺��� �۴ٸ�, ���� ����(result)�� �ٿ��� ��.
		else {
			right_Value = mid - 1;
		}//�ڸ� ������ ���� ���Ϸ��� ���� ���̺��� ũ�ٸ�, ���� ����(result)�� �÷��� ��.
	}
	return result;
}

int main() {
	long long N; long long M; // N = '������ ��', M = '���������� �ϴ� ������ ����'
	cin >> N >> M; // ������ ��(N)�� ���������� �ϴ� ���� ����(M)�� �Է¹���
	long long* tree = new long long[N]; // ������ ����ŭ �����Ҵ�
	for (int i = 0; i < N; i++) {
		cin >> tree[i]; // �� ������ ���̸� �Է¹���
	}
	long long max_height = check_Max(tree, N);
	cout << check_height(max_height, tree, N, M) << endl;
	delete[]tree;
}