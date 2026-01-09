// https://www.acmicpc.net/problem/11724
// 2026-01-08 ~ 2026-01-09 < -- 01-08 안에 풀었는데요 이거 주작임
// 위에 링크 뭐임 ? ? ?
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> arr[1001]; // 2차원 안해도 돼 ?  ? ? 
int visited [1001]; // 방문체크 배열 내가 만듬 -insoo3244444

int cnt = 0;

void DFS(int node){ // n = 정점 개수
    if (visited[node] == 1) return; // 방문 노드 검사 
    
    visited[node] = 1;
    for(auto x : arr[node]) {
        DFS(x);
        visited[x] = 1;
    }
}

// insoo fought but he couldn't win
// butt 궁뎅이

int main() {
    int n, m; // n = 정점 개수, m = 간선 개수
    int cnt = 0;

    cin >> n >> m;

    // 그래프 입력
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        arr[u].push_back(v);
        arr[v].push_back(u); 
    }

    for(int i = 1; i < n + 1; i++) {
        if (visited[i] != 1) { // 방문 노드 검사 
            DFS(i); 
            cnt++;
        }
    } 

    cout << cnt;
    // 내 세상이 무너졌어 ㅠㅠ
}