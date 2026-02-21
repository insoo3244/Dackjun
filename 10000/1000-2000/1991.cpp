// https://www.acmicpc.net/problem/1991
// 2026-02-21
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
    트리 순회

    반복에 집착하지 말고 재귀에 집중하기
    for문을 굳이 사용하지 않아도, 재귀에 의해서 알아서 반복되는 구조를 명심하기

    전중후 모두 반복문을 안써도, 재귀 구조로만 구현이 가능하다

    +) 중간에 list에 철자를 추가하기 위해 idx '+ 65', tree[idx][i] '- 65'를 쓴 이유
    +65 : 숫자 0에 상응하는 철자는 A 이지만, 여기서 -65를 해버리면 쓰레기값이 나옴
    -65 : 철자를 int화 시켜서 -65를 해야, 비로소 그 철자에 상응하는 정수값이 나옴
*/

vector<char> tree[26]; // 이진 트리
vector<char> list; // 순회 리스트

int route = 0; // 루트 노드

// 인자 : 노드의 개수, 탐색 인덱스
// 전위 순회
void preorder(int idx){
    // 현재 탐색 중인 인덱스
    char curIdx = char(idx + 65);
    list.push_back(curIdx);

    // 트리에 없는 노드라면
    if(tree[idx].empty()){
        return;
    }

    for(int i = 0; i < 2; i++){
        if(tree[idx][i] != '.'){
            preorder(int(tree[idx][i]) - 65);
        }
    }
}

// 중위 순회
void inorder(int idx){
    // 트리에 없는 노드라면
    if(tree[idx].empty()){
        return;
    }

    // 왼쪽 자식 방문
    if (tree[idx][0] != '.') {
        inorder(tree[idx][0] - 65);
    }

    // 루트 방문 추가
    list.push_back(char(idx + 65));

    // 오른쪽 자식 방문
    if (tree[idx][1] != '.') {
        inorder(tree[idx][1] - 65);
    }
}

// 후위 순회
void postorder(int idx){
    // 트리에 없는 노드라면
    if(tree[idx].empty()){
        return;
    }

    for(int i = 0; i < 2; i++){
        if(tree[idx][i] != '.'){
            postorder(int(tree[idx][i]) - 65);
            list.push_back(tree[idx][i]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 노드 개수 n
    int n;
    cin >> n;

    // 트리 정보 입력
    for(int i = 0; i < n; i++){
        char head;
        cin >> head;
        for(int j = 0; j < 2; j++){
            char temp;
            cin >> temp;

            tree[int(head) - 65].push_back(temp);
        }
    }

    // 전위 순회
    preorder(route); 
    for(auto x : list){
        cout << x;
    }
    cout << '\n';
    list.clear();

    // 중위 순회
    inorder(route); 
    for(auto x : list){
        cout << x;
    }
    cout << '\n';
    list.clear();

    // 후위 순회
    postorder(route); 
    list.push_back('A');
    for(auto x : list){
        cout << x;
    }
}