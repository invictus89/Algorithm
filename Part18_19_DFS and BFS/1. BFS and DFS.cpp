/*
반례

1. 시작노드가 과연 항상 0일까?
2. 노드 번호가 작은 순서대로 탐색을 한다.

*/

/*
문제
그래프가 주어질 때, 0번 정점을 시작으로 하여 깊이우선탐색과 너비우선탐색의 결과를 출력하는 프로그램을 작성하시오. 
단, 노드를 방문할 때는 노드 번호가 작은 순서대로 방문한다고 하자.


입력
첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. (1 ≤ N ≤ 1,000, 1 ≤ M ≤ 100,000 ) 둘째 줄부터 간선의 정보가 주어진다. 
각 줄은 두 개의 숫자 a, b로 이루어져 있으며, 이는 정점 a와 정점 b가 연결되어 있다는 의미이다.


출력
첫 번째 줄에 깊이우선탐색 결과, 두 번째 줄에 너비우선탐색 결과를 출력한다.

예제 입력
9 12
0 1
0 2
0 3
1 5
2 5
3 4
4 5
5 6
5 7
5 8
6 7
7 8

예제 출력
0 1 5 2 4 3 6 7 8
0 1 2 3 5 4 6 7 8

*/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>

using namespace std;

const int MAX = 100010;

int N, M;
bool visited[MAX]; //for dfs
bool check[MAX]; //for bfs
vector <int> v[MAX];
queue <int> q;
int startNode = INT_MAX;

void dfs(int node) {
	visited[node] = true;
	printf("%d ", node);

	for (int i = 0; i < v[node].size(); i++) {
		int nextNode = v[node][i];
		if (visited[nextNode] == false) {
			dfs(nextNode);
		}
	}
}

void bfs() {
	q.push(startNode);

	int curNode;

	while (1) {
		if (q.empty()) break;

		curNode = q.front();
		q.pop();
		check[curNode] = true;

		printf("%d ", curNode);

		for (int i = 0; i < v[curNode].size(); i++) {
			int nextNode = v[curNode][i];
			if (check[nextNode] == false) {
				q.push(nextNode);
				check[nextNode] = true;
			}
		}
	}
}


int main() {

	//Please Enter Your Code Here
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		startNode = min(startNode, a);
		startNode = min(startNode, b);
		v[a].push_back(b);
		v[b].push_back(a);
		sort(v[a].begin(), v[a].end());
		sort(v[b].begin(), v[b].end());

	}

	dfs(startNode);
	cout << endl;
	bfs();
	return 0;
}