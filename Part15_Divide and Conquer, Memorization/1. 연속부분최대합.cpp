문제
N개의 정수가 주어질 때, 연속된 부분을 선택하여 합을 최대화 하는 프로그램을 작성하시오. 예를 들어, 아래와 같이 8개의 숫자가 있을 경우, 색칠된 부분을 선택했을 때 그 합이 가장 최대가 된다.
 

입력
첫 번째 줄에 n이 주어진다. ( 1 ≤ n ≤ 100,000 ) 두 번째 줄에 n개의 정수가 주어진다. 

출력
연속된 부분을 선택하였을 때의 최댓값을 출력한다.

예제 입력
8
2 3 -5 8 -3 4 2 -9
예제 출력
11 

예제 입력
5
-1 -2 3 -2 4
예제 출력
5

#include <stdio.h>
#include <iostream>
#include <limits.h>
using namespace std;
const int MAX = 100010;

int arr[MAX];

int getMaxSum(int start, int end){
  //start - end까지 연속부분 최대합을 구하는 재귀함수
  
  if(start >= end) return arr[start]; // 기저조건
  
  int mid = (start + end) / 2;
  int left = getMaxSum(start, mid); //왼쪽 최대합
  int right = getMaxSum(mid+1, end); //오른쪽 최대합
  
  //mid부터 시작한 left
  int leftSum = 0;
  int leftMax = INT_MIN;
  for(int i = mid; i >= start; i--){
    leftSum += arr[i];
    leftMax = max(leftMax, leftSum);
  }
  //mid부터 시작한 right
  int rightSum = 0;
  int rightMax = INT_MIN;
  for(int i = mid+1; i <= end; i++){
    rightSum += arr[i];
    rightMax = max(rightMax, rightSum);
  }
  
  int myMax = leftMax + rightMax;
  
  int answer = INT_MIN;
  answer = max(left, right);
  answer = max(answer, myMax);
  //printf("s:%d, e:%d, lm:%d, rm:%d, max:%d\n", start, end, leftMax, rightMax, answer);
  return answer;
}

int main() {

  //Please Enter Your Code Here
  int N;
  scanf("%d", &N);
  for(int i = 0; i < N; i++) scanf("%d", &arr[i]);
  
  int answer = getMaxSum(0, N-1);
  printf("%d", answer);
  return 0;
} 