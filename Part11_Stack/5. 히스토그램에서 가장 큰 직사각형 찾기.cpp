/*
[생각하기]



*/


#include <stdio.h>
#include <math.h>
#include <stack>
#include <iostream>
using namespace std;
struct Box {

	long long index;
	long long height;

	Box(long long index, long long height) : index(index), height(height) {};
};

int arr[100010];

void print(stack<Box> s) {
	while (!s.empty()) {
		printf("(%d, %d)\n", s.top().index, s.top().height);
		s.pop();
	}
	cout << "----------------" << endl;
}

int main() {

	//Please Enter Your Code Here
	int min_idx = 0; //첫 인덱스
	long long val;
	stack<Box> s;
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	s.push(Box(0, 0));

	for (int i = 0; i < N; i++) {
		if (s.top().height <= arr[i]) {
			s.push(Box(i + 1, arr[i]));
		}
		else {
			while (s.top().height > arr[i]) {
				val = max(val, ((i + 1) - s.top().index) * s.top().height);
				//printf("val : %d\n", val);

				min_idx = s.top().index;
				//printf("min index: %d\n", min_idx);
				s.pop();
			}
			s.push(Box(min_idx, arr[i]));
		}
		//print(s);
	}

	Box b(N + 1, 0);

	while (!s.empty()) {
		val = max(val, (b.index - s.top().index) * s.top().height);
		// printf("%d\n", val);
		// print(s);
		s.pop();
	}

	printf("%d\n", val);

	return 0;
}