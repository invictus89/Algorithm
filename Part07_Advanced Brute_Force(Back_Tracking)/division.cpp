//문제 : division
//임의의 자연수를 그 보다 작은 자연수들의 합으로 표현하기

#include <stdio.h>
#include <iostream>
using namespace std;
int N;
int arr[20];
int count;

//설계1. 뭐하는 함수? sum을 고려하여 배열의 i 인덱스에 n이하의 값을 넣는 재귀함수
void getSum(int n, int i, int sum){
  //설계2. 기저 조건 : 합이 N이 되면 종료
 if(sum >= N){
   count++;
   for(int j = 0; j < i; j++){
     cout << arr[j];
     if(j != i-1) cout << '+';
   }
   cout << endl;
   //설계3. 실제 재귀 함수 구현
 }else{
   for(int j = n; j >= 1; j--){
     if(sum + j <= N){
       arr[i] = j;
       getSum(j, i+1, sum + j);
     }
   }
 }
  
}
int main() {

  //Please Enter Your Code Here
  cin >> N;
  getSum(N-1, 0, 0);
  cout << count;
  return 0;
}