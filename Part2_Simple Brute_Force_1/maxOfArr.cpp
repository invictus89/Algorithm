//문제 : maxOfArr
#include <stdio.h>

#include <iostream>

#include <limits.h>

using namespace std;

int main() {



  //Please Enter Your Code Here

  int arr[9][9];

  //입력

  for(int i = 0;i <9; i++){

    for(int j = 0; j < 9; j++){

      cin >> arr[i][j];

    }

  }

  

  //완전 탐색

  int maxValue = INT_MIN;

  int maxIndexX;

  int maxIndexY;

  

  for(int i = 0; i < 9; i++){

    for(int j = 0; j < 9; j++){

      //if(maxValue == arr[i][j]) continue;

      if(maxValue < arr[i][j]){

        maxValue = arr[i][j];

        maxIndexX = i + 1;

        maxIndexY = j + 1;

      }

    }

  }

  

  printf("%d\n%d %d", maxValue, maxIndexX, maxIndexY);

  

  return 0;

}