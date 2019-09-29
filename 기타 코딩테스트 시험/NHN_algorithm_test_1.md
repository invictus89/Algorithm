# NHN 코딩 테스트

## 문제
12
enqueue 1
enqueue 2
enqueue 2
enqueue 1
enqueue 2
dequeue
dequeue
dequeue
dequeue
dequeue
enqueue 7
dequeue

2 1 2 1 2 7



## 풀이

```c++
#include <iostream>
#include <limits.h>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
const int LEN = 102;

struct Point{
	int pVal;
	int pCnt;
	vector<int> pOrder;
};

Point qArr[LEN];
char orderList[LEN][LEN];

int main() {
							
	int n;
  	scanf("%d", &n);
    
    //위의 n 입력시 마지막 \n 때문에 
    //만약 입력버퍼를 지워주지 않으면 아래의 fgets 처음 시작 시 \n만 하나 들어가게 된다.
	while(getchar() != '\n');								 
	for(int i = 0; i < n; i++){
		fgets(orderList[i], 100, stdin); //fgets는 띄어쓰기, 개행문자도 다 입력 받는다.
	}
	
  int idx = 0;							 
	for(int i = 0; i < n; i++){
		string temp = string(orderList[i]);
		string qa = temp.substr(0, 7);
        
        // qArr에 넣기
		if(qa == "enqueue"){
			int val = stoi(temp.substr(temp.find(' ')+1, temp.size()));		
			if(idx == 0) {qArr[idx++] = Point({val, 1, {0}}); continue; }
			bool isInserted = false;
            
            //만약 기존에 있는 val이라면 cnt만 증가
            //그리고 그게 몇번째 인덱스 인지 백터에 추가
			for(int j = 0; j < idx; j++){
				if(qArr[j].pVal == val){
					qArr[j].pCnt++;
					qArr[j].pOrder.push_back(i);
					isInserted = true;
					break;
				}
			}
			if(isInserted == false){
				qArr[idx++] = Point({val, 1, {i}});
			}
		}
		
        // 출력시
		if(qa == "dequeue"){
			int maxIdx = 0;
			for(int j = 0; j < idx; j++){
				if(qArr[j].pCnt < qArr[j+1].pCnt) maxIdx = j+1; //cnt 최대값 설정
                
                //만약cnt가 동일하다면 
                //pOrder의 인덱스가 -1이 아닌 곳의 값 비교
                //이게 작은 것이 가장 먼저 나온 입력 값이다.
				if(qArr[j].pCnt == qArr[j+1].pCnt){
					int firstEariest, secondEariest;
					for(int k = 0; k < qArr[j].pOrder.size(); k++){
						if(qArr[j].pOrder[k] >= 0){
							firstEariest = k;
							break;
						}
					}
					for(int k = 0; k < qArr[j+1].pOrder.size(); k++){
						if(qArr[j+1].pOrder[k] >= 0){
							secondEariest = k;
							break;
						}
					}
					if(firstEariest <= secondEariest) maxIdx = j;
					else maxIdx = j+1;
				}
			}
			//출력할때 pOrder 값 하나 -1로 지워주고
            //pCnt도 -1 해주고
			if(qArr[maxIdx].pCnt != 0){
				for(int j = 0; j < qArr[maxIdx].pOrder.size(); j++){
					if(qArr[maxIdx].pOrder[j] >= 0){
						qArr[maxIdx].pOrder[j] = -1;
						qArr[maxIdx].pCnt--;
						break;
					}
				}
				cout << qArr[maxIdx].pVal << endl;
			}
       
		}
	}
	return 0;
}
```

