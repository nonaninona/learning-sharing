#include<iostream>
using namespace std;
class intstack {
private: 
	
public:
	int top=-1;
	int num_stack[50];
	bool empty() {
		return (top == -1);
	}
	int peak() {
		return num_stack[top];
	}
	int pop() {
		if (top != -1) {
			return num_stack[top--];
		}
	}
	void push(int num) {
		top++;
		num_stack[top] = num;
	}
	void push_2(int num) {
		num_stack[top] = num_stack[top] * 10 + num;
	}
};
class charstack {
private:
public:
	int top=-1;
	char char_stack[50];
	bool empty() {
		return (top == -1);
	}
	int peak() {
		return char_stack[top];
	}
	int pop() {
		if (top != -1) {
			return char_stack[top--];
		}
	}
	void push(char tok) {
		top++;
		char_stack[top] = tok;
	}
};


int main() {
	char str[50];
	intstack num;
	charstack tok;
	cin >> str;
	for (int i = 0; str[i] != '\0'; i++) {
		if (i > 0 && ('0' <= str[i - 1] && '9' >= str[i - 1]) && ('0' <= str[i] && '9' >= str[i])) { num.push_2((int)(str[i] - '0')); }
		else if('0'<=str[i]&&'9'>=str[i]){
			num.push((int)(str[i]-'0'));
		}
		else if (str[i] == '+') {
			if (!tok.empty()) {
				if (tok.peak() == '+'){
					tok.pop();
					int a = num.pop();
					int b = num.pop();
					num.push(a + b);
				}
			}
			tok.push(str[i]);
		}
		else if (str[i] == '-') {
			if (!tok.empty()) {
				if (tok.peak() == '+') {
					tok.pop();
					int a = num.pop();
					int b = num.pop();
					num.push(a + b);
				}
			}
			tok.push(str[i]);
		}
	}
	while (!tok.empty()) {
		if (tok.peak() == '-') {
			tok.pop();
			if (!tok.empty()) {
				if (tok.peak() == '-') {
					int a = num.pop();
					int b = num.pop();
					num.push(b + a);
				}
			}
			else {
				int a = num.pop();
				int b = num.pop();
				num.push(b - a);
			}
		}
		else {
			tok.pop();
			int a = num.pop();
			int b = num.pop();
			num.push(b + a);
		}
	}
	cout << num.pop();
}