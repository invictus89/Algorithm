#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int MAX = 110;

//         1
//     2       3
//   4   5   6   7
// 8   3

struct priorityQueue{
  int arr[MAX] = {0};
  int len = 1;

  void push(int x){
    arr[len++] = x;
    int idx = len-1;

    while(idx > 1){ 
      if(arr[idx] < arr[idx/2]){
        swap(arr[idx], arr[idx/2]);
        idx = idx/2;
      }else{
        break;
      }
    }
  }

//         1
//     2       3
//   4   5   6   7
// 8   3
  void pop(){
    swap(arr[1], arr[len-1]);
    arr[len-1] = 0;
    len--;
    //1. 자식 노드 left와 right 중 우선순위가 작은 친구를 파악한다.
    //  1-1. 자식 노드가 없을 경우
    //  1-2. 자식 노드가 왼쪽에만 있을 경우
    //  1-3. 자식 노드가 둘 다 있을 경우
    //  1-4. 자식 노드가 오른쪽에만 있을 경우
    //    * 완전 이진트리가 1-4의 경우는 존재하지 않는다.
    int idx = 1;
    int cIdx = -1; //자식 노드의 index
    while(1){
      if(len <= idx*2) break;
      else if(1 <= idx*2 && idx*2 < len && idx*2+1 >= len){
        if(arr[idx] > arr[idx*2]) {
          cIdx = idx*2;
        }
      }else{
        if(arr[idx*2] > arr[idx*2+1]){
          cIdx = idx*2+1;
        }else{
          cIdx = idx*2;
        }
      }
      //2. 만약 현재 노드의 우선순위가 자식 노드의 우선순위보다
      //작으면 두개를 바꾼다. 그렇지 않으면 그냥 종료
      swap(arr[idx], arr[cIdx]);
      idx = cIdx;
    }
  
  }
  int top(){
    return arr[1];
  }

};
int main(){
  priorityQueue myQue;
  myQue.push(5);
  myQue.push(3);
  myQue.push(1);
  myQue.push(20);
  myQue.push(30);
  
  cout << myQue.top() << endl; // 1
  myQue.pop();
  cout << myQue.top() << endl; // 3
  myQue.pop();
  cout << myQue.top() << endl; // 5
  
  
  return 0;
}