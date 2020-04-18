//#include <iostream>
//
//int main() {
//	
//	int height[9];
//	int result[7];
//	int a, b;
//	int sum = 0;
//	int testSum;
//
//	for (int i = 0; i < 9; i++) {
//		std::cin >> height[i];
//		sum += height[i];
//	}
//
//	for (int i = 0; i < 8; i++) {
//		for (int j = i+1; j < 9; j++) {
//			testSum = sum - height[j] - height[i];
//			if (testSum == 100) {
//				a = i; b = j;
//				break;
//			}
//		}
//		if (testSum == 100)
//			break;
//	}
//
//	int k = 0;
//	for (int i = 0; i < 9; i++) {
//		if (i == a || i == b)
//			continue;
//
//		result[k] = height[i];
//		k++;
//		if (k == 8)
//			break;
//	}
//
//	for (int i = 0; i < 7; i++) {
//		for (int j = 0; j < 6; j++) {
//			if (result[j] > result[j + 1]) {
//				int temp = result[j];
//				result[j] = result[j+1];
//				result[j + 1] = temp;
//			}
//		}
//	}
//	
//	for (int i = 0; i < 7; i++) {
//		std::cout << result[i] << std::endl;
//	}
//
//}