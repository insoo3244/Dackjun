// https://www.acmicpc.net/problem/2606
// 2026-01-09
// very ez
#include <iostream>
#include <vector>

using namespace std;

vector<int> arr[101];
int vis[101];
int cnt = 0;

void DFS(int node) {
    if(vis[node] == 1) return;

    cnt++;
    vis[node] = 1;
    for(auto x : arr[node]) DFS(x);
}

int main(){
    int com, m;

    cin >> com;
    cin >> m;

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;

        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    DFS(1);

    cout << cnt - 1;
}