// https://www.acmicpc.net/problem/2042
// 2026-02-22
#include <iostream>
#include <vector>

using namespace std;

vector<long long int> list; // 숫자 리스트
long long int tree[4000000]; // 숫자 트리

/*
    시간초과 나오니까 새로 만들기

    세그먼트 트리
    
    배열의 각 인덱스를 리프노드로,
    인덱스 끼리의 합을 부모노드로 두는 자료구조임
    모든 인덱스의 합이 루트노드가 됨

    이진 트리이므로, 크기가 N인 배열로 트리를 만든다면,
    그 크기는 2 ^ (log2(N) + 1) 이 됨.
    N의 최댓값은 1,000,000 이므로, 대충 2^(20 + 1) = 2백만을 넘는 숫자 정도 된다.
    그래도 트리 크기를 좀 넉넉하게 해서 n * 4로 하자

    이걸 이용해보자
*/

// 트리 만들기, 인자 : 시작 노드 번호, 배열 시작 범위, 배열 마지막 범위
void setTree(int node, int start, int end){
    // 탈출 조건 : 서로 같으면, 리프 노드를 의미함
    if(start == end){
        tree[node] = list[start];
        return;
    }
    
    int mid = (start + end) / 2; // 중간점
    
    setTree(node * 2, start, mid); // 왼쪽 범위 재귀
    setTree(node * 2 + 1, mid + 1, end); // 오른쪽 범위 재귀
    
    tree[node] = tree[node * 2] + tree[node * 2 + 1]; // 부모 노드에 값 저장
}

// 구간 합, 인자 : 현재 탐색 노드, 시작, 마지막, 구간의 시작, 마지막
long long int sumTree(int node, int start, int end, int left, int right){
    // 현재 탐색 범위가 구간을 벗어나는 경우
    if(left > end || right < start){
        return 0;
    }
    // 범위가 구간 안에 완전히 속한 경우
    if(left <= start && right >= end){
        return tree[node];
    }

    int mid = (start + end) / 2; // 중간점

    // 범위가 구간에 걸쳐있는 경우
    long long int l_result = sumTree(node * 2, start, mid, left, right); // 왼쪽 재귀
    long long int r_result = sumTree(node * 2 + 1, mid + 1, end, left, right); // 오른쪽 재귀

    return l_result + r_result;
}

// 정보 수정, 인자 : 현재 탐색 노드, 시작, 마지막, 바꿀 위치, 바꿀 값
void updateTree(int node, int start, int end, int idx, long long int value){
    // 현재 탐색 범위가 구간을 벗어나는 경우
    if(idx < start || idx > end){
        return;
    }

    tree[node] += value;

    // 범위가 구간 안에 있는 경우
    if(start != end){
        int mid = (start + end) / 2; // 중간점
        updateTree(node * 2, start, mid, idx, value); // 왼쪽 재귀
        updateTree(node * 2 + 1, mid + 1, end, idx, value); // 오른쪽 재귀
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // 개수 n, 변경 횟수 m, 구간 합의 개수 k
    int n, m, k;
    cin >> n >> m >> k;

    // 숫자 n 개 입력
    for(int i = 0; i < n; i++){
        long long int temp;
        cin >> temp;

        list.push_back(temp);
    }

    setTree(1, 0, n - 1); // 트리 만들기

    // 숫자 변경 및 구간 합 출력
    while(m + k > 0){
        // a = 1 : b 번째 수를 c로 변경, 2 : b부터 c 까지 구간 합 출력
        int a, b;
        long long int c;
        cin >> a >> b >> c;

        if(a == 1){ // 값 바꾸기
            long long int value = c - list[b - 1]; // 바꿀 값과 기존값의 차
            list[b - 1] = c; // 바꾸기
            updateTree(1, 0, n - 1, b - 1, value); // 업데이트 사항 트리에 적용
            m--;
        }
        else{ // 구간 합 구하기
            cout << sumTree(1, 0, n - 1, b - 1, c - 1) << '\n';
            k--;
        }
    }
}


// 아래 부분은 시간초과 된, 세그먼트트리 구조를 사용하지않은 코드
// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
    
//     // 개수 n, 변경 횟수 m, 구간 합의 개수 k
//     int n, m, k;
//     cin >> n >> m >> k;

//     // 숫자 n 개 입력
//     for(int i = 0; i < n; i++){
//         long long int temp;
//         cin >> temp;

//         list.push_back(temp);
//     }

//     // 숫자 변경 및 구간 합 출력
//     int cnt = 0;
//     while(m + k > 0){
//         // a = 1 : b 번째 수를 c로 변경, 2 : b부터 c 까지 구간 합 출력
//         int a, b;
//         long long int c;
//         cin >> a >> b >> c;

//         switch(a){
//         case 1: // a = 1
//             list[b - 1] = c;
//             m--;
//             break;
        
//         case 2: // a = 2
//             // 구간 합 구하기
//             long long int sum = 0;
//             for(int j = b - 1; j < c; j++){
//                 sum += list[j];
//             }

//             cout << sum << '\n';
//             k--;
//             break;
//         }
    
//     }
// }