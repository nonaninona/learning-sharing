//#include <iostream>
//#include <string>
//#include <stack>
//
//std::stack<std::string> TermStack;
//
//
//int main() {
//	std::string str;
//	std::cin >> str;
//
//	int size = str.size();
//	int i = 0;
//	int pi = -1;
//	int j = 0;
//	for (i = 0; i < size; i++) {
//		if (str[i] == '+' || str[i] == '-') {
//			TermStack.push(str.substr(pi + 1, i - pi - 1));
//			TermStack.push(str.substr(i, 1));
//			pi = i;
//			j += 2;
//		}
//	}
//	TermStack.push(str.substr(pi + 1, size - 1 - pi));
//
//	int result = 0;
//	int subResult = 0;
//	while (true) {
//		subResult += atoi(TermStack.top().c_str()); TermStack.pop();
//		if (TermStack.empty())
//			break;
//		if (TermStack.top() == "-") {
//			result -= subResult;
//			subResult = 0;
//		}
//		TermStack.pop();
//		if (TermStack.empty())
//			break;
//	}
//	result += subResult;
//
//	std::cout << result;
//
//}