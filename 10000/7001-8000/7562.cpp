// https://www.acmicpc.net/problem/7562
// 2026-01-20

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int chess[300][300]; // 체스판 크기 겸 방문체크 겸 가중치 연산

// 순서쌍과 큐
queue<pair<int,int>> q; // bfs 이용 큐
queue<pair<int,int>> temp; // 빈 큐

// 탐색 방향 지정 배열
int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};

int BFS(int l, int tar[]){
    while(!q.empty()){
        // 현재 위치 x, y 좌표
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        // 현재 위치가 목표 위치면, 가중치 반환
        if(cx == tar[0] && cy == tar[1]) 
            return chess[cy][cx] - 1;

        for(int i = 0; i < 8; i++){
            // 다음 탐색 위치
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            // 거리 가중치 연산
            if((nx >= 0 && nx < l) && (ny >= 0 && ny < l)){ // 다음 좌표가 범위 내에 있고,
                if(chess[ny][nx] == 0){ // 아직 방문하지 않은 곳이면,
                    q.push({nx, ny}); // 큐 푸쉬
                    chess[ny][nx] = chess[cy][cx] + 1; // 가중치 연산
                }
            }
        }
    }
}

int main(){
    // 테스트 케이스 입력
    int test = 0;
    cin >> test;


    // 시뮬레이션 시작
    for(int i = 0; i < test; i++){
        // 체스판 크기 입력
        int l;
        cin >> l;

        // 나이트 현재 위치 및 목표 위치 입력
        int cur[2]; // 현재 위치
        int tar[2]; // 목표 위치
        cin >> cur[0] >> cur[1];
        cin >> tar[0] >> tar[1];
        
        q.push({cur[0], cur[1]}); // 현재 위치 바로 푸쉬
        chess[cur[1]][cur[0]] = 1; // 거리 가중치 연산

        // 거리 가중치 출력
        cout << BFS(l, tar) << '\n';

        // 큐 및 체스판 초기화
        q = temp;
        for(int j = 0; j < l; j++){
            for(int k = 0; k < l; k++){
                chess[j][k] = 0;
            }
        }
    }
}