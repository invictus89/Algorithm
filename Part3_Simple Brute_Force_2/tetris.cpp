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