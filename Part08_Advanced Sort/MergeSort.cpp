#include <iostream>
using namespace std;
#define SIZE 100000

void merging(int arr[], int start1, int end1, int start2, int end2){
  //arr함수의 왼쪽(start1 ~ end1)과 오른쪽(start2 ~ end2)까지를
  //합친다.
  
  int temp[SIZE];
  int tempIndex = 0;
  int q = start1;
  int p = start2;
  
  //1 3 4 6   2 5 6 7
  while(q <= end1 && p  <= end2){
    if(arr[q] > arr[p]){
      temp[tempIndex++] = arr[p];
      p++;
    }else{
      temp[tempIndex++] = arr[q];
      q++;
    }
  }
  
  
  if(q > end1){
    //왼쪽 값을 모두 넣어
    //오른쪽 값의 나머지를 배열에 넣는 경우
    for(int i = p; i <= end2; i++){
      temp[tempIndex++] = arr[i];
    }
  }
  
  if(p > end2){
    //오른쪽 값을 먼저 모두 넣어
    //왼쪽 값의 나머지를 배열에 넣는 경우
    for(int i = q; i <= end1; i++){
      temp[tempIndex++] = arr[i];
    }
  }
  
  for(int i = start1; i <= end2; i++){
    //temp배열 값을 arr로 다시 넣기
    arr[i] = temp[i-start1];
  }
  
}
void mergeSort(int arr[], int start, int end){
  //arr배열의 start에서 end까지 합병정렬하는 함수
  
  if(start >= end){
    //기저조건 : start가 end를 넘으면 종료
    return;
  }else{
    //구체적 함수 정의
    
    int mid = (start+end)/2;
    //Ex. start = 2, end = 4
    // 2 3   4
    
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    merging(arr, start, mid, mid+1, end);
    //왼쪽(start~mid)과 오른쪽(mid+1 ~ end)까지를 합친다.
  }
  
}

int main(){
  int arr[SIZE];
  int n;
  cin >> n;
  
  for(int i = 0; i < SIZE; i++){
    cin >> arr[i];
  }
  
  //재귀 호출
  mergeSort(arr, 0, n-1);
  
  for(int i = 0; i < n; i++){
    cout << arr[i] << ' ';
  }
  
}
