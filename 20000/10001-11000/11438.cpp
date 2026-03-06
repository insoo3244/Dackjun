// https://www.acmicpc.net/problem/11438
// 2026-03-06
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
    비트 연산
    정수를 2진수로 임시 변환하여, 2의 제곱수를 표현할 수 있음
    
    1을 이진수로 바꾸면 ......00001 이 됨
    비트 연산은 (1 << k) 꼴임
    이는 1을 k만큼 왼쪽으로 민다는 뜻

    ex) (1 << 1) = .....00010 -> 정수 2
        (1 << 4) = .....10000 -> 정수 16
*/


vector<int> vec[100001]; // 정점 인접 리스트
int depth[100001]; // 방문 체크 & 깊이 저장
queue<int> que; // BFS 전용 큐

int parent[18][100001]; // 핵심 : 정점관계 DP 배열 배열[2의 제곱수][노드 개수]
// 행이 18인 이유는, 노드 10만개를 모두 덮을 수 있기 때문임 2^18 = 30만 언저리

void BFS(){
    while(!que.empty()){
        int idx = que.front();
        que.pop();

        // 인접 리스트 순회 & 부모관계 확립
        for(auto x : vec[idx]){
            if(depth[x] == -1){ // 중복 체크
                depth[x] = depth[idx] + 1; // 자식의 깊이는 부모 깊이의 + 1
                parent[0][x] = idx; // 내 2^0(= 1)칸 위 부모 저장
                que.push(x);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    // 노드의 개수 n
    int n;
    cin >> n;

    // 정점 부모관계 초기화
    for(int i = 0; i <= n; i++){
        depth[i] = -1;
    }

    // 정점 관계 입력 (정점이 n개면, 간선은 n - 1개)
    for(int i = 0; i < n - 1; i++){
        int parent, child;
        cin >> parent >> child;

        // 정보 양방향 저장
        vec[child].push_back(parent);
        vec[parent].push_back(child);
    }

    // parent[0][각 노드] 정리
    que.push(1);
    depth[1] = 0;
    BFS();

    // parent[k(= 2^n)][각 노드] 정리
    for(int k = 1; k <= 17; k++){
        for(int i = 1; i <= n; i++){
            int paParent = parent[k - 1][i]; // i의 2^(k-1)번째 조상
            
            // 그 조상이 존재한다면(0이 아니라면), 그 조상의 2^(k-1)번째를 기록
            if(paParent != 0) {
                parent[k][i] = parent[k - 1][paParent];
            }

            // i 번째 노드의 k 번째 부모(= parent[k][i])는 
            // k-1번째 부모(= parent[k - 1][i])의 부모(= parent[k - 1][parent[k - 1][i]])임
        }
    }

    // 알고싶은 쌍의 개수 m
    int m;
    cin >> m;

    // 공통 조상 출력
    int dep = 1;
    for(int i = 0; i < m; i++){
        // 알고싶은 정점 입력
        int a, b;
        cin >> a >> b;

        // 항상 a를 더 깊은 노드로 설정하기
        if(depth[b] >= depth[a]){ 
            int temp = a;
            a = b;
            b = temp;
        }

        int dif = depth[a] - depth[b]; // 두 깊이의 차이

        // 깊이 맞추기 (a를 끌어올리기)
        for(int k = 17; k >= 0; k--){
            // 남은 거리가 점프할 높이보다 크면
            // 남은 거리를 그 만큼 빼기
            if(dif >= (1 << k)){
                a = parent[k][a];
                dif -= (1 << k);
            }
        }

        // a와 b가 같아졌다면 (b가 a의 조상이었다면, 깊이를 맞출 때 a와 b가 같아짐)
        if (a == b){
            cout << a << '\n';
            continue;
        }

        // 그럼에도 a와 b가 서로 다르면
        for(int k = 17; k >= 0; k--){
            // a의 조상이 존재하고, a와 b의 조상이 다르다면
            if(parent[k][a] != 0 && parent[k][a] != parent[k][b]){
                // 점프
                a = parent[k][a];
                b = parent[k][b];
            }
        }

        // 반복문을 진행하면 a와 b의 조상이 같아져서 조건문을 실행하지 않음
        // 공통 조상의 바로 밑 자식에서 더 이상 점프 진행 X
        // 마지막 한 번 더 점프를 함으로써 공통 조상에 도착
        a = parent[0][a]; 
        cout << a << '\n'; // 공통 조상 출력
    }
}