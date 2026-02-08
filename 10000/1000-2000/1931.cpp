// https://www.acmicpc.net/problem/1931
// 2026-02-08
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    전략
    일단 정렬
    
    dfs를 돌려서 완전탐색을 하자
    -> 일단 list 대상 반복문 시작 시, list의 첫 요소를 meet에 푸쉬
    -> 이후 dfs 시작.
    -> meet.back() 의 다음 요소는 해당 회의가 끝나는 시간 이후, 가장 빨리 시작하는 회의
    -> 해당 회의를 푸쉬하고, 재귀 시작
    -> 더 이상 푸쉬할 회의가 없을 때 탈출

    -> 시간이 너무 오래걸려!!!!!!! 최대 n이 10만인데, 10만번 전부 dfs를 돌려버리면 시간초과임

    반복계수를 정해놓고 탐색이 끝날 때 까지 쭉 반복하면서 반복계수 수정
    -> 1. for 안에 while을 해보자 2. while(1)을 해보자
    -> 첫 인덱스를 기준으로 가능한 스케쥴 탐색하기
    -> 이게 dfs랑 다를 게 뭐임?
    -> 매 순간 최선의 선택만 족족 골라서 maxValue를 구하면, 시간이 그나마 덜 걸리게 될 것임
    -> 아니 내가 한 건 최선의 선택이 아니었음;;

    최선의 선택을 위한 알고리즘 : 반복문 1회 안에 모든걸 해결하기
    -> 시작점 고르고 반복문 시작
    -> 틀린 생각 : 시작 회의마다 회의 가능한 모든 경우의 수를 연산해야하니 이중 반복문을 해야겠다.
    -> 맞는 생각 : 아하, 어차피 종료 시간 오름차순 정렬을 했으니,
        종료 시간 = 0; 변수를 이용해서, O(n) 스캔으로 한 번만 훑으면 되겠구나.
*/

vector<pair<int,int>> list; // 회의 시간 리스트

// 정렬 기준 : 
// 회의가 끝난 후, 가장 빨리 시작하는 회의 중, 가장 빠르게 끝나는 회의를 찾아야 하므로,
// 우선, 각 페어의 second 요소가 오름차순으로 정렬 되어야 함
// second요소가 동일할 경우, first 요소가 오름차순으로 정렬 되게끔 해야 함
bool comp(const pair<int,int> &a, const pair<int,int> &b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    else{
        return a.second < b.second;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // 회의 수
    int n;
    cin >> n;

    // 회의 시간 입력
    for(int i = 0; i < n; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        
        list.push_back({temp1, temp2});
    }

    sort(list.begin(), list.end(), comp); // 정렬

    int endtime = 0; // 회의 종료 시간
    int cnt = 0; // 가능한 회의 개수
    
    // 탐색 시작
    for(int i = 0; i < n; i++){
        if(list[i].first >= endtime){ // 만약 회의 시작 시간이 현재 회의 종료 시간과 맞아 떨어지면,
            endtime = list[i].second; // 회의 종료 시간 갱신
            cnt++; // 가능한 회의 개수 + 1
        }
    }

    // 최대 회의 개수 출력
    cout << cnt;
}