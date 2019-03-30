/*
문제
루트가 0인 이진트리가 주어질 때, 이를 전위순회, 중위순회, 후위순회한 결과를 각각 출력하는 프로그램을 작성하시오. 

입력
첫 번째 줄에 트리의 노드 개수 n이 주어진다. ( 1 ≤ n ≤ 100 ) 
두 번째 줄부터 트리의 정보가 주어진다. 각 줄은 3개의 숫자 a, b, c로 이루어지며, 
그 의미는 노드 a의 왼쪽 자식노드가 b, 오른쪽 자식노드가 c라는 뜻이다. 
자식노드가 존재하지 않을 경우에는 -1이 주어진다.

출력
첫 번째 줄에 전위순회, 두 번째 줄에 중위순회, 세 번째 줄에 후위순회를 한 결과를 출력한다.
 
예제 입력
6
0 1 2
1 3 4
2 -1 5
3 -1 -1
4 -1 -1
5 -1 -1

예제 출력
0 1 3 4 2 5
3 1 4 0 2 5
3 4 1 5 2 0
*/


#include <stdio.h>
#include <iostream>
using namespace std;

const int MAX = 100;

struct Tree{
  int left;
  int right;
};

Tree tree[MAX];

void preorder(int x){
  //x를 root로 하는 트리의 전위순회하는 함수
  
  if(tree[x].left == -1 && tree[x].right == -1){
    printf("%d ", x);
  }else{
    printf("%d ", x);
    if(tree[x].left != -1) preorder(tree[x].left);
    if(tree[x].right != -1) preorder(tree[x].right);
  }
}

void inorder(int x){
  if(tree[x].left == -1 && tree[x].right == -1){
    printf("%d ", x);
  }else{
    if(tree[x].left != -1) inorder(tree[x].left);
    printf("%d ", x);
    if(tree[x].right != -1) inorder(tree[x].right);
  }
}

void postorder(int x){
  if(tree[x].left == -1 && tree[x].right == -1){
    printf("%d ", x);
  }else{
    if(tree[x].left != -1) postorder(tree[x].left);
    if(tree[x].right != -1) postorder(tree[x].right);
    printf("%d ", x);
  }
}
int main() {

  //Please Enter Your Code Here
  int N;
  int a, b, c;
  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    scanf("%d %d %d", &a, &b, &c);
    tree[a].left = b;
    tree[a].right = c;
  } 
  
  preorder(0);
  cout << endl;
  inorder(0);
  cout << endl;
  postorder(0);
  
  return 0;
}