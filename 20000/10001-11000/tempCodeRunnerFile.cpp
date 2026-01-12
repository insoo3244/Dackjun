// https://www.acmicpc.net/problem/10026
// 2026-01-12
#include <iostream>
#include <string>
#include <vector>

using namespace std;

char greed[101][101]; // 모눈종이 최대 크기
int vis[101][101]; // 방문 체크

// 탐색 방향 지정 배열
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

// RGB 별 화소 유무 
bool Rtemp = 0; 
bool Gtemp = 0; 
bool Btemp = 0; 

void Rfind(int x, int y, int n){
    if(y < 0 || y > n) return; // y 범위 체크
    if(x < 0 || x > n) return; // x 범위 체크
    if(vis[y][x] == 1) return; // 방문 체크
    if(greed[y][x] != 'R') return; // 방문 체크

    vis[y][x] = 1; // 방문 확인

    // 양 옆으로 탐색
    for(int i = 0; i < 4; i++){
        Rfind(x + dx[i], y + dy[i], n);
    }

    Rtemp = 1;
}

void Gfind(int x, int y, int n){
    if(y < 0 || y > n) return; // y 범위 체크
    if(x < 0 || x > n) return; // x 범위 체크
    if(vis[y][x] == 1) return; // 방문 체크
    if(greed[y][x] != 'G') return; // 방문 체크

    vis[y][x] = 1; // 방문 확인

    // 양 옆으로 탐색
    for(int i = 0; i < 4; i++){
        Gfind(x + dx[i], y + dy[i], n);
    }

    Gtemp = 1;
}

void Bfind(int x, int y, int n){
    if(y < 0 || y > n) return; // y 범위 체크
    if(x < 0 || x > n) return; // x 범위 체크
    if(vis[y][x] == 1) return; // 방문 체크
    if(greed[y][x] != 'B') return; // 방문 체크

    vis[y][x] = 1; // 방문 확인

    // 양 옆으로 탐색
    for(int i = 0; i < 4; i++){
        Bfind(x + dx[i], y + dy[i], n);
    }

    Btemp = 1;
}

int main(){
    // graph, vis 초기화
    for(int i = 0; i < 101; i++){
        for(int j = 0; j < 101; j++){
            greed[i][j] = ' ';
            vis[i][j] = 0;
        }
    }

    int n; // 그리드 크기
    cin >> n;
    
    // 그리드 정보 입력
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char c; // R, G, B?
            cin >> c;

            greed[i][j] = c;
        }
    }

    // 내 그래프 현황 출력
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << greed[i][j];
    //     }
    //     cout << endl;
    // }
    
    // 그리드 탐색
    // RGB 영역 개수
    int Rcnt = 0;
    int Gcnt = 0;
    int Bcnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            Rtemp = 0;
            Gtemp = 0;
            Btemp = 0;

            Rfind(i, j, n);
            Gfind(i, j, n);
            Bfind(i, j, n);

            if(Rtemp != 0) { Rcnt++; }
            if(Gtemp != 0) { Gcnt++; }
            if(Btemp != 0) { Bcnt++; }
        }
    }

    // 영역 개수 출력
    cout << Rcnt + Gcnt + Bcnt << " " << Rcnt + Bcnt;
}