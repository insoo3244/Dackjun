#include <iostream>
#include <string>
#include <vector>

using namespace std;

int cs = 0;
void chUp(vector<string> &v);
void csDown();

int main() {
    int ch; // 채널 개수
    cin >> ch;

    vector<string> chList(ch); // 채널 리스트
    for(int i = 0; i < ch; i++){
        cin >> chList[i];
    }
    

    // KBS1 끌어올리기
    int isKBS1 = 0; // KBS1의 현재 채널 순서
    for(int i = 0; i < ch; i++){ // KBS1 채널 순서찾기
        csDown(); // 커서위치와 채널탐색수준 일치시키기
        if(chList[i] == "KBS1"){
            isKBS1 = i;
            break;
        }
    }

    for(int i = isKBS1; ){
        chUp(chList);
    }
    
}

void chUp(vector<string> &v1) {
    string temp;
    temp = v1[cs];
    v1[cs] = v1[cs - 1];
    v1[cs - 1] = temp;
}

void csDown(){
    if(cs >= 4) { return; }
    cs++;
}

/*
채널 개수 입력
채널 이름 입력 -> KBS1, 2 포함
KBS1, 2가 1빠2빠로 편성이 바뀌는 알고리즘 작동

필요한 함수 생각해보기
리모컨 버튼은 이런 기능이있음
화살표 위/아래 조종 -> 채널 선택 / 선택한 채널을 위/아래 채널과 위치바꾸기

필요한 기능
1. 채널 선택하는 기능
2. 채널 위치 바꾸는 기능
3. 1~4번의 버튼을 몇 번 누르는지 카운팅 하고 출력하는 기능
4. KBS1,2 가 1빠2빠로 잘 왔는지 검수하는 기능

알고리즘 순서
1. KBS1을 찾을 때까지 커서를 내리기 (1번 버튼 실행)
2. KBS1이 1번 채널이 될때까지 끌어올리기 (4번 버튼 실행)
3. KBS2 또한 마찬가지로 실행
4. 매 동작마다 리모컨 버튼에 해당되는 번호출력

*/