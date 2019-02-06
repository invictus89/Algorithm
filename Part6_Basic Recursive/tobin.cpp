/*
TOBIN
문제
두 정수 n, k를 입력받아 k개의 1을 가진 n자리 이진 패턴을 출력하는 프로그램을 작성하세요.

입력
두 정수 n,k가 입력으로 주어진다. ( 0< n <= 30, 0 <= k < 8 , n>=k )

출력
결과를 내림차순으로 출력한다.
*/


#include <stdio.h>

#include <iostream>

using namespace std;



int arr[30];

int N, K;





void recursive(int n, int k, int index){

  //출력

  if(index >= N){

    for(int i = 0; i < N; i++){

      cout << arr[i];

    }

    cout << endl;

    return; //재귀 종료

  }

  

  //1의 값 배열에 넣기

  if(k > 0){

    arr[index] = 1;

    recursive(n-1, k-1, index + 1);

  }

  

  //0의 값 배열에 넣기

  if(n - k > 0){

    arr[index] = 0;

    recursive(n-1, k, index + 1);  

  }

}



int main() {



  //Please Enter Your Code Here

  cin >> N >> K;

  //매개변수 : n, k, index

  recursive(N, K, 0);

  return 0;

}