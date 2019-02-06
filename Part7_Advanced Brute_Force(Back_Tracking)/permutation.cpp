#include <stdio.h>
#include <iostream>
using namespace std;
#define SIZE 26

int N;
int R;
bool nextLine = false;
char arr[SIZE];
char arr2[SIZE];
//중복을 배제하기 위한 중복체크 배열
char check[SIZE];


//설계1. 해당 재귀는 index에 arr 알파벳을 저장한다. 
void printChar(int index, int r){
  //설계2. 기저 조건 : 인덱스가 R(두 자리수)과 같으면 재귀 종료 및 배열 출력
  if(index >= R){
    if(nextLine) cout << endl;
    nextLine = true;
    for(int i = 0; i < index+1; i++){
      cout << arr2[i];
    }
    return;
  //설계3. 구체적 재귀 함수 구현 
  }else{
    //아직 채워넣을 수 있는 자리수가 있을 때만 진행
    if(r > 0){ 
      //각 자리마다 0부터 N까지의 값을 넣는다.
      for(int i = 0; i < N; i++){
        if(check[i] != 0) continue;
        else{
          check[i] = 1;
          arr2[index] = arr[i];
          printChar(index + 1, r - 1);
          //돌아오면 반드시 0으로 초기화
          check[i] = 0;
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