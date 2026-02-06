// https://www.acmicpc.net/problem/1764
// 2026-02-06
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/*
    새로 알게 된 사실

    set 자료 구조
    -> 선언 : set<자료형> 변수;
    -> 중복을 허용하지 않는 자료 구조
    -> 삽입, 삭제, 탐색이 logN 시간 복잡도를 가짐
    -> 내부적으로 이진 탐색 트리로 구현됨
    -> C++ STL에서는 <set> 헤더파일에 포함되어 있음
    -> s.find(변수) 으로 특정 원소 탐색 가능.
    -> 리턴 값이 iterator 형태, 못찾으면 s.end() 반환
    -> 인덱스 접근은 불가능

    binary_search() 함수
    -> algorithm 헤더파일에 포함된 함수
    -> find()와 다르게 정렬된 범위에서만 사용 가능하며, 리턴값이 bool형
*/

using namespace std;

// 듣, 보 명단
vector<string> set;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // 듣도 못한 사람 수 n, 보도 못한 사람 수 m
    int n, m;
    cin >> n >> m;
    
    // 듣도 못한 명단 입력
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        set.push_back(temp);
    }

    // set 정렬
    sort(set.begin(), set.end());

    // 보도 못한 명단 입력과 동시에, 듣도 못한 명단과 비교
    int cnt = 0; // 듣보잡 수
    vector<string> result; // 듣보잡 명단
    for(int i = 0; i < m; i++){
        string temp;
        cin >> temp;
        if(binary_search(set.begin(), set.end(), temp)){
            cnt++;
            result.push_back(temp);
        }
    }

    // 출력
    cout << cnt << '\n';
    sort(result.begin(), result.end()); // 사전 순 정렬
    for(auto x : result) {
         cout << x << '\n';
    }
}