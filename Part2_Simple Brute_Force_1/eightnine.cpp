//문제 : eightnine
#include <stdio.h>
#include <iostream>
using namespace std;
int main() {

  //Please Enter Your Code Here
  int n, m;
  cin >> n >> m;
  int arr[101][101];
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> arr[i][j];
    }
  }
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j <= (m-1) / 2; j++){
      swap(arr[i][j], arr[i][(m-1)-j]);
    }
  }
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cout << arr[i][j] << ' ';
    }
    cout << endl;
  }
  
  return 0;
}