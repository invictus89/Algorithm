//���� : ��Ʈ����
/*
�߰� ���� �ʿ�
��� 1) ��� ���� Ž���� �ʿ� ���� ���� ���� ���� ������ ���� ���� ���̴�.
��� 2) ����ó�� �� ��� ���� �����Ͽ� ������ ����
*/

//�� ������ Ž���Ͽ� ������ ��� : ��ȿ����  
#include <stdio.h>
#include <iostream>
#include <stdio.h>
using namespace std;

void print(int arr[][20], int x, int y){
  for(int i = 0; i < x; i++){
    for(int j = 0; j < y; j++){
      cout << arr[i][j] << ' ';
    }
    cout << endl;
  }
}
int main() {

  //Please Enter Your Code Here
  int arr[20][20];
  int c, r;
  //r : ����, C : ����
  cin >> r >> c;
  
  //�Է�
  for(int i = 0; i < c; i++){
    for(int j = 0; j < r; j++){
      cin >> arr[i][j];
    }
  }
  
  //��� �׽�Ʈ
  //print(arr, r, c);
  
  //���η� Ž��
  int answerArr[c] = {0};
  int sum = 0;
  for(int i = 0; i < c; i++){
    for(int j = 0; j < r; j++){
      //1 �O��
      if(arr[j][i] == 1 || (arr[j][i] == 0 && j == c - 1)){
        //���� ����
        //printf("1�� ��ġ[j, i] : %d, %d\n", j, i);
        if(j <= 3) {
          break;
        }
        else{
          int k = (arr[j][i] == 0 && j == c - 1) ? j : j - 1;
          for(k; k >= (j-1)-3; k--){
            sum = 0;
            for(int t = 0; t < r; t++){
              if(t != i) sum += arr[k][t];
            }
            if(sum == (r-1)){
              //cout << "j�� ��ġ : " << k << endl;
              answerArr[i]++;
            }
          }
        }
        break;
      }
    }
  }
  int answerA = 0;
  int answerB = 0;
  for(int i = 0; i < r; i++){
    //cout << answerArr[i] << ' ';
    if(answerArr[i] != 0){
      answerA = i + 1; 
      answerB = answerArr[i];
    }
  }
  //cout << endl;
  cout << answerA << ' ' << answerB << endl;
  return 0;
}


/////////////////////////////////////////////
2��° - 190708

#include <iostream>
#include <stdio.h>
#include <limits.h>
using namespace std;
const int LEN = 22;

int colCheck[LEN];
int rowCheck[LEN];
int arr[LEN][LEN];

int main(){
  int answer_index = 0;
  int answer_nums = 0;
  int c, r;
  scanf("%d %d", &c, &r);
  for(int i = 0; i <= r+1; i++){
    for(int j = 0; j <= c+1; j++){
      arr[i][j] = 9;
    }
  }  
  for(int i = 1; i <= r; i++){
    for(int j = 1; j <= c; j++){
      scanf("%d", &arr[i][j]);
    }
  }  

  for(int i = 1; i <= c; i++){
    int count = 0;
    for(int j = r; j >= 1; j--){
      if(arr[j][i] == 0) count++;
      if(count >= 4){
        colCheck[i] = true;
        break;
      }
    }
  }

  for(int i = 1; i <= c; i++){
    if(colCheck[i] == false) continue;
    int zeroX;
    for(int j = r; j >= 1; j--){
      if(arr[j][i] == 0) {
        zeroX = j;
        break;
      }
    }
    for(int k = 0; k < 4; k++){
      arr[zeroX-k][i] = 1;
    }

    cout << "===========" << endl;
    for(int q = 1; q <= r; q++){
      for(int j = 1; j <= c; j++){
        cout << arr[q][j] << ' ';
      }
      cout << endl;
    }
    cout << "===========" << endl;

    int temp_nums = 0;
    for(int k = zeroX; k >= 1; k--){
      int count = 0;
      for(int t = 1; t <= c; t++){
        if(arr[k][t] == 1) count++;
      }
      if(count == c) temp_nums++;
    }
    cout << "temp_nums : " << temp_nums << endl;

    if(answer_nums < temp_nums){
      answer_nums = temp_nums;
      answer_index = i;
    }

    for(int k = 0; k < 4; k++){
      arr[zeroX-k][i] = 0;
    }

  }

  cout << answer_index << ' ' << answer_nums << endl;

  return 0;
}