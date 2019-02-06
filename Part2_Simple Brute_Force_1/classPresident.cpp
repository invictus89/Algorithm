//문제 : classPresident
//수정 요망 : 재귀적 방법을 통해 다시 구현해 볼것('19.02.06)

#include <stdio.h>

#include <iostream>

#include <limits.h>

using namespace std;

int main() {

 

  //Please Enter Your Code Here

  int arr[1000][5];

  int arrSameClass[1000][5] = {0};

  int n;

  cin >> n;

  for(int i = 0; i < n; i++){

    for(int j = 0; j < 5; j++){

      cin >> arr[i][j];

    }

  }

  

 

  for(int i = 0; i < 5; i++){

    for(int j = 0; j < n; j++){

      for(int k = j + 1; k < n; k++){

        bool isDup = false;

        if(arr[j][i] == arr[k][i]){

          for(int t = 0; t < i; t++){

            if(arr[j][t] == arr[k][t] && i != 0) {isDup = true; break;} 

            else isDup = false;

          }

          if(!isDup){

            arrSameClass[j][i]++;

            arrSameClass[k][i]++;  

          }

          

        }

      }

    }

  }

 

  int maxSum = INT_MIN;

  int maxIndex = 0;

  int sum = 0;

  

  for(int i = 0; i < n; i++){

    sum = 0;

    for(int j = 0; j < 5; j++){

      sum += arrSameClass[i][j];

    }

    if(maxSum < sum){

      maxSum = sum;

      maxIndex = i + 1;

    }

  }

  

  cout << maxIndex << endl;

  

  return 0;

}