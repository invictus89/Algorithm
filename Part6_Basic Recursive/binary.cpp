/*
문제
숫자를 입력 받아 이진수로 출력하는 프로그램을 작성하시오.

입력
첫 번째 줄에 숫자를 입력 받는다. 숫자의 크기는 1,000보다 작거나 같다.

출력
첫째 줄에 숫자를 이진수로 바꾸어 출력한다.

예제 입력
14
예제 출력
1110
=================================
접근법
1. n의 이진수는 n/2의 몫의 이진수에다가 나머지를 붙여 계산하게 된다.
2. getBinary(n)은 n의 이진수를 반환하는 함수이다.
3. 기저 조건은 n == 0 이면 0, n == 1이면 1을 리턴
4. f(n)은 f(n-1) 하고 n % 2를 print한다.
*/

#include <stdio.h>
#include <iostream>
using namespace std;
void printBinary(int n){
  if(n == 1){
    cout << 1;
  }else{
    printBinary(n/2);
    cout << n%2;
  }
}
int main() {

  //Please Enter Your Code Here
  int n;
  cin >> n;
  printBinary(n);
  return 0;
}