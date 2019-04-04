/*
순열구하기
문제
서로 다른 n개의 원소들 중에서 r개만을 뽑아 일렬로 나열하는 것을 순열이라 한다. 
예를 들어, 3개의 원소 a, b, c 중에서 2개만을 뽑아 나열하면 ab, ac, ba, bc, ca, cb 의 6가지 경우가 있다. 
n과 r이 주어질 때, n개의 소문자 중에서 r개만을 뽑아 나열하는 모든 경우를 출력하는 프로그램을 작성하시오. 
단, a부터 시작하여 연속으로 n개의 알파벳을 갖고 있다고 하자.

입력
첫 번째 줄에 n과 r이 주어진다. ( 1 ≤ n ≤ 26, 1 ≤ r ≤ n )

출력
각 줄에 n개의 소문자 중에서 r개만을 뽑아 나열하는 경우를 사전순으로 나열한 결과를 출력한다.



예제 입력
4 2

예제 출력
ab
ac
ad
ba
bc
bd
ca
cb
cd
da
db
dc

*/
#include <stdio.h>
#include <iostream>
using namespace std;

string arr[12];
string ansArr[12];
bool isOkArr[12];
char c = 'a';
int N, R;

void printAlpha(int idx) {
	if (idx >= R) {
		for (int i = 0; i < R; i++) {
			cout << ansArr[i];
		}
		cout << endl;
	}
	else {
		for (int i = 0; i < N; i++) {
			if (isOkArr[i] == true) {
				ansArr[idx] = arr[i];
				isOkArr[i] = false;
				printAlpha(idx + 1);
				isOkArr[i] = true;
			}
		}

	}
}

int main() {

	//Please Enter Your Code Here
	scanf("%d %d", &N, &R);

	for (int i = 0; i < N; i++) {
		string str = string(1, c);
		arr[i] = str;
		c++;
		isOkArr[i] = true;

	}

	printAlpha(0);

	return 0;
}
