//문제 : 등차수열과 등비수열 구하기
//수정 필요 : 등차수열과 등비수열의 특징을 이용하여 구현할 것
#include <stdio.h>

#include <iostream>

using namespace std;



int main() {



  //Please Enter Your Code Here

  int a1, a2, a3;

  int value;

  int gp;

  int ap;

  string str;

  while(1){

    cin >> a1 >> a2 >> a3;

    //종료

    if(a1 == 0 && a2 == 0 && a3 ==0) break;

    //등비 or 등차

    else{

       //case1 : 등차

      if(a3 - a2 == a2 - a1){

        ap = a2 - a1;

        cout << "AP" << ' ' << a3 + ap << endl;



        //str = "ap " + (a3 + ap);

      }

      //case2 : 등비

      else if((a3 / a2 == a2 / a1) && (a3 % a2 == a2 % a1)){

        gp = a2 / a1;

        cout << "GP" << ' ' << a3 * gp << endl;

        //str = "gp " + (a3 * gp);

      }

     

     // cout << str << endl;

    }

    //출력

  }

  return 0;

}