#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
전략 구상

토마토 상태 :
익은 상태 1
익지 않은 상태 0
빈 상자 -1

토마토는 하루를 단위로, 익은 토마토로부터 1 칸씩 '익은 상태'가 번져나감.
상하좌우로만 전염되며, 대각선 X
다만, 빈 상자로 둘러쌓인 익지 않은 토마토는 영원히 익지 않음.

성공 조건 : 
1. 가능한 모든 토마토가 익을 때 까지의 날짜 구하기
2. 시작부터 모든 토마토가 익어있으면 0 출력
3. 토마토가 모두 익지 못하는 상황이 발생하면 -1 출력

풀이 전략
1.bfs를 굴리기 전, 모든 토마토가 익었는지 검사 

2.처음 배치되는 익은 토마토는 1개 뿐만이 아니라 여러 개일 수도 있음
    bfs를 반복하는 타이밍이 중요함
    -> 날짜 가중치가 동일한 모든 인덱스 탐색이 끝나면, 다음 가중치 탐색 시작
        -> (다 풀고 난 뒤) 고려사항이 아니게 되었음;
        어차피 큐는 선입선출의 구조이기 때문에 
        날짜 가중치가 작은 순으로 탐색을 시작하게 됨.

3. bfs가 끝나면, 격리되어서 익지 못한 토마토가 있는지 검사
*/

int box[1000][1000]; // 창고 크기
int wei[1000][1000]; // 날짜 가중치 저장 겸 방문 체크
int max_wei = 0; // 가장 높은 날짜 가중치

// 탐색 방향 지정 배열
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

queue<pair<int,int>> q; // BFS에 이용할 창고 좌표 저장 큐

void BFS(int m, int n){
    // 모든 익은 토마토를 큐에 넣기
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(box[i][j] == 1){
                q.push({j, i});
                wei[i][j] = 1;
            }
        }
    }
    

    // 탐색 시작
    while(!q.empty()){
        // 현재 탐색 좌표 : cx, cy
        int cx = q.front().first; 
        int cy = q.front().second; 
        q.pop();

        // 상하좌우로 뻗기
        for(int i = 0; i < 4; i++){
            // 다음 탐색 좌표 : nx, ny
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            // 다음 탐색 창고가
            if((nx >= 0 && nx < m) && (ny >= 0 && ny < n)){ // 범위 내에 있고,
                if(box[ny][nx] == 0){ // 익지 않은 토마토가 있으며,
                    if(wei[ny][nx] == 0){ // 아직 탐색하지 않은 곳이면,
                        q.push({nx, ny}); // 큐에 푸쉬
                        wei[ny][nx] = wei[cy][cx] + 1; // 날짜 가중치 증가
                        box[ny][nx] = 1; // 익은 토마토 표시

                        // 추가로, 가장 높은 날짜 가중치 갱신
                        if(wei[ny][nx] > max_wei) 
                            max_wei = wei[ny][nx];
                    }
                }
            }
        }
    }
}

int main(){
    // 입출력 시간 줄이기
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    // 창고 크기 입력 m : 가로, n : 세로
    int m, n;
    cin >> m >> n;
    
    // 창고 정보 입력
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> box[i][j];
        }
    }

    // 모든 토마토가 익었는지 확인하기
    bool isOk = 1; // 전부 익었나
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(box[i][j] == 0){ // 안 익었나?
                isOk = 0; // 안 익음
                break;
            }
        }
        if(!isOk) // 안 익음
            break;
    }

    if(isOk){ // 전부 익었음
        cout << "0";
        return 0;
    }

    BFS(m, n);

    // 안 익은 토마토가 있는지 확인하기
    isOk = 1; // 전부 익었을거임
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(box[i][j] == 0){ // 안 익었나?
                isOk = 0; // 안 익음
                break;
            }
        }
        if(!isOk) // 안 익음
            break;
    }

    if(!isOk){ // 전부 안익음
        cout << "-1";
        return 0;
    }

    // 최고 날짜 가중치 출력
    cout << max_wei - 1;

    // 테스트 출력
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << box[i][j] << " ";
    //     }
    //     cout << endl;
    // }

}