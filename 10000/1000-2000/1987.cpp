// https://www.acmicpc.net/problem/1987
// 2026-01-24 ~ 01-25
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
    전략 구상
    dfs를 이용해 백트레킹을 구현하여 문제를 풀어보자

    논리 흐름
    1. 현재 위치 정보 (cx, cy)를 가져옴
    2. 다음 탐색 위치 (nx, ny)를 계산함

    == 여기서 부터 백트레킹 구조를 구현해야 함 ==
    그래프가 깊이의 끝에 도달하면, 지금까지 저장했던 데이터를 일부 백트레킹 해야 함
    되돌려야 하는 데이터 -> 방문 체크, 중복 알파벳 리스트
    그대로 남아있어야 하는 데이터 -> 최대 거리 가중치
    
    3. 다음 탐색 위치에 대해 검사함
        -> 조건 1 : nxny가 보드 범위 내에 있는가 ?
        -> 조건 2 : 방문한 적이 있는가 ? 
        -> 조건 3 : 이전에 본 적 없는 알파벳인가 ? 
    
    3 - 1. 조건을 만족하면, 다음 탐색 위치를 경로 벡터에 저장함 -> path
    3 - 2. 조건을 만족하지 못하면, 그대로 다음 탐색 방향으로 continue;

    4. 거리 가중치 최댓값 검사
    dfs 재귀 호출을 통해 최대 깊이 까지 내려감
    현재 상황 까지의 거리 가중치를 다른 변수에 저장 
    거리가중치 : path.size(); 다른 변수 : int mx_value;
    매 탐색마다 거리 가중치가 mx_value를 넘는지 검사하고, 여부에 따라 갱신하기

    5. 백트레킹
    최대 깊이에 도달한 경우, 백트레킹을 실행함.
    dfs를 실행한 뒤, 모든 벡터에 대한 일부 데이터를 pop_back();
        -> 탐색 방향 별 반복문을 돌리고 있으므로,
        한 번 백트레킹을 시작하면 재귀 호출한 함수가 마무리 될 때,
        분기점까지 전부 데이터가 사라짐
    
    위에 한 거 다 시간초과 뜸

    다시 해보자
    제미니한테 물어보니까,
    path, dictionary 굳이 벡터 선언안해도 되고,
    26짜리 bool 자료형 배열만 있으면 방문체크, 알파벳 중복 체크 전부 가능하다고함
    지금까지 굳이 동적 메모리만 고집한 이유가 popback이라는 편리한 기능을 사용하기 위함이었는데,
    생각해보니 정적 배열로도 충분히 구현 가능할 것 같음
    

    */

char board[20][20]; // 보드 크기

// 탐색 방향 지정 배열
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool dictionary[26];

int dist = 0;
int mx_value = 0;

// 탐색 함수, 인자 : 세로 r, 가로 c
void dfs(int r, int c, pair<int,int> p){
    for(int i = 0; i < 4; i++){
        // 현재 위치 좌표
        int nx = p.first + dx[i];
        int ny = p.second + dy[i];

        if((nx >= 0 && nx < c) && (ny >= 0 && ny < r)){ // 현재 위치가 범위 내에 있으면,
            if(dictionary[(int)board[ny][nx] - 65] == false){
                dictionary[(int)board[ny][nx] - 65] = true;
                dist++;

                dfs(r, c, {nx, ny});

                if(dist > mx_value){
                    mx_value = dist;
                }

                dist--;
                dictionary[(int)board[ny][nx] - 65] = false;
            }


            // 이 부분이 시간초과 뜸
            // // 경로 체크
            // bool isVisited = false;
            // for(auto x : path){
            //     if(x.first == nx && x.second == ny){
            //         isVisited = true;
            //     }
            // }

            // // 사전 체크
            // bool isVisited2 = false;
            // for(auto x : dictionary){
            //     if(board[ny][nx] == x){
            //         isVisited2 = true;
            //     }
            // }

            // if(!isVisited && !isVisited2){
            //     path.push_back({nx, ny});
            //     dictionary.push_back(board[ny][nx]);

            //     dfs(r, c, {nx, ny});
                
            //     if(path.size() > mx_value) {
            //         mx_value = path.size();
            //     }

            //     path.pop_back();
            //     dictionary.pop_back();
            // }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i < 26; i++){
        dictionary[i] = false;
    }

    // 세로, 가로 크기 입력
    int r, c;
    cin >> r >> c;

    // 보드 입력
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            char temp;
            cin >> board[i][j];
        }
    }

    dictionary[(int)board[0][0] - 65] = true;

    dfs(r, c, {0, 0});

    cout << mx_value + 1;
}
// // 말 위치와 경로를 담은 데이터 구조체 State
// struct State{
//     int x, y; // 말 위치 좌표
//     int dis; // 거리 가중치
//     vector<bool> dictionary; // 알파벳 사전 -> 방문 알파벳 표시
//     vector<pair<int,int>> path; // 말이 지금까지 지나온 경로
// };

// char board[20][20]; // 보드 최대 크기
// queue<State> que; // bfs 이용 큐
// int mx_value = 0; // 최댓값 구하기

// // 탐색 방향 지정 배열
// int dx[4] = {-1, 1, 0, 0};
// int dy[4] = {0, 0, -1, 1};

// // 탐색 함수, 인자 : 보드판 크기 세로, 가로 
// void bfs(int r, int c){
//     while(!que.empty()){
//         // 현재 위치 x,y좌표, 사전 정보, 경로
//         int cx = que.front().x;
//         int cy = que.front().y;
//         int distance = que.front().dis;
//         vector<bool> diction = que.front().dictionary;
//         vector<pair<int,int>> cpath = que.front().path;
//         que.pop();

//         // 방향 별 탐색 시작
//         for(int i = 0; i < 4; i++){
//             // 다음 탐색 위치 x,y 좌표
//             int nx = cx + dx[i];
//             int ny = cy + dy[i];

//             // 조건 검사
//             if((nx >= 0 && nx < c) && (ny >= 0 && ny < r)){ // 다음 탐색 좌표가 보드 안에 있고,
//                 if(diction[(int)board[ny][nx] - 65] == false){ // 처음 보는 알파벳이라면,
//                     // 방문을 안한 곳이라면,
//                     bool visited = false; // 방문 체크 변수
//                     for(auto p : cpath){ 
//                         if(p.first == nx && p.second == ny){
//                             visited = true;
//                             break;
//                         }
//                     }

//                     if(!visited){ // 방문 안한 곳이라면,
//                         vector<pair<int,int>> npath = cpath; // 다음 탐색에 넘겨줄 경로의 카피본
//                         npath.push_back({nx, ny}); // 경로에 다음 탐색 추가

//                         vector<bool> next_diction = diction; // 다음 탐색에 넘겨줄 사전의 카피본
//                         next_diction[(int)board[ny][nx] - 65] = true; // 사전에 알파벳 등록
//                         que.push({nx, ny, distance + 1, next_diction, npath}); // 다음 큐에 푸쉬

//                         if(distance + 1 > mx_value){
//                             mx_value = distance + 1;
//                         }
//                     }
//                 }
//             }
//         }
//     }
// }

// int main(){
//     // 세로, 가로 입력
//     int r, c;
//     cin >> r >> c;

//     // 보드 칸 채우기
//     char temp;
//     for(int i = 0; i < r; i++){
//         for(int j = 0; j < c; j++){
//             cin >> temp;
//             board[i][j] = temp;
//         }
//     }

//     // 구조체 초기화 및 말 위치 큐에 푸쉬
//     int dis = 1; // 거리 가중치
//     vector<bool> diction(26, false); // 사전 배열
//     vector<pair<int,int>> path;
//     path.push_back({0, 0}); // 초기 위치 경로에 등록
//     diction[(int)board[0][0] - 65] = true; // 초기 위치 사전에 등록
//     State origin = {0, 0, dis, diction, path}; // 초기값 구조체 완성

//     que.push(origin); // 큐에 푸쉬

//     // 탐색 시작
//     bfs(r, c);

//     // 출력
//     cout << mx_value;
// }