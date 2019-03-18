/*
두 용액

문제
KOI 부설 과학연구소에서는 많은 종류의 산성 용액과 알칼리성 용액을 보유하고 있다.각 용액에는 그 용액의 특성을 나타내는 하나의 정수가 주어져있다.
산성 용액의 특성값은 1부터 1, 000, 000, 000까지의 양의 정수로 나타내고, 
알칼리성 용액의 특성값은 - 1부터 - 1, 000, 000, 000까지의 음의 정수로 나타낸다.
같은 양의 두 용액을 혼합한 용액의 특성값은 혼합에 사용된 각 용액의 특성값의 합으로 정의한다.
이 연구소에서는 같은 양의 두 용액을 혼합하여 특성값이 0에 가장 가까운 용액을 만들려고 한다.
예를 들어, 주어진 용액들의 특성값이[-2, 4, -99, -1, 98]인 경우에는 
특성값이 - 99인 용액과 특성값이 98인 용액을 혼합하면 특성값이 - 1인 용액을 만들 수 있고, 
이 용액이 특성값이 0에 가장 가까운 용액이다.
참고로, 두 종류의 알칼리성 용액만으로나 혹은 두 종류의 산성 용액만으로 특성값이 0에 가장 가까운 혼합 용액을 만드는 경우도 존재할 수 있다.
산성 용액과 알칼리성 용액의 특성값이 주어졌을 때, 
이 중 두 개의 서로 다른 용액을 혼합하여 특성값이 0에 가장 가까운 용액을 만들어내는 두 용액을 찾는 프로그램을 작성하시오.



입력
첫째 줄에는 전체 용액의 수 N이 입력된다.N은 2 이상 100, 000 이하이다.
둘째 줄에는 용액의 특성값을 나타내는 N개의 정수가 빈칸을 사이에 두고 주어진다.
이 수들은 모두 - 1, 000, 000, 000 이상 1, 000, 000, 000 이하이다.N개의 용액들의 특성값은 모두 다르고, 
산성 용액만으로나 알칼리성 용액만으로 입력이 주어지는 경우도 있을 수 있다.

출력
첫째 줄에 특성값이 0에 가장 가까운 용액을 만들어내는 두 용액의 특성값을 출력한다.
출력해야하는 두 용액은 특성값의 오름차순으로 출력한다.
특성값이 0에 가장 가까운 용액을 만들어내는 경우가 두 개 이상일 경우에는 특성값의 최솟값이 가장 작은 숫자를 출력한다.
해당 경우에서 특성값의 최솟값이 같은 경우는 없다고 가정한다.

예제 입력
5
- 2 4 - 99 1 98
예제 출력
- 99 98


출처
2010 한국정보올림피아드 전국본선 중등부 1번
*/
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <limits.h>
/*
시간 복잡도 주의
첫째 시도 : 이중 포문( O(n^2) )으로 안됨
둘째 시도 : n이 100,000이라서 n * long n 가능함
*/
using namespace std;

int N;
int arr[100010];
int ans_1 = 0;
//min_ans를 만드는 앞의 값
int ans_2 = 0;
//min_ans를 만드는 뒤의 값

int main() {
	int min_ans = INT_MAX;
	//배열 전체 범위에서 0과 가장 가까운 최종 값
	int min_val = 0;
	//picked와 min_temp와 더한 값

	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
	sort(arr, arr + N);

	for (int i = 0; i < N; i++) {
		int picked = arr[i];
		int start = 0;
		int end = N - 1;

		while (start + 1 < end) {
			int mid = (start + end) / 2;
			if (arr[mid] + picked >= 0) end = mid;
			else start = mid;
		}
		//start와 end가 인접하여 위치하게 된다.

		int min_temp = 0;
		//picked와 더해 가장 0에 가까운 곳의 값

		//picked와 start, picked와 end 중 작은 것을 계산한다.
		if (abs(picked + arr[start]) > abs(picked + arr[end])) {
			if (i == end) {
				//-2, 0이고 picked가 0일때, piced와 end가 중복
				min_temp = arr[start];
			}
			else {
				min_temp = arr[end];
				min_val = abs(picked + arr[end]);
			}
		}
		else {
			if (i == start) {
				//0, 2이고 picked가 0일때, piced와 start가 중복
				min_temp = arr[end];
			}
			else {
				min_temp = arr[start];
				min_val = abs(picked + arr[start]);
			}
		}

		if (min_ans > min_val) {
			ans_1 = picked;
			ans_2 = min_temp;
			min_ans = min_val;
		}
		else if (min_ans == min_val) {
			if (min(picked, min_temp) < min(ans_1, ans_2)) {
				ans_1 = picked;
				ans_2 = min_temp;
			}
		}
		//printf("first : %d, second: %d\n", ans_1, ans_2);
	}
	printf("%d %d\n", ans_1, ans_2);
	return 0;
}