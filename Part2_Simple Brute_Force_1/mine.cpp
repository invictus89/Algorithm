//문제 : mine
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

  





  /*

  for(int i = 0; i < n; i ++){

    for(int j = 0; j < m; j++){

      cout << arr[i][j] << ' ';

    }

    cout << endl;

  }

  */

  

  return 0;

}