// https://www.acmicpc.net/problem/1922
// 2026-03-04
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    구해야 하는 것
    컴퓨터를 연결하는데 드는 최소 비용

    필요한 입력
    컴퓨터 수
    연결선 수
    컴퓨터 간의 연결정보
    연결하는데 드는 비용

    필요한 논리
    컴퓨터를 서로 연결하는 로직 + 연쇄 연결 시, 전부 연결되는 로직
    모든 컴퓨터가 연결되었는지 확인하는 로직
        -> 이때, 비용이 얼마드는지 연산하는 로직
    모든 연결 방법 중, 최소비용을 구하는 로직

    적합한 자료구조 - ? 

    컴퓨터 간의 연결정보
        -> 연결관계 저장 vector<int>[]
        -> 연결되어 있는 상태 저장 bool[]
    연결하는데 드는 비용 -> int[];

    적합한 알고리즘 - ?
    백트래킹 - 그래프를 순회하며 반복적인 push와 pop을 통해 여러 조합 검사
    그리디 - 입력이 끝남과 동시에 최소 반복으로 원하는 값 얻어내기

    음; 하나도 모르겠다

    -- 제미나이 왈 --
    백트래킹 하면 시간 복잡해지니까 그리디한 접근이 필수
    전형적인 '최소신장트리' 문제임

    인접리스트 보다는 간선의 정보(컴퓨터 a, 컴퓨터 b, 비용 c) 자체를 저장하는것이 더 효율적

    로직 가이드라인
    1. 연결 정보를 모두 입력받고, 비용 기준 오름차순
        -> 구조체로 저장하기
        
    2. 연결해도 되는지 판단하는 로직 작성 
        -> 두 컴퓨터가 같은 네트워크에 있는가?
            -> 그렇다면, 건너뛰기
            -> 맞다면, 한 쪽으로 부모노드 통일하기
                -> 동시에, 최소비용을 구하는데 필요한 비용 연산 진행
        
        -> 연결한 횟수를 세어서, N - 1까지 횟수가 채워질 경우 강제 종료
            -> N개의 컴퓨터가 서로 연결되기 위한 최소 횟수는 N - 1번임
            -> 그러면 아직 탐색하지 않은 네트워크 중에, 더 싼 비용이 들어가는 경우를 배제하잖아?
                -> 비용 오름차순으로 벡터를 정렬한 덕에 고려하지 않아도 됨.
         
    3. 이후, 사용한 간선의 비용을 계산 후 출력
    
    
*/

// 네트워크 연결 정보 구조체
struct Network{
    int c1, c2, cost;

    Network(int a, int b, int c){
        c1 = a; c2 = b; cost = c;
    }
};

// 구조체 정렬을 위한 compare 함수
bool compare(const Network &n1, const Network &n2){
    return n1.cost < n2.cost;
}

vector<Network> vec; // 구조체를 저장할 벡터
int parent[1001]; // 컴퓨터 연결 정보

// 부모 원소 찾기
int find(int idx){
    if(parent[idx] == idx){ // 자기 자신이라면, 부모노드
        return idx;
    }

    return parent[idx] = find(parent[idx]); // 거쳐오는 모든 노드가 부모 노드를 지정하게끔 하기
}

// 합집합 연산
void sumSet(int a, int b) {
    if (a != b) {
        parent[a] = b;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 컴퓨터 수 n, 연결 선 수 m
    int n, m; 
    cin >> n >> m;

    for(int i = 1; i < n + 1; i++){
        parent[i] = i;
    }

    // 네트워크 선 정보 입력
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;

        Network temp(a, b, c);

        vec.push_back(temp);
    }

    // 연결 비용 순 정렬
    sort(vec.begin(), vec.end(), compare);

    // 연결 정보대로 연결하기
    int sumCost = 0; // 비용 합산
    int count = 0; // 연결한 횟수 : N - 1번이 되면 로직 강제 종료
    for(auto x : vec){
        if(count == n - 1){
            break; 
        }

        int rootA = find(x.c1);
        int rootB = find(x.c2);

        // 만약 서로 같은 부모를 가리키고 있다면 건너뛰기
        if(rootA == rootB){
            continue;
        }
        
        sumSet(rootA, rootB); // 부모노드를 한 쪽으로 통일 
        sumCost += x.cost; // 비용 연산    
        count++; // 횟수 연산
    }

    cout << sumCost;
}