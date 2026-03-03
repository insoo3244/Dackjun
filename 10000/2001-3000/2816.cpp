#include <iostream>
#include <string>
#include <vector>

using namespace std;

int cs = 0; // 화살표를 담당하는 전역변수 : 이 값은 가리키는 채널 인덱스 번호를 나타냄
void chUp(vector<string> &v); // 채널 옮기기 함수
void csDown(int channel); // 화살표 옮기기 함수, 인수 : 채널 개수

int main() {
    int ch; // 채널 개수
    cin >> ch;

    vector<string> chList(ch); // 채널 리스트
    for(int i = 0; i < ch; i++){
        cin >> chList[i];
    }
    
    // KBS1 위치 찾기
    int isKBS1 = 0; // KBS1의 현재 채널 순서
    for(int i = 0; i < ch; i++){
        if(chList[i] == "KBS1"){
            isKBS1 = i;
            break;
        }
        csDown(ch); // 화살표 위치와 채널 탐색 수준 일치
    }

    // KBS1 위치 옮기기
    for(int i = isKBS1; i > 0; i--){
        chUp(chList);
    }

    if(chList[1] == "KBS2"){
        return 0;
    }

    // KBS2 위치 찾기
    int isKBS2 = 0; // KBS2의 현재 채널 순서
    for(int i = 0; i < ch; i++){
        if(chList[i] == "KBS2"){
            isKBS2 = i;
            break;
        }
        csDown(ch);
    }

    // KBS2 위치 옮기기
    for(int i = isKBS2; i > 1; i--){
        chUp(chList);
    }
}

void chUp(vector<string> &v1) {
    string temp;
    temp = v1[cs];
    v1[cs] = v1[cs - 1];
    v1[cs - 1] = temp;

    if(cs > 0) cs--; // 채널 위치를 옮기면서 커서도 같이 옮기기
    
    cout << "4";
}

void csDown(int channel){
    if(cs >= channel) { return; }

    cs++;
    cout << "1";
}