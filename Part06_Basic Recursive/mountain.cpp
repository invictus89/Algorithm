/*
mountain

문제
봉우리가 여러개인 산 모양을 출력한다. 산 모양은 그림과 같고 좌우 대칭이다.
(그림 - 블로그 참조)

입력
첫 번째 줄에 숫자를 입력 받는다. 숫자의 크기는 20보다 작은 자연수이다.

출력
출력 예의 형식으로 출력한다.
*/

 #include <stdio.h>
#include <iostream>
using namespace std;

void mountain(int n){

  if(n == 1){

    cout << 1;
    return;
  }

  mountain(n-1);
  cout << n;
  mountain(n-1);

}

int main() {

  //Please Enter Your Code Here

  int n;

  cin >> n;

  

  mountain(n);

  //mountain(n);

  

  return 0;

}