/*
순열구하기
문제
서로 다른 n개의 원소들 중에서 r개만을 뽑아 일렬로 나열하는 것을 순열이라 한다. 예를 들어, 3개의 원소 a, b, c 중에서 2개만을 뽑아 나열하면 ab, ac, ba, bc, ca, cb 의 6가지 경우가 있다. n과 r이 주어질 때, n개의 소문자 중에서 r개만을 뽑아 나열하는 모든 경우를 출력하는 프로그램을 작성하시오. 단, a부터 시작하여 연속으로 n개의 알파벳을 갖고 있다고 하자.  

입력
첫 번째 줄에 n과 r이 주어진다. ( 1 ≤ n ≤ 26, 1 ≤ r ≤ n )  

출력
각 줄에 n개의 소문자 중에서 r개만을 뽑아 나열하는 경우를 사전순으로 나열한 결과를 출력한다.
*/

//코칭 후 해결('19.01.20)
//설계
//1. 해당 재귀는 주어진 index에 알파벳을 배열에 저장한다. 
//2. Basic Condition : 해당 index가 2가 되면 배열을 출력
//3. 구체적 재귀함수 정의 : 
//  3-1. 넣을 수 있는 개수(r)이 0이상일 때 각 자리마다 0에서 N까지의 값을 배열에 넣는다.
//  3-2. 주어진 index의 배열 값은 0 ~ index-1의 배열 값과 중복되서는 안된다. 이를 위해 check배열을 사용한다.
//  3-3. 이미 넣은 값은 check배열에 1을, return 시 0으로 초기화 해준다.


#include <stdio.h>
#include <iostream>
using namespace std;
#define SIZE 26

int N;
int R;
char arr[SIZE];
char arr2[SIZE];
char check[SIZE];

//해당 재귀는 index에 arr 알파벳을 저장한다. 
void printChar(int index, int r){
  //기저 조건
  if(index >= R){
    for(int i = 0; i < index+1; i++){
      cout << arr2[i];
    }
    cout << endl;
    return;
  // f(n)은 n의 자리에 배열 값을 하나씩 저장하되, f(0) ~ f(n-1)의 값과 중복되서는 안된다.
  }else{
    if(r > 0){
      for(int i = 0; i < N; i++){
        if(check[i] != 0) continue;
        else{
          check[i] = 1;
          arr2[index] = arr[i];
          printChar(index + 1, r - 1);
        }
        //index가 0일때만 초기화해준다.
        if(index == 0){
          for(int i = 0; i < N; i++) check[i] = 0;
        }
      }
    }  
  }
}
 
int main() {
  //처음은 무조건 'a'
  arr[0] = 'a';
  cin >> N >> R;

  for(int i = 1; i < N; i++){
    arr[i] = arr[i-1] + 1;
  }

  printChar(0, R);

  return 0;
}