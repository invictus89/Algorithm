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

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
using namespace std;

int N;
int LEN;
int count;
string sign[3] = {"+", "-", "."};
string arr[30];
vector<string> v;

//0인지 check
bool check(){
  bool isZero = false;
  long long sum = stoll(v[0]);
  for(int i = 0; i < v.size(); i++){
    if(v[i] == "+"){
      sum = sum + stoll(v[i+1]);
    }else if(v[i] == "-"){
      sum = sum - stoll(v[i+1]);
    }
  } 
  
  if(sum == 0){
    isZero = true;
    count++;
  }
  
  return isZero;
}

void createVector(){
   for(int i = 0; i < LEN; i++){
     if(arr[i] == "."){
       string temp = v.back() + arr[i+1];
       v.pop_back();
       v.push_back(temp);
     }else{
       if(arr[i-1] == ".") continue;
       v.push_back(arr[i]); 
     }
   }
}

void printDessert(int index, int plusNum, int minusNum, int pointNum){
  //기저조건
  if(index >= LEN){
    
    if(plusNum == N-1 || minusNum == N-1 || pointNum == N-1) 
      return;
      
    createVector();
    
    if(v.size() > 3){
      if(check() == 1){
        if(count <= 20){
          for(int i = 0; i < LEN; i++){
            cout << arr[i] << ' ';
          }
          cout << endl;
        }
      }
    }
    v.clear();
   return;
  //반복 함수 구현 
  }else{
    for(int i = 0; i < 3; i++){
      arr[index] = sign[i];
      if(sign[i] == "+") printDessert(index+2, plusNum+1, minusNum, pointNum);
      if(sign[i] == "-") printDessert(index+2, plusNum, minusNum+1, pointNum);
      if(sign[i] == ".") printDessert(index+2, plusNum, minusNum, pointNum+1);
    }
  }
}

int main() {
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