/*
문제 : offset
*/
#include <stdio.h>

#include <iostream>

using namespace std;





int main() {



  //Please Enter Your Code Here

  

  bool okStar = true;

  char arr[5][5];

  for(int i = 0; i < 5; i++){

    for(int j = 0; j < 5; j++){

      cin >> arr[i][j];

    }

  }

  for(int i = 0; i < 5; i++){

    for(int j = 0; j < 5; j++){

      okStar = true;

      if(i-1 >= 0){

        if(arr[i][j] >= arr[i-1][j]) okStar = false;

      }

      if(i+1 < 5){

        if(arr[i][j] >= arr[i+1][j]) okStar = false;

      }

      if(j-1 >= 0){

        if(arr[i][j] >= arr[i][j-1]) okStar = false;

      }

      if(j+1 < 5){

        if(arr[i][j] >= arr[i][j+1]) okStar = false;

      }

      if(okStar == true) arr[i][j] = '*';

    }

  }

  

    for(int i = 0; i < 5; i++){

      for(int j = 0; j < 5; j++){

        cout << arr[i][j] << ' ';

    }

    cout << endl;

  }

  

  return 0;

}
