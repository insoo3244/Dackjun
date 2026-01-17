// https://www.acmicpc.net/problem/2667
// 2026-01-17
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool arr[25][25]; // 단지 크기
bool vis[25][25]; // 방문 체크

// 탐색 방향 지정 배열
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

vector<int> vec; // aCnt 저장 배열 (탐색 후, 단지 내 집 수 저장하기)
int aCnt = 0; // 총 단지 수
int hCnt = 0; // 단지 내 집 수

void DFS(int y, int x, int n){
    if((x < 0 || x >= n) || (y < 0 || y >= n)) 
        {return;}
    if(arr[y][x] == 0 || vis[y][x]) 
        {return;}

    vis[y][x] = 1;
    aCnt++; // 집 수 연산

    // 방향 별 탐색 시작
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if((nx < 0 || nx >= n) || (ny < 0 || ny >= n))
            {continue;}
        if(arr[ny][nx] == 0 || vis[ny][nx]) 
            {continue;}

        DFS(ny, nx, n);
    }
}

int main(){
    // 단지 크기 입력
    int n;
    cin >> n;

    // 단지 내 집 위치 입력
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) {
            char w;
            cin >> w;
            int num = w - '0';
            arr[i][j] = num;
        }
    }

    // 탐색 시작
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == 1 && !vis[i][j]){ // 집 유무 구분 및 방문 체크
                DFS(i, j, n); // 영역 하나 탐색

                // 한 영역 탐색 후
                hCnt++; // 영역 수 연산
                vec.push_back(aCnt); // vec에 집 수 저장
                aCnt = 0; // 집 수 초기화
            }
        }
    }

    // 출력
    cout << hCnt << '\n'; 
    sort(vec.begin(), vec.end()); // 오름차순 정렬
    for(auto x : vec) cout << x << '\n';
}