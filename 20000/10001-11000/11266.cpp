// https://www.acmicpc.net/problem/11266
// 2026-03-08
#include <iostream>
#include <vector>

using namespace std;

vector<int> vec[10001]; // 인접 리스트
int vis[10001]; // 방문 체크 & 방문 순서 기록
bool isCut[10001]; // 단절점 리스트
int od = 0;

/*
    단절점
    해당 정점을 제거했을 때, 그래프가 두 개 이상으로 나누어지는 정점을 말함

    해당 정점을 배제하고 dfs를 돌려보자

    ==== 시간초과 ====
    -> 제미나이한테 물어보기

    
*/

// dfs : 탐색 인덱스 idx, 노드 개수 v, 부모노드 parent
int dfs(int idx, int v, int parent){
    // 루트노드 전용
    int childCount = 0;

    vis[idx] = ++od; // 방문 순서 매기기
    int low = vis[idx]; // 내가 갈 수 있는 가장 작은 방문번호. 초기값 : 자기 자신
    int child_low; // 자식 노드의 low

    // 가장 작은 방문번호 갱신
    for(int i : vec[idx]){
        if(i == parent) continue; // 부모노드는 무시해야 함

        if(vis[i] != 0){ // 방문 한 곳이면,
            if(vis[i] < low){ // 나보다 번호가 작은 지 검사
                low = vis[i];
            }
        }
        else{ // 아직 방문 안 한 곳이면, dfs 돌리기
            childCount++;
            child_low = dfs(i, v, idx);

            // 루트노드 X, 자식low가 내 순번보다 크다면
            if(parent != 0 && child_low >= vis[idx]){
                isCut[idx] = true;
            }

            // 내 방문 순서가 자식low 보다 크다면, 우회로 존재 -> 자식으로 덮어쓰기
            low = (low < child_low) ? low : child_low;
        }
    }

    // 루트노드 O, 자식이 여러 개일 때만
    if(parent == 0 && childCount > 1){
        isCut[idx] = true;
    }

    return low; // 내가 어디까지 내려갈 수 있나 반환하기
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    // 정점 개수 v, 간선 개수 e
    int v, e;
    cin >> v >> e;

    for(int i = 0; i <= v; i++){
        isCut[i] = false;
    }

    // 정점 정보 입력
    for(int i = 0; i < e; i++){
        int a, b;
        cin >> a >> b;

        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    // 단절점 찾기
    // 1. 탐색을 시작한 노드(루트노드)가 자식이 2개인 경우 단절점
    // 2. 어떤 자식노드 v가 부모노드 u를 거치지 않고 u의 부모로 가는 경로가 없으면, 단절점
    // -> v의 후손들이 갈 수 있는 가장 빠른 방문 순서 >= u의 방문 순서   
    int cnt = 0; // 단절점 개수
    for(int i = 1; i <=v; i++){
        if(vis[i] != 0) continue;

        dfs(i, v, 0);        
    }

    for(int i = 1; i <= v; i++){
        if(isCut[i]) cnt++;
    }

    cout << cnt << '\n';
    for(int i = 1; i <= v; i++){
        if(isCut[i]) cout << i << " ";
    }
}


// void dfs(int idx, int v, int order){
//     if(vis[idx] != 0){ // 방문체크
//         return;
//     }
//     vis[idx] = order;

//     for(auto x : vec[idx]){
//         dfs(x, v, order + 1);
//     }
// }

// int main() {
//     // ios_base::sync_with_stdio(false);
//     // cin.tie(NULL);
    
//     // 정점 개수 v, 간선 개수 e
//     int v, e;
//     cin >> v >> e;

//     // 방문체크 초기화
//     for(int i = 1; i <= v; i++){
//         vis[i] = 0;
//     }

//     // 정점 관계 입력
//     for(int i = 0; i < e; i++){
//         int a, b;
//         cin >> a >> b;

//         vec[a].push_back(b);
//         vec[b].push_back(a);
//     }

//     // 그래프 개수 연산
//     int OriginCnt = 0;
//     for(int i = 1; i <= v; i++){
//         if(vis[i] == 1) continue;
//         dfs(i, v, i);

//         OriginCnt++;
//     }

//     // 방문체크 초기화
//     for(int i = 1; i <= v; i++){
//         vis[i] = 0;
//     }

//     // 정점 배제 후 그래프 개수 연산. 본래 그래프 갯수 만큼 탐색
//     int temp = OriginCnt;
//     for(int i = 1; i <= v; i++){
//         while(temp--){
//             if(vis[i] != 0) continue;
//             vis[i] = 10;

//             dfs(1, v, i);
//         }
        
//         temp = OriginCnt;

//         // 방문 배열 확인 -> 안된 곳이 있으면 단절점 존재
//         bool isExist = false;
//         for(int j = 1; j <= v; j++){
//             if(vis[j] == 0){
//                 isExist = true;
//                 break;
//             }
//         }

//         if(isExist){ // 단절점 존재 시
//             // 단절점 찾아서 저장
//             for(int j = 1; j <= v; j++){
//                 if(vis[j] == 10){
//                     sliceVertex.push_back(j);
//                 }
//             }
//         }

//         // 방문체크 초기화
//         for(int i = 1; i <= v; i++){
//             vis[i] = 0;
//         }
//     }

//     // 단절점 개수 및 정보 출력
//     cout << sliceVertex.size() << '\n';
//     for(int x : sliceVertex){
//         cout << x << " ";
//     }
// }