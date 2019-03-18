#include <iostream>
using namespace std;

int N;
int count;
int maxCount;
int arr[10];
int check[10];

void saveCount(int index, int count){
  //basic condition
  if(index == N){
    return;
  //recursive processing
  }else{
    if(arr[index] < N){
      if(check[index] == 0){
        cout << arr[index] << ' ';
        check[index] = 1;
        saveCount(arr[index], count+1);
      }else{
        cout << endl;
        maxCount = max(maxCount, count);
      }
    }else{
      cout << endl;
      return;
    }
  }
}

int main(){
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> arr[i];
  }
  
  for(int i = 0; i < N; i++){
    saveCount(i, 0);
  }
  cout << "max : " << maxCount << endl;
 
}