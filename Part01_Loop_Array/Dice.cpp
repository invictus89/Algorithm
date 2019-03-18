/*
문제 : 숫자 주사위
*/
#include <stdio.h>
#include <iostream>
using namespace std;
int main() {
 
  //Please Enter Your Code Here
  int n;
  int incrX = 2;
  int incrY = 1;
  int startNumX = 1;
  cin >> n;
  for(int i = 0; i < n; i++){
    int num = startNumX;
    int incrY = 1;
    for(int j = 0; j < n; j++){
      cout << num;
      num += incrY;
      incrY++;
    }
    startNumX += incrX;
    incrX++;
    cout << endl;
  }
  return 0;
}