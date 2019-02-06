//문제 : 계차수열을 활용하기

#include <stdio.h>

#include <iostream>

using namespace std;

#define LENGTH 1000000

int main() {



  

  //Please Enter Your Code Here

  int index = 1;

  int start = 0;

  int end = 0;

  int ap = 6;

  int n;

  bool state = false;

  cin >> n;

  

  while(true){

    if(n == 1){

      cout << 1;

      break;

    }

    start = 2 + ((index-1) * ((2*ap + (index-2)*6))) / 2;

    end = start + (ap * index) - 1;

    

    //cout << start << ' ' << end << endl;

    

    for(int i = start; i <= end; i++){

      if(i == n){

        cout << index + 1;

        state = true;

        break;

      }

    }

    if(state) break;

    index++;

  }

  return 0;

}