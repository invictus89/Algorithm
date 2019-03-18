//문제 : PROSJEK
// - 특정 정수 수열 A가 있다. 특정 항까지의 평균값을 그 항으로 하는 수열 B가 주어질 때, A 수열 구하기

//재귀적 방법을 통해 수정해볼 것
#include <stdio.h>

#include <iostream>

using namespace std;

int main() {

  int arrA[100];

  int arrB[100];

  //Please Enter Your Code Here

  int n;

  cin >> n;

  for(int i = 0; i < n; i++){

    cin >> arrB[i];

  }

  arrA[0] = arrB[0];

  cout << arrB[0] << ' ';

  for(int i = 1; i < n; i++){

    arrA[i] = (arrB[i] * (i+1)) - (arrB[i-1] * i);

    cout << arrA[i] << ' ';

  }

  

  return 0;

}

//an = bn * n - b(n-1)*(n-1);

//bn = (a1+a2+---+an) / n;

//bn = b(n-1)*(n-1) + an / n;