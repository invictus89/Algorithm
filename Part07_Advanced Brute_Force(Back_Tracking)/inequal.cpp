//문제 : inequal
//<>(부등호)를 입력받아 적용 가능한 숫자 출력

//방법1. 모든 경우를 다 배열에 넣고, 조건에 맞는 결과만 출력하기
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
using namespace std;

int K; //부등호 개수
char arrEqual[9]; //부등호 저장 배열
int arrNum[10]; //부등호에 맞는 입력 가능한 배열
bool check[10]; // 중복 제거를 위한 배열
vector<string> answer; //조건에 부합하는 리스트 배열에 저장


bool isPossible(){
  for(int i = 0; i < K; i++){
    if(arrEqual[i] == '<'){
      if(arrNum[i] > arrNum[i+1]) return false;
    }else if(arrEqual[i] == '>'){
      if(arrNum[i] < arrNum[i+1]) return false;
    }
  }
  return true;
}
//설계1 무엇을 하는 함수 ? 해당 index에 9~0까지 재귀적으로 출력
//k : 비교할 부등호를 가진 배열의 인덱스
void printNum(int index){
  //설계2. 기저 조건: 주어진 인덱스가 부등호 개수+1과 같을 때 종료
  if(index == K + 1){
    if(isPossible()){
      string str = "";
      for(int i = 0; i < K+1; i++){
        str = str + to_string(arrNum[i]);
      }
      answer.push_back(str); 
    }
  }else{
    //설계3. 재귀함수 구현
    for(int i = 9; i >= 0; i--){
      //반복 피하기
      if(!check[i]){
        arrNum[index] = i;
        check[i] = true;
        printNum(index+1);
        //반복 배열 0으로 초기화
        check[i] = false;
      }
    }
  }
}

int main() {

  //Please Enter Your Code Here
  cin >> K;
  for(int i = 0; i < K; i++){
    cin >> arrEqual[i];
  }
  
  printNum(0);
  cout << answer[0] << endl;
  cout << answer[answer.size()-1] << endl;
  return 0;
}
//=================================================
//방법2(내가 한 방법). 배열에 넣을 때 조건에 맞는 값만 넣기
//장점 : 시간 절약
//단점 : 코드 중복
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
using namespace std;

int K; //부등호 개수
char arrEqual[9]; //부등호 저장 배열
int arrNum[10]; //부등호에 맞는 입력 가능한 배열
bool check[10]; // 중복 제거를 위한 배열
vector<string> answer; //조건에 부합하는 리스트 배열에 저장

//해당 index에 9~0까지 재귀적으로 출력
//k : 비교할 부등호를 가진 배열의 인덱스
void printNum(int index, int k){
  // 기저 조건
  if(index == K + 1){
    string str = "";
    for(int i = 0; i < K+1; i++){
      str = str + to_string(arrNum[i]);
    }
   answer.push_back(str);
  }else{
    for(int i = 9; i >= 0; i--){
      //첫 인덱스의 값은 무조건 삽입
      if(index == 0){
        arrNum[index] = i;
        check[i] = 1;
        printNum(index+1, k);
        check[i] = 0;
      }else if(arrEqual[k] == '>'){
        if(arrNum[index-1] > i && check[i] != 1){
          arrNum[index] = i;
          check[i] = 1;
          printNum(index+1, k+1);
          check[i] = 0;
        }
      }else if(arrEqual[k] == '<' && check[i] != 1){
        if(arrNum[index-1] < i){
          arrNum[index] = i;
          check[i] = 1;
          printNum(index+1, k+1);
          check[i] = 0;
        }
      }
    }
  }
}

int main() {

  //Please Enter Your Code Here
  cin >> K;
  for(int i = 0; i < K; i++){
    cin >> arrEqual[i];
  }
  
  printNum(0, 0);
  cout << answer[0] << endl;
  cout << answer[answer.size()-1] << endl;
  return 0;
}