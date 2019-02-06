/*
문제 : 상자 색칠
*/

#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {

  //Please Enter Your Code Here
  bool okDraw = true;
  int arr[1001] = {0};
  int input;
  int count = 0;
  int oneCount = 0;
  int n;
  cin >> n;
  
  for(int i = 0; i < n; i++){
    cin >> input;
    arr[input]++;
  }
  
  if(n < 6) {
    okDraw = false;
  }else{
    for(int i = 0; i < n; i++){
      if(arr[i] != 0) count++;
      if(arr[i] == 1) oneCount++;
    }
    if(count < 3) {
      okDraw = false;
    }else if(count == 3){
      if(oneCount >= 1) okDraw = false;
    }else if(count == 4){
      if(oneCount >= 3) okDraw = false;
    }
  }
  
  if(okDraw) cout << "YES";
  else cout << "NO";
  
  
  return 0;
}