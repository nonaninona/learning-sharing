//#include <iostream>
//
//int square(int n, int times) {
//
//	int result = 1;
//
//	for (int i = 0; i < times; i++) {
//		result *= n;
//	}
//
//	return result;
//}
//
//int main() {
//
//	int N = 0;
//	int scale;
//	int constructer;
//	int tempi;
//
//	while(!(N <= 1000000 && N >= 1))
//		std::cin >> N;
//
//	for (int i = 1; i <= N; i++) {
//		
//		if (i == N) {
//			constructer = 0;
//			break;
//		}
//		
//		tempi = i;
//
//		for (int j = 1; j < 7; j++)
//			if (tempi / square(10, j) == 0) {
//				scale = j;			//ex) 256Àº 3ÀÚ¸®
//				break;
//			}
//
//		constructer = tempi;
//
//		for (int j = 0; j < scale; j++) {
//			int number = tempi / square(10, scale - 1 - j);
//			constructer += number;
//			tempi -= number * square(10, scale - 1 - j);
//		}
//
//		if (constructer == N) {
//			constructer = i;
//			break;
//		}
//	}
//
//	std::cout << constructer << std::endl;
//
//}