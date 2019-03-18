//문제 : 빙고

[2차 방법(강사 도움) - 행/열/대각선 데이터 관리 배열 사용]

#include <stdio.h>

#include <iostream>

using namespace std;

#define SIZE 5

int print(int arr[][SIZE]){

  for(int i = 0; i < SIZE; i++){

    for(int j = 0; j < SIZE; j++){

      cout << arr[i][j] << ' ';

    }

    cout << endl;

  }

}

//행 검사

int checkRow(int arr[], int len, int i, int num){

  arr[i]++;

  //cout << "row : " << arr[i] << endl;

  if(arr[i] == 5) return ++num;

  else return num;

}

//열 검사

int checkCol(int arr[], int len, int j, int num){

  arr[j]++;

 // cout << "col : " << arr[j] << endl;

  if(arr[j] == 5) return ++num;

  else return num;

}

//대각선 검사

int checkDia(int arr[], int len, int i, int j, int num){

  if(i == j){

    arr[0]++;

   // cout << "dia1 : " << arr[0] << endl;



    if(arr[0] == 5) num++;

  }

  if(i + j == len - 1){

    arr[1]++;

    //cout << "dia2 : " << arr[1] << endl;



    if(arr[1] == 5) num++;

  }

  return num;

}



int main() {



  //Please Enter Your Code Here

  //내 배열

  int arr1[SIZE][SIZE];

  //사회자 배열

  int arr2[SIZE][SIZE];

  //입력

  for(int i = 0; i < SIZE; i++){

    for(int j = 0; j < SIZE; j++){

      cin >> arr1[i][j];

    }

  }

  

  for(int i = 0; i < SIZE; i++){

    for(int j = 0; j < SIZE; j++){

      cin >> arr2[i][j];

    }

  }

  

  int row[SIZE] = {0};//행관리 배열

  int col[SIZE] = {0};//열관리 배열

  int dia[2] = {0};//대각선 관리 배열

  int totalNum = 0;//총 빙고 수

  int count = 0;//총 카운트 수

  

  for(int i = 0; i < SIZE; i++){

    for(int j = 0; j < SIZE; j++){

      count++;

      for(int i2 = 0; i2 < SIZE; i2++){

        for(int j2 = 0; j2 < SIZE; j2++){

          if(arr2[i][j] == arr1[i2][j2]){

            totalNum = checkRow(row, SIZE, i2, totalNum);

            totalNum = checkCol(col, SIZE, j2, totalNum);

            totalNum = checkDia(dia, SIZE, i2, j2, totalNum);

          }

          if(totalNum >= 3){

            cout << count << endl;

            return 0;

          }

        }

      }

    }

  }

  

  return 0;

}



[1차 방법(혼자) - 배열 없이 루프 돌며 카운트 셈] 


#include <iostream>

#include <stdio.h>

using namespace std;



#define SIZE 5

int numBingo(int arr[][SIZE], int x, int y);

void print(int arr[][SIZE]);



int main()

{



	int my_arr[SIZE][SIZE] = { 0 };

	int your_arr[SIZE][SIZE] = { 0 };

	int totalBingo = 0;

	int answer = 0;



	for (int i = 0; i < 5; i++) {

		for (int j = 0; j < 5; j++) {

			cin >> my_arr[i][j];

		}

	}



	for (int i = 0; i < 5; i++) {

		for (int j = 0; j < 5; j++) {

			cin >> your_arr[i][j];

		}

	}



	for (int i = 0; i < SIZE; i++) {

		for (int j = 0; j < SIZE; j++) {

			int checkValue = your_arr[i][j];

			answer++;

			for (int x = 0; x < SIZE; x++) {

				for (int y = 0; y < SIZE; y++) {

					if (my_arr[x][y] == checkValue) {

						my_arr[x][y] = 0;

						totalBingo += numBingo(my_arr, x, y);

						if (totalBingo >= 3) {

						  //print(my_arr);

							cout << answer << endl;

							return 0;

						}

					}

				}

			}

		}

	}

	return 0;

}



int numBingo(int arr[][SIZE], int x, int y) {

	int numX = 0, numY = 0, numC1 = 0, numC2 = 0;

	int total = 0;



	//가로

	for (int i = 0; i < SIZE; i++) {

		if (arr[x][i] == 0) numX++;

		if (arr[i][y] == 0) numY++;

	}



	//대각선1

	if(x == y){

	  for(int i = 0; i < SIZE; i++){

	    if(arr[i][i] == 0) numC1++;

	  }

	}

	//대각선2

	if((x+y) == SIZE - 1){

	  for(int i = 0; i < SIZE; i++){

	    if(arr[i][(SIZE-1) - i] == 0) numC2++;

	  }

	}

	

	if (numX == SIZE) total++;

	if (numY == SIZE) total++;

	if (numC1 == SIZE) total++;

	if (numC2 == SIZE) total++;



	return total;

}



void print(int arr[][SIZE]) {

	for (int i = 0; i < SIZE; i++) {

		for (int j = 0; j < SIZE; j++) {

			cout << arr[i][j] << ' ';

		}

		cout << endl;

	}

}