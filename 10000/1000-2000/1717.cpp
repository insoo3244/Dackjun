// https://www.acmicpc.net/problem/1717
// 2026-03-02
#include <iostream>
#include <vector>

using namespace std;

int arr[1000001]; // n + 1 크기 집합

// 부모 원소 찾기
int find(int idx){
    if(arr[idx] == idx){ // 자기 자신이라면, 부모노드
        return idx;
    }

    return arr[idx] = find(arr[idx]); // 부모 노드 찾기
}

// 합집합 연산
void sum(int a, int b) {
    int rootA = find(a); // a의 부모 노드 찾아서 저장
    int rootB = find(b); // b의 부모 노드 찾아서 저장
    
    if (rootA != rootB) {
        arr[rootA] = rootB;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // n : 집합 크기 n + 1, m : 연산 개수
    int n, m;
    cin >> n >> m;

    // 배열 초기화
    for(int i = 0; i < n + 1; i++){
        arr[i] = i;
    }

    int a, b, c;
    // a : 0 = 합집합 연산, 1 = 같은 집합 확인 연산
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;

        switch(a){
            case 0:
                sum(b, c);
                break;
            case 1:
                if(find(b) == find(c)){
                    cout << "YES";
                }
                else{
                    cout << "NO";
                }

                cout << '\n';
                break;
        }
    }
}