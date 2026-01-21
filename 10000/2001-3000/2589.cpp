// https://www.acmicpc.net/problem/2589
// 2026-01-21
#include <iostream>
#include <queue>

using namespace std;

/*
전략 구상

한 칸 이동할 때, 한 시간 소비

보물의 위치는 내가 임의로 지정한 지도에,
"최단 거리로 이동할 때, 가장 오래 걸리는 두 곳" 에 위치함

시간 구하기 : 
각 육지 인덱스 마다 BFS를 돌리기
-> 가장 먼 곳에 가장 빨리 도착하는 시간 데이터를 가짐

t_max 변수 : 가장 오래걸리는 시간 가중치 찾기

아스키코드는 127 까지만 존재함. 그 값을 넘어가면 쓰레기값이 되니,
map을 int로 받거나, 시간 가중치 배열을 하나 더 만들자
*/

int map[50][50]; // 보물지도 최대 크기
queue<pair<int,int>> q; // BFS 이용 큐
int t_max = 0; // 가장 오래걸리는 시간 가중치 구하기

// 탐색 방향 지정 배열
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void BFS(int m, int n){
    while(!q.empty()){
        // 현재 위치 cx, cy
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        // 탐색 시작
        for(int i = 0; i < 4; i++){
            // 다음 탐색 위치
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if((nx >= 0 && nx < n) && (ny >= 0 && ny < m)){ // nxny가 범위 내에 있고,
                if(map[ny][nx] == 76) { // 육지이면서, 한 번도 안가봤으면,
                    map[ny][nx] = map[cy][cx] + 1; // L이 아닌, 아스키코드 상 다음 철자 저장
                    q.push({nx, ny}); // 큐에 푸쉬
                    if(map[ny][nx] > t_max){ // t_max 갱신해주기
                        t_max = map[ny][nx];
                    }
                }
            }
        }
    }
}

int main(){
    // 보물지도의 크기 입력
    int m, n; // 세로 가로
    cin >> m >> n;

    // 보물지도 지형 입력
    int temp[50][50];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            char c;
            cin >> c;
            map[i][j] = c;
            temp[i][j] = map[i][j]; // temp에도 똑같이 복사
        }
    }
    // 테스트 출력
    // for(int i = 0; i < m; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << map[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // 탐색 시작
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(map[i][j] == 76){ // 육지 인덱스면,
                q.push({j, i}); // 큐에 푸쉬
                map[i][j] = 77;
                BFS(m, n); // BFS로 시간 가중치 및 t_max 연산
            }

            // map 초기화
            for(int k = 0; k < m; k++){
                for(int l = 0; l < n; l++){
                    map[k][l] = temp[k][l];
                }
            }
        }
    }

    // 출력
    cout << t_max - 76 - 1;
}