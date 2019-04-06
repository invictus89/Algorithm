/*
문제
트리가 주어지고, 두 노드 X, Y가 주어질 때, 이 두 노드 사이의 거리를 출력하는 프로그램을 작성하시오. 
트리에서는 두 노드를 잇는 경로가 유일하기 때문에, 정답은 항상 유일하다는 것을 참고한다. 
예를 들어, 다음과 같은 트리에서 노드 3, 노드 6 사이의 거리는 4이다.


입력
첫 번째 줄에 트리의 노드 개수 n, 두 노드 X, Y의 번호가 주어진다. ( 0 ≤ X, Y ≤ n < 1000 ) 
두 번째 줄부터 트리의 간선 정보가 주어진다. 각 줄은 2개의 숫자 a, b로 이루어지며, 
이는 노드 a가 노드 b의 부모노드라는 것을 의미한다. 루트는 노드 0이라고 가정한다.

출력
두 노드 X, Y 사이의 거리를 출력한다.


예제 입력
11 3 6
0 1
0 2
1 3
1 4
1 5
2 6
2 10
6 7
6 8
6 9

예제 출력
4

*/

#include <stdio.h>
#include <iostream>
using namespace std;
const int MAX = 1010;
int main() {

	//Please Enter Your Code Here
	int nArr[MAX];
	int hArr[MAX];
	int n, x, y;
	scanf("%d %d %d", &n, &x, &y);

	nArr[0] = -1;//초기화

	//배열에 부모 노드 정보를 담는다.
	for (int i = 1; i < n; i++) {
		int pData, cData;
		scanf("%d %d", &pData, &cData);
		nArr[cData] = pData;
	}

	//높이를 저장한다.
	//시간 절약을 위하여
	//나의 부모 노드의 높이에 +1을 더하여 계산한다.
	for (int i = 0; i < n; i++) {
		int idx = i;
		int height = 1;

		if (nArr[idx] != -1) {
			height = hArr[nArr[idx]] + 1;
		}
		else {
			while (nArr[idx] != -1) {
				idx = nArr[idx];
				height = height + 1;
			}
		}
		hArr[i] = height;
	}

	int pNode; //공통 부모 노드
	int xIdx = x;
	int yIdx = y;
	while (1) {
		//인덱스가 같아 공통 부모가 결정되었음에도 
		//상위 노드를 참조하는 것을 막기 위해 먼저 확인한다.
		if (xIdx == yIdx) {
			pNode = xIdx;
			break;
		}
		else if (nArr[xIdx] == nArr[yIdx]) {
			//종료
			pNode = nArr[xIdx];
			break;
		}
		else {
			if (hArr[xIdx] > hArr[yIdx]) {
				xIdx = nArr[xIdx];
			}
			else if (hArr[xIdx] < hArr[yIdx]) {
				yIdx = nArr[yIdx];
			}
			else {
				//same
				xIdx = nArr[xIdx];
				yIdx = nArr[yIdx];
			}
		}
	}

	//printf("공통 조상 : %d\n", pNode);
	if (pNode == -1) pNode = 0;//0의 부모를 -1로 설정하였으므로 재처리
	int leftVal = hArr[x] - hArr[pNode];
	int rightVal = hArr[y] - hArr[pNode];
	int answer = leftVal + rightVal;
	printf("%d", answer);

	return 0;
}