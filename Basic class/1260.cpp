#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 레전드개빡통대가리 열심히굴려서 DFS BFS 이해해보자
/*
DFS 깊이우선탐색
1 - 2 \
|      5
3 - 4 /
탐색 순서 (1번 시작) : 1 2 5 4 3
시작 노드에 인접한 노드 중, 가장 깊숙히 파고드는 노드를 선택해서 탐색

BFS 너비우선탐색
1 - 2 \
|      5
3 - 4 /
탐색순서 (1번 시작) : 1 2 3 5 4

구현하고자 하는 것
1. 정점과 간선의 개수, 시작 노드 위치를 입력받음
2. 이후 간선의 개수만큼 노드 간의 관계를 입력받음
3. 입력받은 정보를 토대로 그래프 체계 저장
4. 이후 그래프를 DFS/BFS 각각의 방식으로 탐색 경로(노드번호)를 공백으로 구분해서 출력하기

2번 - 그래프의 정보를 저장하는 방법
그래프의 정보를 저장할 객체 graph 선언
graph는 각 멤버를 가지게 됨

멤버변수
- 정점의 개수
- 간선의 개수
- 간선의 정보를 저장할 동적 boolean 2차원 배열(이하 gArray로 칭함) -> (정점의 개수 x 정점의 개수) 크기의 배열 : 초기값은 모두 0. 간선이 이어져있는 노드끼리만 true로 초기화
... 이후 더 추가 됨
멤버함수
- 생성자 함수 (멤버변수 초기화)
- 소멸자 함수 (동적배열 소멸이 필요함)
- gArray에 정보를 입력받을 함수
- gArray의 정보를 불러와줄 boolean 반환 함수
- get 함수 (각 멤버변수)
.. 이후 더 추가 됨

* 탐색 시, 주의할 점 : 거리가 같은 두 노드 중에 숫자가 작은 노드부터 탐색
각 탐색함수는 그래프 객체, 자료구조를 인자로 받음

DFS 함수 구상
1 - 2 \
|      5
3 - 4 /
=== 1번부터 DFS 시작 ===
- 1번에 방문했으니, 1을 스택에 저장
- 1을 pop하고 1과 인접한 2, 3을 스택에 저장
- 숫자가 더 작은 2부터 탐색을 해야하니, 2를 pop하고 인접한 5를 스택에 저장
- 5를 pop하고 인접한 4를 스택에 저장
- 4를 pop하고 3에 방문했으나, 이미 스택에 저장되어있으니 작업X
- 3을 pop하고 스택이 비어있으니 재귀 종료


BFS 함수 구상
1 - 2 \
|      5
3 - 4 /
=== 1번부터 BFS 시작 ===
- 1번에 방문했으니, 1을 큐에 저장
- 1을 deque하고 1과 인접한 2, 3을 모두 큐에 저장
- 2를 deque하고 2와 인접한 5를 큐에 저장
- 3을 deque하고 3과 인접한 4를 큐에 저장
- 5를 deque하고 5와 인접한 2, 4는 이미 방문했으니 작업 X
- 4를 deque하고 함수 종료


*/

class graph{
private:
    int vertex; // 정점 개수
    int edge; // 간선 개수
    int start; // 시작 노드
    bool** gArray; // 간선 정보 2차원 배열 포인터
    bool* visitDFS; // DFS 방문 계수
    bool* visitBFS; // BFS 방문 계수

public:
    // 생성자 함수
    graph(int v, int e, int s) {
        // 각 멤버변수 초기화
        vertex = v;
        edge = e;
        start = s;

        // 2차원 배열 초기화
        gArray = new bool *[vertex]; // gArray 행 배열 포인터 선언
        for(int i = 0; i < vertex; i++){
            gArray[i] = new bool [vertex]; // gArray 각 행 마다 열 할당
            for(int j = 0; j < vertex; j++){
                gArray[i][j] = false; // fasle 초기화
            }
        }

        visitDFS = new bool[vertex]; // DFS 방문 여부 확인 배열
        for(int i = 0; i < vertex; i++) visitDFS[i] = false; // false 초기화

        visitBFS = new bool[vertex]; // BFS 방문 여부 확인 배열
        for(int i = 0; i < vertex; i++) visitBFS[i] = false; // false 초기화
    }

    // 소멸자 함수
    ~graph() {
        for(int i = 0; i < vertex; i++){
            delete[] gArray[i];
        }
        
        delete[] gArray;
    }

    // 그래프 정보 입력받기
    void entergArray() {
        int v1, v2; // 정점 정보

        // 간선의 개수만큼 간선 정보 입력받고, gArray에 저장
        for(int i = 0; i < edge; i++){
            cin >> v1 >> v2;
            gArray[v1 - 1][v2 - 1] = true;
            gArray[v2 - 1][v1 - 1] = true;
        }
    }

    // 그래프 정보 갱신하기
    void setFalsegArray(int n1, int n2){
        gArray[n1][n2] = false;
    }

    // DFS 방문계수 갱신하기
    void setTrueVisitDFS(int n1){
        visitDFS[n1] = true;
    }

    // BFS 방문계수 갱신하기
    void setTrueVisitBFS(int n1){
        visitBFS[n1] = true;
    }

    // 정점 개수 불러오기
    int getVertex() { return vertex; }

    // 시작 노드 불러오기
    int getStart() { return start; }

    // 간선 개수 불러오기
    int getEdge() { return edge; }

    // gArray 포인터 불러오기
    bool** getgArray() { return gArray; }

    // 방문 계수 불러오기
    bool* getVisitDFS() { return visitDFS; }

    // 방문 계수 불러오기
    bool* getVisitBFS() { return visitBFS; }
};

void DFS(graph &g, vector<int> &s, int start);
void BFS(graph &g, queue<int> &q, int start);

int main(){
    int vertex; // 정점 개수
    int edge; // 간선 개수
    int start; // 시작 정점

    cin >> vertex >> edge >> start; // 예제 입력
    graph graph(vertex, edge, start); // 그래프 정보 저장
    
    // 그래프 정보 입력
    graph.entergArray();

    // 탐색 시작
    vector<int> stack;
    queue<int> queue;

    DFS(graph, stack, graph.getStart());
    cout << endl;
    BFS(graph, queue, graph.getStart());
}

void DFS(graph &g, vector<int> &s, int start){
    // 시작 노드 스택에 저장하기 & 재귀 후 스택에 저장하기
    bool** gtemp = g.getgArray(); 
    bool* vtemp = g.getVisitDFS();

    if(vtemp[start - 1] == 1) { return; } // 노드 중복 방문 시 종료

    // 노드 방문 계수 갱신 및 방문여부출력
    g.setTrueVisitDFS(start - 1);
    cout << start << " ";
    
    // DFS 구현
    for(int i = 0; i < g.getVertex(); i++){ // 쭉쭉 깊숙히 내려감
        
        // 인접 노드 발견 조건문
        if(gtemp[start - 1][i] == true) { // 갈림길이 있으면 여기서 분기 시작 & 재귀가 끝나면 다른 분기로 반복시작 
            s.push_back(i + 1);
            DFS(g, s, i + 1); // 재귀 시작
            s.pop_back(); // 재귀를 마치고 값 방출
        }
    }
}

void BFS(graph &g, queue<int> &q, int start){
    bool** gtemp = g.getgArray(); 
    bool* vtemp = g.getVisitBFS();

    if(vtemp[start - 1] == true) { return; } // 노드 중복 방문 시 종료

    // 노드 방문 계수 갱신
    g.setTrueVisitBFS(start - 1);

    // BFS 구현
    q.push(start); // 일단 시작 노드를 큐에 넣고 시작
    while(!q.empty()){ // 큐가 바닥날 때 까지 반복
        cout << q.front() << " "; // 출력

        for(int i = 0; i < g.getVertex(); i++){
            // 인접 노드 발견 조건문
            if(gtemp[q.front() - 1][i] == true){
                if(vtemp[i] == true) continue; // 큐에 중복되는 값 투입 방지
                q.push(i + 1); // 인접 노드 싹 다 우겨넣기
                g.setTrueVisitBFS(i); // 방문 체크까지
            }
        }
        q.pop(); // 시작노드 방출 & 노드 방출을 통해 다음 노드의 인접노드 검수 반복
    }
}
