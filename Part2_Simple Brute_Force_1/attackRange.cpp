/*
문제 : attackrange
*/

[1차 풀이 : 전 범위를 탐색하기때문에 비효율]

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main() {

  //Please Enter Your Code Here
  int n;
  string arr[100][100];
  int x, y, r;
  int dx[] = {1, 0, -1, 0};
  int dy[] = {0, 1, 0, -1};
  cin >> n;
  cin >> x >> y >> r;
  string find = "x";



  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      arr[i][j] = "0";
    }
  }
   
  arr[x-1][y-1] = "x";

  for(int k = 0; k < r; k++){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if(arr[i][j] == find){
          for(int s = 0; s < 4; s++){
            int nx = i + dx[s];
            int ny = j + dy[s];
            //arr[nx][ny] == "0" 검사가 먼저 오면 오류난다!
            //따라서 무조건 배열 범위를 초과하는지 부터 검사해야 한다!!
            if(nx >= 0 && nx < n && ny >= 0 && ny < n && arr[nx][ny] == "0") arr[nx][ny] = to_string(k+1);
          }
        }
      }
    }
    find = to_string(k+1);
   }

  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cout << arr[i][j] <<' ';
    }
    cout << endl;
  }
  return 0;
}

[2차 풀이 : 'x'표시로부터 해당 유효거리 이내만 측정]

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int abs(int num){
  if(num < 0) num = -num;
  return num;
}

int main() {
  string arr[100][100];
  int n;
  cin >> n;
  int x, y, r;
  cin >> x >> y >> r;
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      int distance = abs(i - (x - 1)) + abs(j - (y - 1));
      if(distance <= r){
        arr[i][j] = to_string(distance);
      }else{
        arr[i][j] = "0";
        continue;
      }
    }
  }
  arr[x-1][y-1] = "x";
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cout << arr[i][j] << ' ';
    }
    cout << endl;
  }
  
  return 0;
}