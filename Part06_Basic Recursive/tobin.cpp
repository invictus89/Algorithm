/*
TOBIN
문제
두 정수 n, k를 입력받아 k개의 1을 가진 n자리 이진 패턴을 출력하는 프로그램을 작성하세요.

입력
두 정수 n,k가 입력으로 주어진다. ( 0< n <= 30, 0 <= k < 8 , n>=k )

출력
결과를 내림차순으로 출력한다.
*/

//주의 : 0은 과연 언제 배열에 넣어야 하나?

#include <stdio.h>
#include <iostream>
using namespace std;
int N;
int R;
int arr[30];
void tobin(int index, int r){
  //기저
  if(index >= N){
    if(r == R){
      for(int i = 0; i < N; i++){
        cout << arr[i];
      }
      cout << endl;
    }
    return;
  }
  //커팅1
  if(r > R) return;
  
  //1
  arr[index] = 1;
  tobin(index+1, r+1);
  
  //0
  arr[index] = 0;
  tobin(index+1, r);
}
int main() {

  //Please Enter Your Code Here
  cin >> N >> R;
  tobin(0, 0);
  return 0;
}
