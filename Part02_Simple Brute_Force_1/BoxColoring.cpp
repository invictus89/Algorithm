/*
한 색깔 당 사용가능한 횟수와 그 합을 생각해 볼 것

*/

//두번째 푼 방법
#include <stdio.h>
#include <iostream>
using namespace std;
const int MAX = 1010;

int N;
int arr[MAX];
int cnt[MAX];

int main() {
  scanf("%d", &N);
  for(int i = 0; i < N; i++) scanf("%d", &arr[i]);
  
  for(int i = 0; i < N; i++){
    if((++cnt[arr[i]]) >= 2) cnt[arr[i]] = 2; 
  }

  int countZeroNot = 0;
  int sum = 0;
  for(int i = 0; i < N; i++){
    sum += cnt[i];
    if(cnt[arr[i]] != 0) countZeroNot++;
  }
  
  if(countZeroNot >= 3 && sum >= 6) {
    printf("YES");
    return 0;
  }
  
  printf("NO");
  
  return 0;
}

//첫번째 푼 방법
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {

  //Please Enter Your Code Here
  bool okDraw = true;
  int arr[1001] = {0};
  int input;
  int count = 0;
  int oneCount = 0;
  int n;
  cin >> n;
  
  for(int i = 0; i < n; i++){
    cin >> input;
    arr[input]++;
  }
  
  if(n < 6) {
    okDraw = false;
  }else{
    for(int i = 0; i < n; i++){
      if(arr[i] != 0) count++;
      if(arr[i] == 1) oneCount++;
    }
    if(count < 3) {
      okDraw = false;
    }else if(count == 3){
      if(oneCount >= 1) okDraw = false;
    }else if(count == 4){
      if(oneCount >= 3) okDraw = false;
    }
  }
  
  if(okDraw) cout << "YES";
  else cout << "NO";
  
  
  return 0;
}
