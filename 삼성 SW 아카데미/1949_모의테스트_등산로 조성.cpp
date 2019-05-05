#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <algorithm>
using namespace std;

/*
[설계 포인트]
1. 두 명의 일꾼의 위치를 먼저 선정한다.
2. 선정된 위치내에서 재귀함수를 통해 원하는 값을 계산한다.

[주의 사항]
1. 다중 for문 내에서 최대 및 최소값을 구해야 할 경우 어느 for문에서 구현해야 하는지 신중히 생각해야 한다.
  (쉬운만큼 쉽게 실수 할 수 있다. --- 이거때매 1시간 반 고생함...)

*/

const int MAX = 12; //맵 크기
int honeyMap[MAX][MAX]; // 벌꿀 저장 맵
int N, M, C; // 입력 값
int debug[MAX][MAX]; // 테스트 용
int temp[MAX]; // 일꾼의 벌꿀 채취 범위만을 따로 관리하기 위한 배열
int list[MAX]; // temp 배열 내에서 원소의 개수를 고려하여 합계를 구하기 위한 배열 
bool check[MAX]; // list에서 합을 구할 때 중복 관리를 위한 배열
int res = INT_MIN; // list 내에서 합계의 최대값을 갖는 변수

struct Worker {
	int x, y;
};

void debuging(int x1, int y1, int x2, int y2) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			debug[i][j] = 0;
		}
	}
	debug[x1][y1] = 1;
	debug[x2][y2] = 2;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%d ", debug[i][j]);
		}
		printf("\n");
	}
}
//temp배열에서 digit의 숫자자리만큼(list배열) 합을 구하여 C가 넘지않으면
//그 제곱수의 합(res)을 리턴해주는 재귀함수
int getSum(int digit, int index) {
	//기저 조건
	if (index >= digit) {
		int sum = 0;
		int sum2 = 0;
		for (int i = 0; i < digit; i++) {
			sum = sum + list[i];
			sum2 = sum2 + list[i] * list[i];
		}
		if (sum <= C) {
			res = max(res, sum2);
			return res;
		}
	}

	//재귀 구현
	for (int i = 0; i < M; i++) {
		if (check[i] == false) {
			list[index] = temp[i];
			check[i] = true;
			res = getSum(digit, index + 1);
			check[i] = false;
		}
	}
	return res;
}

int main() {
	int answer = 0;
	int sumWorker1 = 0; //list배열에서의 자리수별 합계의 최대값
	int sumWorker2 = 0;
	int res1 = 0; //자리수별 합계중에서의 최대값
	int res2 = 0;
	int t;
	scanf("%d", &t);
	for (int z = 0; z < t; z++) {
		//초기화 코드
		scanf("%d %d %d", &N, &M, &C);
		for (int i = 0; i < N + 2; i++) {
			for (int j = 0; j < N + 2; j++) {
				honeyMap[i][j] = 10;
			}
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				scanf("%d", &honeyMap[i][j]);
			}
		}

		//구현 시작

		//i1, j1 - 일꾼1
		for (int i1 = 1; i1 <= N; i1++) {
			for (int j1 = 1; j1 <= N; j1++) {
				Worker w1({ i1, j1 });
				if (w1.y + (M - 1) > N) continue;
				//i2, j2 - 일꾼2
				for (int i2 = 1; i2 <= N; i2++) {
					for (int j2 = 1; j2 <= N; j2++) {
						Worker w2({ i2, j2 });
						if (w1.x == w2.x && w1.y == w2.y) continue;
						if (w1.x == w2.x && w1.y > w2.y) {
							if (w2.y + (M - 1) >= w1.y) continue;
						}
						if (w1.x == w2.x && w1.y < w2.y) {
							if (w1.y + (M - 1) >= w2.y || w2.y + (M - 1) > N) continue;
						}
						if (w2.y + (M - 1) > N) continue;

						//일꾼1과 일꾼2의 위치가 정해졌다.
						//이제 재귀함수로 최대값을 구하자
						for (int i = 1; i <= M; i++) {
							//합이 원소 한개에서 M까지 이루어질 경우를 나누어서 계산
							for (int j = 0; j < M; j++) temp[j] = honeyMap[w1.x][w1.y + j];
							sumWorker1 = getSum(i, 0);
							res1 = max(res1, sumWorker1);
							for (int j = 0; j < M; j++) check[j] = 0;
							res = INT_MIN;
							//일꾼 1 완료

							for (int j = 0; j < M; j++) temp[j] = honeyMap[w2.x][w2.y + j];
							sumWorker2 = getSum(i, 0);
							res2 = max(res2, sumWorker2);
							for (int j = 0; j < M; j++) check[j] = 0;
							res = INT_MIN;
							//일꾼 2 완료

						}
						answer = max(answer, (res1 + res2));
						res = INT_MIN;
						res1 = INT_MIN;
						res2 = INT_MIN;
						//위의 4줄의 코드를 for문내에서 구현하여 한시간 반동안 고생함....
					}
				}
			}
		}
		printf("#%d %d\n", (z + 1), answer);
		answer = 0;
	}
	return 0;
}