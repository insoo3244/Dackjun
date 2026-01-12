// https://www.acmicpc.net/problem/2583
// 2026-01-11
#include <iostream>
#include <vector>
#include <algorithm>
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

using namespace std;

int graph[101][101]; // 모눈종이 최대 크기
int vis[101][101]; // 방문 체크
int cnt = 0;

vector<int> vec; // 빈 영역 별 넓이 저장하기
int temp = 0; // 빈 영역의 넓이

void find(int x, int y, int m, int n){
    if(y < 1 || y > m) return; // y 범위 체크
    if(x < 1 || x > n) return; // x 범위 체크
    if(vis[y][x] == 1) return; // 방문 체크
    if(graph[y][x] == 1) return; // 빈 영역 체크

    vis[y][x] = 1; // 방문 확인

    // 양 옆으로 탐색
    for(int i = 0; i < 4; i++){
        find(x + dx[i], y + dy[i], m, n);
    }
    // insoo3244 : 이거 개사긴데 ?

    temp++;
}

int main(){
    // graph, vis 초기화
    for(int i = 0; i < 101; i++){
        for(int j = 0; j < 101; j++){
            graph[i][j] = 0;
            vis[i][j] = 0;
        }
    }

    // 모눈종이 크기 및 직사각형 개수 입력
    // m, n : 모눈종이 세로 가로 / k : 모눈 종이 위에 그릴 직사각형 개수
    int m, n, k;
    cin >> m >> n >> k;
    
    // 직사각형 정보 입력
    // xd,y : 직사각형 왼쪽아래 좌표 / xu,y : 오른쪽위 좌표
    int xd, yd, xu, yu; 
    for(int i = 0; i < k; i++){
        cin >> xd >> yd >> xu >> yu;
        for(int j = yd + 1; j <= yu; j++){
            for(int l = xd + 1; l <= xu; l++){
                graph[j][l] = 1;
            }
        }
    }

    // 내 그래프 현황 출력
    // for(int i = m; i > 0; i--){
    //     for(int j = 1; j < n + 1; j++){
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // for(int i = 0; i < m + 1; i++) {
    //     for(int j = 0; j < n + 1; j++) {
    //         cout << i << ", " << j << " ";
    //         cout << graph[i][j];
    //     }
    //     cout << endl;
    // }

    // 탐색 시작
    int bCount = 0; // 빈 칸 개수
    int bACount = 0; // 빈 영역 개수a
    for(int i = 1; i < m + 1; i++){
        for(int j = 1; j < n + 1; j++){
            if(graph[i][j] == 0) bCount++; // 빈 칸 개수 세기
            temp = 0;
            find(j, i, m, n);
            
            // 0을 나누는 경우를 없애기 위한 삼중의문문
            bACount += (temp == 0 ? 0 : 1);

            // temp가 0 이면, find가 조건에 걸려서 종료된 것
            if(temp != 0) vec.push_back(temp);
        }
    }

    // 결과 출력
    cout << bACount << endl;
    sort(vec.begin(), vec.end());
    for(auto x : vec) cout << x << " ";
}