//문제 : 달팽이 배열 채우기
//루프 대신 재귀함수를 사용하여 풀어 볼 것  

#include <stdio.h>

#include <iostream>

using namespace std;

int main() {

  int c, r, k;

  cin >> c >> r >> k;

  int arr[1000][1000];

  int num = 1;

  int directionX = -1;

  int directionY = 1;

  int posX = r;

  int posY = 0;

  int roofX = r;

  int roofY = c - 1;

  bool result = false;

  

  while(1){

    

     for(int i = 0; i < roofX; i++){

        posX = posX + directionX;

        arr[posX][posY] = num;

        if(num == k) {result = true; break;}

        num++;

      }

      roofX--;

      directionX = -directionX;

    if(roofY == 0 || result == true) break;

  

    for(int i = 0; i < roofY; i++){

      posY = posY + directionY;

      arr[posX][posY] = num;

      if(num == k) {result = true; break;}

      num++;

    }

    roofY--;

    directionY = -directionY;

    if(roofX == 0 || result == true) break;

  }

  //cout << "posX : " << posX << ' ' << "PosY : " << posY << endl;

  if(result == 0) cout << 0 << endl;

  else cout << posY + 1 << " " << r - posX << endl;



  

  return 0;

}