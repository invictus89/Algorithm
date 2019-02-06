/*

문제 : 숫자 피라미드

*/

 #include <stdio.h>

#include <iostream>



using namespace std;



  //Please Enter Your Code Her



int main() {

  int n, s;

  cin >> n >> s;

  

  for(int i = 0; i < n; i++){

    for(int j = 0; j < n - i - 1; j++) cout << ' ';

    int size = i * 2 + 1;

    int arr[size];

    for(int j = 0; j < size; j++){

      arr[j] = s++;

      if(s == 10) s = 1;

    }

    if(i % 2 == 0)

      for(int j = size - 1; j >= 0; j--) cout << arr[j];

    else 

      for(int j = 0; j < size; j++) cout << arr[j];

    cout << endl;

  }

  return 0;

}
