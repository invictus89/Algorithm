#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <math.h>
using namespace std;

/*

2차식 정답 추측
문제
2차식 f(x) = x*x+ x 가 있고, 숫자 a가 주어진다. 
우리는 f(x) = a 를 만족하는 x의 값을 찾고 싶지만, 보통 이 값은 정수로 떨어지지 않는 경우가 많다. 
예를 들어, f(x) = 20 을 풀고자 한다면, x = 4이기 때문에 이는 정수이지만, f(x) = 103 을 풀고자 한다면 이는 x = 9.6612... 로써 정수가 아니다.

이 문제에서는 x의 정수부분이 얼마인지를 구하는 프로그램을 작성하시오. 
예를 들어, f(x) = 103 을 풀고자 한다면, x = 9.6612... 이기 때문에 정수부분은 9가 된다.



입력
첫 번째 줄에 숫자 a가 주어진다. ( 1 ≤ a ≤ 1,000,000,000,000,000,000 )

출력
f(x) = a 를 만족하는 x의 정수부분을 출력한다.

예제 입력
103
예제 출력
9




*/
long long cal(long num) {
	return num * num + num;
}

long binarySearch(long start, long end, long target) {
	//start ~ end 까지 이진 탐색으로 f(x) = x^2 + x의 해 구하기
	//printf("s:%d, e:%d\n", start, end);

	if (start >= end) {
		//기본 기저 조건
		int answer = (cal(start) > target) ? start - 1 : start;
		return answer;
	}
	else {
		long mid = (start + end) / 2;
		long val = cal(mid);

		if (target == val) return mid;
		else if (target > val) {
			return binarySearch(mid + 1, end, target);
		}
		else {
			return binarySearch(start, mid - 1, target);
		}
	}
}

int main() {

	//Please Enter Your Code Here
	long long a;
	cin >> a;

	//cout << a;
	long sq_max_long = sqrt(LONG_MAX);
	//탐색 리스트 범위

	long answer = binarySearch(0, sq_max_long, a);
	cout << answer;
	return 0;
}