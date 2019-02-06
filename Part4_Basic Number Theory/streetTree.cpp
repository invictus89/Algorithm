// 문제 : streetTree
// 가로수의 위치가 주어질 때 가로수의 최소개수를 출력하라

#include <stdio.h>

#include <iostream>

using namespace std;



long fGcd(long num1, long num2){

  if(num1 % num2 == 0) return num2;

  else return fGcd(num2, num1 % num2);

}



int main() {

  int arr[100000];

  //Please Enter Your Code Here

  int n;

  cin >> n;

  for(int i = 0; i < n; i++)

    cin >> arr[i];

  

  int preValue = arr[1] - arr[0];

  int curValue = 0;

  for(int i = 1; i < n; i++){

    int curValue = arr[i] - arr[i-1];

    preValue = (preValue < curValue) ? fGcd(curValue, preValue) : fGcd(preValue, curValue);

    //cout << curValue << ' ' << preValue << endl;

  }

  

  

  int count = 0;

  for(int i = 1; i < n; i++){

    count += ((arr[i] - arr[i-1]) / preValue) - 1;

  }

  

  cout << count;

  return 0;

}