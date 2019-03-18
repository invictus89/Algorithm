/*
접시
문제
접시가 a, b, c, d 가 있고, 알파벳 순으로 한쪽이 막혀 있는 세척기에 들어간다고 할 때, b a c d 순으로 꺼내기 위해서는 
push, push, pop, pop, push, pop, push, pop을 하면 된다. 세척기에서 꺼내는 순서가 주어질 때 그 동작을 출력하는 프로그램을 작성하시오. 
만약 주어진 순서대로 접시를 꺼낼 수 없다면 “impossible”을 출력한다.


입력
첫째 줄에 소문자 알파벳이 주어진다. 중복된 소문자 알파벳은 입력되지 않는다. 알파벳 소문자는 26개이다.

출력
접시를 꺼내는 것이 가능한 경우 push, pop의 순서를 출력한다. 이것이 불가능하다면 impossible을 출력한다.

예제 입력
bacd
예제 출력
push
push
pop
pop
push
pop
push
pop

예제 입력
dabc
예제 출력
impossible


*/

#include <stdio.h>
#include <iostream>
using namespace std;

struct Stack {
	int data[110];
	int len = 0;
	int capacity = 0;

	void create(int n) {
		capacity = n;
	}

	void push(int x) {
		if (len >= capacity) {
			cout << "Overflow" << endl;
		}
		else {
			data[len++] = x;
		}
	}

	void pop() {
		if (len <= 0) {
			cout << "Underflow" << endl;
		}
		else {
			data[len - 1] = 0;
			len--;
		}
	}

	int top() {
		if (len <= 0) {
			cout << "NULL" << endl;
			return -1;
		}
		else {
			//cout << "top : " << data[len-1] << endl;
			return data[len - 1];
		}
	}

	int size() {
		return len;
	}
};
int main() {

	//Please Enter Your Code Here
	int n, m;
	cin >> n >> m;
	Stack s;
	s.create(n);
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		if (x == 1) {
			int y;
			cin >> y;
			s.push(y);
		}
		if (x == 2) {
			s.pop();
		}
		if (x == 3) {
			int val = s.top();
			if (val != -1) cout << val << endl;
		}
	}
	return 0;
}