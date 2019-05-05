/*

출력
처음 20줄에 대해 가능한 20가지 답을 출력하는데, 사전 순으로 앞선 것을 출력한다. 순서는 +가 가장 앞서고 -와 . 이 순서대로 뒤따른다. 답이 20개 미만이면 가능한 답을 각 숫자와 문자 사이에 공백을 두고 출력한다. 모두 출력한다. 마지막 줄에는 가능한 답의 총 가지수를 출력한다.


예제 입력
7
예제 출력
1 + 2 - 3 + 4 - 5 - 6 + 7
1 + 2 - 3 - 4 + 5 + 6 - 7
1 - 2 + 3 + 4 - 5 + 6 - 7
1 - 2 - 3 - 4 - 5 + 6 + 7 
1 - 2 . 3 + 4 + 5 + 6 + 7 
1 - 2 . 3 - 4 . 5 + 6 . 7
6

*/

#include <iostream>
#include <stdio.h>
using namespace std;

int N, count;
char signKind[3] = {'+', '-', '.'};
char signs[20];
int nums[20];

//합을 구하는 함수
int sumCheck(){
  // '.'이 처음 나온 것인지 아닌지 구별하는 변수
  // 이전 결과 값을 이어서 계산해야 하는데
  // 만약 '.'이 처음나오면 그 결과 값이 없기에 '.'인덱스 값의 숫자를 대입한다.
  bool fDup = true; 

  //'.'이 연속하여 나올 때 이전 값을 저장하여 새로운 값을 구하기 위한 변수
  int midVal = 1;
  int sum = nums[0]; //최종 합을 저장할 변수
  int flag = 0; // 1('+'), 2('-')

  //처음에 계산하기 위한 로직
  if(signs[0] == '+') flag = 1;
  if(signs[0] == '-') flag = 2;

  for(int i = 0; i <= N-2; i++){
    if(signs[i] == '+' && signs[i+1] != '.'){ 
      sum = sum + nums[i+1];
      flag = 1;
    }else if(signs[i] == '+' && signs[i+1] == '.'){
      flag = 1; //flag가 0이 되어 계산이 안됨을 방지
    }

    if(signs[i] == '-' && signs[i+1] != '.'){
      sum = sum - nums[i+1];
      flag = 2;
    }else if(signs[i] == '-' && signs[i+1] == '.'){
      flag = 2; //flag가 0이 되어 계산이 안됨을 방지
    }

    if(signs[i] == '.'){
      int tenNum = 1;
      if(nums[i+1] < 10) tenNum = 10 * 1;
      else tenNum = 10 * 10;
        
      //'.'이 연달아 나올 때
      if(signs[i+1] == '.'){
        if(fDup == true){
          midVal = nums[i];
        }
        midVal = midVal * tenNum + nums[i+1];
        fDup = false; //'.'이 다음에도 나올 것임을 보임
      //'.'이 다음 요소에서 종료됨
      }else{
        if(fDup == true){ //'.'이 처음이라면 배열의 값으로 세팅
          midVal = nums[i];
        }
        midVal = midVal * tenNum + nums[i+1];
        if(flag == 1){
          sum = sum + midVal;
        }
        if(flag == 2){
          sum = sum - midVal;
        }
        if(flag == 0){
          sum = midVal;
        }
        midVal = 1;
        fDup = true;
      }
    }
  }
  return sum;
}

//idx에 +, -, .을 넣어 요구사항에 맞게 계산 후
//합이 0인 배열을 출력하는 재귀함수
void dessert(int idx){
  if(N == 1) return; //숫자 입력이 한개
  if(idx >= N-1){
    //합 체크
    int val = sumCheck();
    if(val == 0){
      count++;
      if(count <= 20){
        for(int i = 0; i < N; i++){
          printf("%d ", nums[i]);
          if(i < N-1) printf("%c ", signs[i]);
        }
        printf("\n");
        
      }
    }
    return;
  }
  
  //재귀 구현
  for(int i = 0; i < 3; i++){
    signs[idx] = signKind[i];
    dessert(idx+1);
  }
}

int main(){
  scanf("%d", &N);
  int data = 1;
  for(int i = 0; i < N; i++){
    nums[i] = data++;
  }

  dessert(0);
  printf("%d\n", count);
  return 0;
}
  cin >> N;
  LEN = N + (N-1);
  int temp = 1;
  
  for(int i = 0; i < LEN; i++){
    if(i%2 == 0){
      arr[i] = to_string(temp++);
    }
  }

  printDessert(1, 0, 0, 0);
  cout << count;
  
  return 0;
}