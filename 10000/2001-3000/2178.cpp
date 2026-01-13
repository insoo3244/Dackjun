// https://www.acmicpc.net/problem/2178
// 2026-01-13

#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int maze[101][101]; // 미로 기본 크기

// 탐색 방향 지정 배열
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int d = 0; // 이동한 거리

void bfs(int n, int m){
    // BFS 이용 큐
    queue<pair<int, int>> q;

    // 탐색 시작 좌표 (1, 1)
    int x = 1;
    int y = 1;
    q.push({x, y});
    
    // 큐 가장 앞에있는 요소 와왓와서 x좌표 y좌표 저장했음 
    while(!q.empty()){
        int q_size = q.size(); 
        
        //큐 가장 앞에있는거 꺼내오고싶음 숫자쌍
        for(int i = 0; i < q_size; i++) {
            // 큐 가장 앞에있는 요소 뽑아와서 현재 노드가 어디있는지를 사용할거임
            pair<int, int> cur = q.front();  
            int cx = cur.first;
            int cy = cur.second;

            // 지움
            q.pop();

            for(int j = 0; j < 4; j++){
                int nx = cx + dx[j];
                int ny = cy + dy[j];

                // x, y 범위 체크
                if((nx < 1 || nx > m + 1) || (ny < 1 || ny > n + 1))
                    continue;
                        
                if(maze[ny][nx] == 1) {
                    maze[ny][nx] = maze[cy][cx] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main(){
    // 미로 크기 입력 n : 세로 / m : 가로
    int n, m;
    cin >> n >> m;

    // 미로 맵 설계

    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < m + 1; j++) {
            char num;
            cin >> num;
            int c = num - '0';
            maze[i][j] = c;
        }
    }

    bfs(n, m);

    cout << maze[n][m];
}