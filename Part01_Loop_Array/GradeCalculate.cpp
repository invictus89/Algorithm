/*
문제 : 점수 계산
*/
#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
  //Please Enter Your Code Here

  int arr[101];
  int n;
  int sum;
  cin >> n;

  for(int i = 0; i < n; i++) cin >> arr[i];

  for(int i = 0; i < n; i++){
    if(arr[i] == 1) {
      sum++;
      int j = i;
      while(i != 0 && arr[j-1] == 1){
        sum++;
        j--;
      }
    }
  }
  cout << sum;
  return 0;
}