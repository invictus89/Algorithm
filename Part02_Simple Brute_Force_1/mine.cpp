//문제 : mine



//Second Solution
#include <stdio.h>
#include <iostream>
using namespace std;
const int MAX = 110;

int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, -1, 1, 1, -1};
int arr[MAX][MAX];
int N, M;
int X, Y;

int main() {

  //Please Enter Your Code Here
  scanf("%d %d %d %d", &N, &M, &X, &Y);
  
  for(int i = 0; i < N+2; i++){
    for(int j = 0; j < M+2; j++){
      arr[i][j] = 9;
    }
  }
  
  for(int i = 1; i < N+1; i++){
    for(int j = 1; j < M+1; j++){
      scanf("%d", &arr[i][j]);
    }
  }
  
  int count = 0;
  
  if(arr[X][Y] == 1){
    printf("game over");
    return 0;
  }else{
    for(int i = 0; i < 8; i++){
      int nx = X + dx[i];
      int ny = Y + dy[i];
      
      if(arr[nx][ny] == 1) count++;
    }
  }
  printf("%d", count);
  return 0;
}
//Frist Solution
#include <stdio.h>

#include <iostream>

using namespace std;

int main() {



  //Please Enter Your Code Here

  int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};

  int dy[] = {0, 1, 0, -1, -1, 1, 1, -1}; 

  int n, m, x, y;

  int arr[100][100];

  int count = 0;

  cin >> n >> m >> x >> y;

  

  for(int i = 0; i < n; i ++){

    for(int j = 0; j < m; j++){

      cin >> arr[i][j];

    }

  }


  if(arr[x-1][y-1] == 1){

    cout << "game over" << endl;

  }else{

    for(int i = 0; i < 8; i++){

      int nx = (x-1) + dx[i];

      int ny = (y-1) + dy[i];

      if(arr[nx][ny] == 1) count++;

    }  

     cout << count << endl;
  }

  return 0;

}

