// https://www.acmicpc.net/problem/1987
// 2026-01-24
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 말 위치와 경로를 담은 데이터 구조체 State
struct State{
    int x, y; // 말 위치 좌표
    int dis; // 거리 가중치
    vector<bool> dictionary; // 알파벳 사전 -> 방문 알파벳 표시
    vector<pair<int,int>> path; // 말이 지금까지 지나온 경로
};

char board[20][20]; // 보드 최대 크기
queue<State> que; // bfs 이용 큐
int mx_value = 0; // 최댓값 구하기

// 탐색 방향 지정 배열
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 탐색 함수, 인자 : 보드판 크기 세로, 가로 
void bfs(int r, int c){
    while(!que.empty()){
        // 현재 위치 x,y좌표, 사전 정보, 경로
        int cx = que.front().x;
        int cy = que.front().y;
        int distance = que.front().dis;
        vector<bool> diction = que.front().dictionary;
        vector<pair<int,int>> cpath = que.front().path;
        que.pop();

        // 방향 별 탐색 시작
        for(int i = 0; i < 4; i++){
            // 다음 탐색 위치 x,y 좌표
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            // 조건 검사
            if((nx >= 0 && nx < c) && (ny >= 0 && ny < r)){ // 다음 탐색 좌표가 보드 안에 있고,
                if(diction[(int)board[ny][nx] - 65] == false){ // 처음 보는 알파벳이라면,
                    // 방문을 안한 곳이라면,
                    bool visited = false; // 방문 체크 변수
                    for(auto p : cpath){ 
                        if(p.first == nx && p.second == ny){
                            visited = true;
                            break;
                        }
                    }

                    if(!visited){ // 방문 안한 곳이라면,
                        vector<pair<int,int>> npath = cpath; // 다음 탐색에 넘겨줄 경로의 카피본
                        npath.push_back({nx, ny}); // 경로에 다음 탐색 추가

                        vector<bool> next_diction = diction; // 다음 탐색에 넘겨줄 사전의 카피본
                        next_diction[(int)board[ny][nx] - 65] = true; // 사전에 알파벳 등록
                        que.push({nx, ny, distance + 1, next_diction, npath}); // 다음 큐에 푸쉬

                        if(distance + 1 > mx_value){
                            mx_value = distance + 1;
                        }
                    }
                }
            }
        }
    }
}

int main(){
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

    // 구조체 초기화 및 말 위치 큐에 푸쉬
    int dis = 1; // 거리 가중치
    vector<bool> diction(26, false); // 사전 배열
    vector<pair<int,int>> path;
    path.push_back({0, 0}); // 초기 위치 경로에 등록
    diction[(int)board[0][0] - 65] = true; // 초기 위치 사전에 등록
    State origin = {0, 0, dis, diction, path}; // 초기값 구조체 완성

    que.push(origin); // 큐에 푸쉬

    // 탐색 시작
    bfs(r, c);

    // 출력
    cout << mx_value;
}