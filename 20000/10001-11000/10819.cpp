// https://www.acmicpc.net/problem/10819
// 2026-01-23
#include <iostream>
#include <vector>

using namespace std;

vector<int> vec; // 수를 저장할 벡터
vector<int> ans; // 합한 결과를 저장할 벡터

int best = 0; // 최댓값 갱신

// 탐색 함수 dfs
// 인자 : 배열 사이즈 n, 배열에 채운 숫자 개수 s, 방문 체크 동적배열 vis
void dfs(int n, int s, bool vis[]){
    // ans에 모든 숫자가 다 들어가면 합 시작
    if(s == n){
        int value = 0;
        for(int i = 0; i < n - 1; i++){
            if(ans[i] - ans[i + 1] >= 0){
                value += ans[i] - ans[i + 1];
            }
            else{
                value += -1 * (ans[i] - ans[i + 1]);
            }
        }

        if(value > best)
            best = value;

        return;
    }

    // 백트래킹
    // ans에 숫자를 차례대로 계속 대입하면서 최댓값을 비교할 것
    for(int i = 0; i < n; i++){
        if(vis[i] == false){
            ans.push_back(vec[i]);
            *(vis + i) = true;
            dfs(n, ans.size(), vis);

            ans.pop_back();
            *(vis + i) = false;
        }
    }
}

int main(){
    // 배열 사이즈 및 저장할 숫자 입력
    int n, a;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a;
        vec.push_back(a);
    }

    bool* vis = new bool[n];
    for(int i = 0; i < n; i++){
        vis[i] = false;
    }

    dfs(n, 0, vis);

    cout << best;

    delete[] vis;
}