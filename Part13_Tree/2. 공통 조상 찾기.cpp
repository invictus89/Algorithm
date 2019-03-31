//첫번째 나의 생각(시도해 볼 것 - 재귀 연습삼아)
//  이중 배열로 현재 노드의 자식 노드를 저장한다.
//  재귀함수를 이용한다.
//  void recursive(int x, int target)
//    -> x를 부모노드로 하는 노드를 target을 만날 때 까지 탐색한다.
//    -> 만약 7이면 배열에 (0, 2, 6)
//    -> 만약 10이면 배열에 (0, 2, 10)이 저장될 것이다.
//  문제점 : 완전 탐색으로 시간이 오래 걸린다. 

//두번째 방법(코칭 후)
//  일차원 배열에 index는 현재 노드, 값은 그 노드의 부모 노드를 저장한다.
//  이를 이용하면 각 노드의 높이와 루트까지 따라 올라갈 수 있다.

#include <stdio.h>
#include <iostream>
using namespace std;
const int MAX = 1010;
int main() {

  int pArr[MAX];//부모가 저장되어있는 배열
  int hArr[MAX];//높이가 저장되어있는 배열
  int n, x, y;
  scanf("%d %d %d", &n, &x, &y);
  
  pArr[0] = -1; //편의삼아 -1로 지정
  
  //입력 받기
  for(int i = 1; i < n; i++){
    int pData;
    int cData;
    scanf("%d %d", &pData, &cData);
    pArr[cData] = pData;
    
  }
  
  //높이구하기
  for(int i = 0; i < n; i++){
    int height = 1;
    int tempIdx = i;
    while(pArr[tempIdx] != -1){
      height++;
      tempIdx = pArr[tempIdx];
    }
    hArr[i] = height;
  }
  
  int answer;
  int xIdx = x;
  int yIdx = y;
  while(1){
    if(pArr[xIdx] == pArr[yIdx]) {
      answer = pArr[xIdx]; 
      //cout << "case 0 : break" << endl;
      break;
    }
    else{
      if(hArr[xIdx] < hArr[yIdx]){
        //printf("case 1 : hArr[xIdx] < hArr[yIdx]\n");
        yIdx = pArr[yIdx];
      }else if(hArr[xIdx] > hArr[yIdx]){
        //cout << "case 2 : hArr[xIdx] > hArr[yIdx]" << endl;
        xIdx = pArr[xIdx];
      }else{
        //높이가 동일한 경우
        //cout << " case 3 : hArr[xIdx] = hArr[yIdx]" << endl;
        xIdx = pArr[xIdx];
        yIdx = pArr[yIdx];
      } 
    }
  }
  printf("%d\n", answer);
   return 0;
}