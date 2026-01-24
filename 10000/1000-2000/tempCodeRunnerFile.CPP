// https://www.acmicpc.net/problem/1987
// 2026-01-24
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 말 위치와 경로를 담은 데이터 구조체 State
struct State{
    int x, y; // 말 위치 좌표
    vector<pair<int,int>> path; // 말이 지금까지 지나온 경로
};

bool dictionary[26]; // 알파벳 사전 -> 방문 알파벳 표시
char board[20][20]; // 보드 최대 크기
int vis[20][20]; // 방문 체크 배열 겸 거리 가중치
queue<State> que; // bfs 이용 큐
int mx_value = 0; // 최댓값 구하기

// 탐색 방향 지정 배열
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 탐색 함수, 인자 : 보드판 크기 세로, 가로 
void bfs(int r, int c){
    while(!que.empty()){
        // 현재 위치 x,y좌표, 경로
        int cx = que.front().x;
        int cy = que.front().y;
        vector<pair<int,int>> cpath = que.front().path;
        que.pop();

        // 방향 별 탐색 시작
        for(int i = 0; i < 4; i++){
            // 다음 탐색 위치 x,y 좌표
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            // 조건 검사
            if((nx >= 0 && nx < c) && (ny >= 0 && ny < r)){ // 다음 탐색 좌표가 보드 안에 있고,
                if(vis[ny][nx] == 0){ // 방문하지 않은 곳이라면,
                    if(dictionary[(int)board[ny][nx] - 65] == false){ // 처음 보는 알파벳이라면,
                        // 지나온 경로에 다음 탐색 
                        bool visited = false;
                        for(auto p : cpath){
                            if(p.first == nx && p.second == ny){
                                visited = true;
                                break;
                            }
                        }

                        if(!visited){
                            cpath.push_back({nx, ny});
                            que.push({nx, ny, cpath});
                        }
                    }
                }
            }
        }
    }
}

int main(){
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            vis[i][j] = false;
        }
    }
    // 세로, 가로 입력
    int r, c;
    cin >> r >> c;

    // 보드 칸 채우기
    char temp;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> temp;
            board[i][j] = temp;
        }
    }
    
    dictionary[(int)board[0][0] - 65] = true; // 시작 위치 사전에 등록

    // 구조체 초기화 및 말 위치 큐에 푸쉬
    vector<pair<int,int>> path;
    path.push_back({0, 0}); // 초기 위치 경로에 등록
    State origin = {0, 0, path}; // 초기값 구조체 완성
    que.push(origin); // 큐에 푸쉬

    // 탐색 시작
    bfs(r, c);

    // 출력
    cout << mx_value;
}