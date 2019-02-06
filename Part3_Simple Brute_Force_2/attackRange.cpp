//문제 : 면적 합 구하기
//도형마다 값을 채워나간다. 완전 탐색하며 값이 0이 아닌 배열에 닿으면 카운트를 1증가시킨다.

#include <stdio.h>

#include <iostream>

#include <limits.h>

#include <math.h>

using namespace std;

#define SIZE 100

int main() {



  //Please Enter Your Code Here

  int x1, y1, x2, y2;

  int i1, j1, i2, j2;

  int maxValue = INT_MIN;

  int arr[100][100] = {0};

  int count = 0;



  for(int n = 0; n < 4; n++){

    cin >> x1 >> y1 >> x2 >> y2;

    i1 = (SIZE - 1) - y1;

    j1= x1;

    i2 = (SIZE -1) - (y2 - 1);

    j2 = x2 - 1;

    

    //cout << i1 << ' ' << j1 << ' ' << i2 << ' ' << j2 << endl;

    

    for(int t = i2; t <= i1; t++){

      for(int k = j1; k <= j2; k++ ){

        arr[t][k] = n + 1;

      }

    }

  }

  

  /*

  for(int i = 0; i < SIZE; i++){

    for(int j = 0; j < SIZE; j++){

      cout << arr[i][j] << ' ';

    }

    cout << endl;

  }

  */

    

  for(int i = 0; i < SIZE; i++){

    for(int j = 0; j < SIZE; j++){

      if(arr[i][j] != 0) count++;

    }

  }

  

  cout << count << endl;

  

  return 0;

}