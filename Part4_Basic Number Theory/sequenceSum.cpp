//문제 : sequence sum
// - N개의 양의 정수를 가지는 수열 A가 있었다. 수열 자체를 알지는 못하지만 수열의 두 요소의 합은 알 수 있다. 수열 A를 찾아라!
//1차 시도 : 점수 60점, 이유 못 찾음

#include <stdio.h>
#include <iostream>
using namespace std;
#define SIZE 1000-3+1


  int sArr[SIZE][SIZE];
  int aArr[SIZE];

int main() {
  
  //Please Enter Your Code Here
  int n;
  cin >> n;
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> sArr[i][j];
    }
  }
  //0과 n 제외
  //An = S(n, n+1) + s(n-1, n) s(n, n+1)
  for(int i = 1; i < n - 1; i++){
    aArr[i] = (sArr[i][i+1] + sArr[i-1][i] - sArr[i-1][i+1]) / 2;
  }
 
  aArr[0] = sArr[0][1] - aArr[1];
  aArr[n - 1] = sArr[n - 2][n - 1] - aArr[n - 2];
  
  for(int i = 0;i < n; i++){
    cout << aArr[i] << ' ';
  }
 
  return 0;
}