#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
const int MAX = 110;

int main() {

	//Please Enter Your Code Here
	int dArr[MAX] = { 0 };
	int hArr[MAX] = { 0 };
	int N, R;
	scanf("%d %d", &N, &R);

	dArr[R] = -1;
	for (int i = 1; i < N; i++) {
		int pNode, cNode;
		scanf("%d %d", &pNode, &cNode);
		dArr[cNode] = pNode;
	}

	int answer = INT_MIN;
	for (int i = R; i < R + N; i++) {
		int idx = i;
		int height = 0;
		if (dArr[idx] != -1) {
			height = hArr[dArr[idx]] + 1;
		}
		else {
			while (dArr[idx] != -1) {
				idx = dArr[idx];
				height = height + 1;
			}
		}
		hArr[i] = height;
		answer = max(answer, height);
	}


	printf("%d\n", answer);
	return 0;
}