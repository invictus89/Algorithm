#include <stdio.h>
#include <iostream>
using namespace std;
const int MAX = 7;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};


int main() {

  //Please Enter Your Code Here
  int arr[MAX][MAX];
  
  for(int i = 0; i < MAX; i++){
    for(int j = 0; j < MAX; j++){
      arr[i][j] = 10;
    }
  }
  
   for(int i = 1; i < MAX-1; i++){
    for(int j = 1; j < MAX-1; j++){
      scanf("%d", &arr[i][j]);
    }
  }
  
  for(int i = 1; i < MAX-1; i++){
    for(int j = 1; j < MAX-1; j++){
      bool check = true;
      for(int k = 0; k < 4; k++){
        int nx = i + dx[k];
        int ny = j + dy[k];
        
        if(arr[i][j] < arr[nx][ny]){
          check = true;
        }else{
          check = false;
          break;
        }
      }
      if(check == true){
        printf("%c ", '*');
      }else{
        printf("%d ", arr[i][j]);
      }
      
    }
    printf("\n");
  }
  
  return 0;
}
