// https://www.acmicpc.net/problem/2252
// 2026-03-03
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> vec[32001]; 
queue<int> que;
int indegree[32001]; // 내 앞에 몇 명이 와야하지? (진입 차수)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // n 명의 학생, m 번 만큼의 비교
    int n, m;
    cin >> n >> m;

    // 순서 관계 입력
    for(int i = 0; i < m; i++){
        // 순서 입력
        int a, b;
        cin >> a >> b;

        vec[a].push_back(b);

        indegree[b]++;
    }

    // 앞에 아무도 서지 않는 학생 (진입차수가 0인 인덱스) 큐에 넣기
    for(int i = 1; i < n + 1; i++){
        if(indegree[i] == 0){
            que.push(i);
        }
    }

    // 큐가 빌 때 까지 줄 세우기
    while(!que.empty()){
        int num = que.front();
        que.pop();

        cout << num << " ";

        // 순서 관계에 관련있는 학생들 진입차수 연산
        for(auto x : vec[num]){
            indegree[x]--;

            if(indegree[x] == 0){
                que.push(x);
            }
        }
    }
}