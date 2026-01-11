#include <iostream>
using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    //a = 현재 시각, b = 임무 시작 시각
    int h = (a[0] - '0') * 10 + (a[1] - '0');
    int m = (a[3] - '0') * 10 + (a[4] - '0');
    int s = (a[6] - '0') * 10 + (a[7] - '0');
    int eh = (b[0] - '0') * 10 + (b[1] - '0');
    int em = (b[3] - '0') * 10 + (b[4] - '0');
    int es = (b[6] - '0') * 10 + (b[7] - '0');
    int dh, dm, ds;
    int c = 0;
    // h,m,s = 현재 시각의 시, 분, 초를 int로 받아냄
    // eh,em,es = 임무 시작 시각의 시, 분, 초를 int로 받아냄
    // dh, dm, ds = 남은 시각을 담아내는 변수
    // c = 내림 체크 ex) 00:01:27 - 00:00:46 = 00:00:41 -> 분에서 내림

    if(s <= es){
        ds = es - s; 
    }
    else{
        ds = es + 60 - s;
        c++; //c 활성화
    }
    //ds 계산 및 내림 체크

    if(c != 0){
        em--; //분 내림
        c = 0; //c 초기화
        if(m <= em){
            dm = em - m;
        }
        else{
            dm = em + 60 - m;
            c++; //c 활성화
        }
    }
    else{
        if(m <= em){
            dm = em - m;
        }
        else{
            dm = em + 60 - m;
            c++; //c 활성화
        }
    }
    //내림에 의한 분 계산 고려 및 dm 계산

    if(c != 0){
        eh--; //시간 내림
        if(h <= eh){
            dh = eh - h;
        }
        else{
            dh = eh + 24 - h;
        }
    }
    else{
        if(h <= eh){
            dh = eh - h;
        }
        else{
            dh = eh + 24 - h;
        }
    }
    //내림에 의한 시간 계산 고려 및 dh 계산
 
    int arr[8];
    arr[0] = dh / 10;
    arr[1] = dh % 10;
    arr[3] = dm / 10;
    arr[4] = dm % 10;
    arr[6] = ds / 10;
    arr[7] = ds % 10;
    //arr = 남은 시간을 'XX:XX:XX' 꼴에 맞추어 출력하기 위한 배열
    //인덱스 하나하나 정성스럽게 시간 담아버리기~ 이거말곤 방법이 안떠오름 ㅋㅋ 다른 방법이 있나요?(진짜 모름)
    //2, 5번 인덱스에는 ':'을 출력할 것

    for(int i = 0; i < 8; i++){
        if(i == 2 || i == 5){
            cout << ":";
        }
        else{
            cout << arr[i];
        }
    }
    //출력 반복문
}