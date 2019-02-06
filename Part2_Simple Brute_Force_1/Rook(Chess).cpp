/*
문제 : 체스의 룩 기능 구현하기
*/

#include <stdio.h>
#include <iostream>
using namespace std;
int main() {

  //Please Enter Your Code Here
  int arr[8][8];
  int locLookX;
  int locLookY;
  int locKingX;
  int locKingY;
  bool okKill = false;
  
  //데이터 입력
  //룩과 킹 위치 찾기
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      cin >> arr[i][j];
      if(arr[i][j] == 2){
        locLookX = i;
        locLookY = j;
      }
      if(arr[i][j] == 1){
        locKingX = i;
        locKingY = j;
      }
    }
  }
 
  int k, t; // for문 탐색을 위한 값
  //x축에 킹과 룩이 있을 때
  if((locKingX - locLookX) == 0){
    if(locKingY < locLookY){
      k = locKingY; 
      t = locLookY;
    }else{
      k = locLookY;
      t = locKingY;
    }
    //0과 1, 2가 아닌 값은 false로 리턴
    for(int i = k; i <= t; i++){
      okKill = false;
      if(arr[locKingX][i] != 0 && arr[locKingX][i] != 1 && arr[locKingX][i] != 2) break; 
      else okKill = true;
    }  
  }
  //y축에 킹과 룩이 있을 때
  if((locKingY - locLookY) == 0){
    if(locKingX < locLookX){
      k = locKingX; 
      t = locLookX;
    }else{
      k = locLookX;
      t = locKingX;
    }
    for(int i = k; i <= t; i++){
      okKill = false;
      if(arr[i][locKingY] != 0 && arr[i][locKingY] != 1 && arr[i][locKingY] != 2 ) break;
      else okKill = true;
    }  
  }
  if(okKill) cout << 1;
  else cout << 0;
  return 0;
  
}