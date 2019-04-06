/*
문제
n과 m이 주어질 때, n^m을 구하는 프로그램을 작성하시오. 
단, n^m의 값이 커질 수 있기 때문에, 정답을 10,007 으로 나눈 나머지를 출력한다.

입력
첫 번째 줄에 숫자 n과 m이 주어진다. ( 1 ≤ n ≤ 100, 1 ≤ m ≤ 1,000,000,000,000,000,000 )  

출력
첫째 줄에 nm을 10,007 으로 나눈 나머지를 출력한다.

예제 입력
3 4
예제 출력
81
*/

#include <stdio.h>
#include <iostream>
#include <limits.h>
using namespace std;
const int STD = 10007;
long long getPow(int a, long long b){
  if(b == 0){
    return 1;
  }else if(b % 2 == 0){
    long long temp = getPow(a, b/2);
    if(temp > STD) temp = temp % STD;
    return temp * temp;
  }else{
    long long temp = getPow(a, (b-1)/2);
    if(temp > STD) temp = temp % STD;
    return a * temp * temp;
  }
}

int main() {
  int n;
  long long m;
  
  cin >> n >> m;
  
  cout << getPow(n, m) % STD;
  
}