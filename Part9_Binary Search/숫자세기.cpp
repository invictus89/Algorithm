/*
문제
n개의 숫자가 주어지고, q개의 질문이 주어진다. 각각의 질문은 n개의 숫자 중에서 특정 숫자가 몇개나 있는지를 묻는다. 
q개의 질문에 모두 답하는 프로그램을 작성하시오.


입력
첫 번째 줄에 숫자의 개수 n, 그리고 질문의 개수 q가 주어진다 ( 1 ≤ n ≤ 100,000, 1 ≤ q ≤ 100,000) 두 번째 줄에 n개의 숫자가 주어진다. 
세 번째 줄에 q개의 질문이 주어진다. 주어지는 q개의 질문은 모두 1000이하이다.

출력
각 질문에 대하여 숫자의 개수를 한 줄에 하나씩 출력한다.

예제 입력
10 4
1 3 4 3 2 3 1 2 5 10
1 3 9 10
예제 출력
2
3
0
1
*/

#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int n, q, target;

int countNum(int arr[], int index, int target){
  //원소의 값이 일치할 때 왼쪽 루프와 오른쪽 루프를 돌며
  //같은 수의 개수를 세어 반환한다.
  
  int cur_pos = index;
  int count = 0;
  
  //index부터 0까지
  while(cur_pos >= 0){
    if(arr[cur_pos--] == target) count++;
    else break;
  }
  
  //index부터 마지막 원소까지
  //! index는 이미 위의 루프에서 한 번 포함시켰기 때문에
  //나중에 count 리턴시 -1을 해준다.
  cur_pos = index;
  while(cur_pos <= n-1){
    if(arr[cur_pos++] == target) count++;
    else break;
  }
  return count-1;
}
int binarySearch(int arr[], int start, int end, int target){
  //arr배열 start에서 end까지 target의 개수를 반환한다. 
  //없으면 0을 반환한다.
  
  //printf("s: %d, e: %d\n", start, end);
  if(start > end) return 0;
  else if(start == end){
    if(arr[start] == target) return countNum(arr, start, target);
    else return 0;
  }else{
    int mid = (start + end) / 2;
    if(arr[mid] == target) return countNum(arr, mid, target);
    else if(arr[mid] > target) return binarySearch(arr, start, mid-1, target);
    else return binarySearch(arr, mid+1, end, target);
  }
}
int main() {

  //Please Enter Your Code Here
  int arr[100000];
  scanf("%d %d", &n ,&q);
  
  for(int i = 0; i < n; i++)
    cin >> arr[i];
    
  sort(arr, arr+n);
  // for(int i = 0; i < n; i++)
  //   cout << arr[i] << ' ';
  // cout << endl;
  
  for(int i = 0; i < q; i++){
    cin >> target;
    int count = binarySearch(arr, 0, n-1, target);
    printf("%d\n", count);
  }
  
  return 0;
}