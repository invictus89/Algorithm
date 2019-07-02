# 단순 재귀함수 활용 문제

## 문제



## 특징

- 배열을 돌며 모든 경우의 수를 고려하여 합을 구하는 문제

- 단지, 그 합을 이루는 원소개 개수가 2개로 한정되어 있음

- 재귀를 돌며 자기 자신의 원소는 포함하되 이전 원소는 되돌아 갈 필요는 없다.  따라서 아래 코드 추가

  ```C++
   // 재귀를 돌며 이전 값을 포함시키지 않기 위해 사용
   if(index == 1){
   	if(my_list[0].idx > i) continue;
   }
  ```

  

## 풀이

```c++
#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <math.h>
using namespace std;
const int LEN = 2;
const int INPUT_LEN = 3;
bool check[INPUT_LEN];

struct Mine{
  int idx;
  int val;
};

int given_arr[INPUT_LEN];
int answer = INT_MIN;
Mine my_list[LEN];

void getMax(int len, int index){
  if(index >= len){
    // for(int i = 0; i < 2; i++){
    //   printf("%d ", my_list[i].val);
    // }
    // printf("\n");
    int sum = my_list[0].val + my_list[1].val + abs(my_list[0].idx - my_list[1].idx);
    answer = max(answer, sum);
  }else{
    for(int i = 0; i < INPUT_LEN; i++){
      // 재귀를 돌며 이전 값을 포함시키지 않기 위해 사용
      if(index == 1){
        if(my_list[0].idx > i) continue;
      }
      my_list[index] = Mine({i, given_arr[i]});
      getMax(len, index+1);
    }
  }
}

int main(){
  for(int i = 0; i < INPUT_LEN; i++){
    cin >> given_arr[i];
  }

  getMax(LEN, 0);
  printf("%d", answer);
  
  return 0;
}
```

