/*


예제 입력
9 15
2 1 8 1 3 7 2 6 3

-> 9개의 숫자를 입력받고, 연속된 숫자의 합이 15이상이 되어야 한다. 
-> 몇 개의 연속된 숫자가 되어야 하는가?

예제 출력
3
-> 7 + 2 + 6 = 15


*/

#include <stdio.h>
#include <iostream>
using namespace std;

int arr[1000];
int N, R;

bool check(int n) {
	//배열을 모두 탐색하며
	//n개의 연속된 숫자의 합을 구한다.
	//시간복잡도는 O(n)이 나와야 한다.

	int sum = 0;

	for (int i = 0; i < n; i++) sum += arr[i];

	if (sum >= R) return true;

	for (int i = 0; i < N - n; i++) {
		sum = sum - arr[i] + arr[i + n];
		if (sum >= R) return true;
	}

	return false;

}

int binarySearch(int start, int end) {
	if (start + 1 >= end) return end;
	else {
		int mid = (start + end) / 2;
		if (check(mid)) return binarySearch(start, mid);
		else return binarySearch(mid, end);
	}
}
int main() {

	//Please Enter Your Code Here
	cin >> N >> R;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int start = 1;
	int end = N;

	if (check(1)) cout << 0;
	else if (!(check(N))) cout << 0;
	else {
		int answer = binarySearch(start, end);
		cout << answer;
	}

	return 0;
}