// https://www.acmicpc.net/problem/1697
// 2026-01-18

// 전략 구상

/*

수빈이는 두 가지 행동을 할 수 있음

현재 좌표 : x
1. 걷기 : x +- 1 로 이동함
2. 순간이동 : 2x 로 이동함 (무조건 양의 방향으로 이동)
행동 1회 당, 1초 소비

이 두 가지 행동으로 동생의 위치까지 도달해야 하며,
최소 도달 시간을 구해야 함.
-> BFS

BFS를 굴리는데 필요한 요소
1. 시작 노드
2. 인접 노드를 pop, push 하면서 탐색 방법 설계
3. 탐색 기준과 종료 조건

이 문제를 푸는데 필요한 요소
1. 시작 노드 -> 수빈이의 위치

2. 1부터 100000까지 좌표가 존재하는 수직선 상의 세계를 
그래프로 나타내는 것은 무리가 있음.
-> 인접 노드를 [ x +- 1 , 2x ] 3개를 추가하면서 탐색 시작.

3. 탐색 기준과 종료 조건
-> 좌표가 0과 100000을 벗어나면 종료
-> 동생을 찾으면 종료

*/

#include <iostream>
#include <queue>

using namespace std;

queue<int> que; // BFS를 위한 큐
vector<int> vec; // 동생에게 도착할 때 소비한 시간 저장
int weight[100001]; // 시간 가중치 배열 및 방문 체크

// 탐색 방향 지정 배열
int dn[3] = {1, -1, 2}; 

void BFS(int n, int k){ 
    weight[n] = 1;
    que.push(n);
    
    while(!que.empty()){
        int curLoct = que.front(); // 현재 위치
        int curP = curLoct + dn[0]; // 현재 위치 + 1
        int curM = curLoct + dn[1]; // - 1
        int curT = curLoct * dn[2]; // * 2
        que.pop();
        
        // 현재 위치 범위 검사
        if((curLoct < 0) || (curLoct > 100000)) { continue; }

        // 동생 위치 도달 검사
        if(curLoct == k) { return; }

        // 시간 가중치 부여 & 방문 체크
        // 인접 노드 추가
        if(curM >= 0){ // 범위 확인
            if(weight[curM] == 0){  // 중복 체크
                que.push(curM); // 큐에 푸쉬
                weight[curM] = weight[curLoct] + 1; // 가중치 부여
            }
        }
        
        if(curP <= 100000){
            if(weight[curP] == 0){ 
                que.push(curP);
                weight[curP] = weight[curLoct] + 1;
            }
        }
        
        if(curT <= 100000){
            if(weight[curT] == 0){ 
                que.push(curT);
                weight[curT] = weight[curLoct] + 1;
            }
        }
    }
}

int main(){
    // vis 초기화
    for(int i = 0; i < 100001; i++)
        {weight[i] = 0;}
        
    // 위치 입력
    int n, k;
    cin >> n >> k; 

    BFS(n, k);
    
    cout << weight[k] - 1;
}