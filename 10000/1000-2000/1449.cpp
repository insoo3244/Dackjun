// https://www.acmicpc.net/problem/1449
// 2026-02-11
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> loc; // 물이 새는 곳

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // 물이 새는 곳 개수 n, 테이프의 길이 l
    int n, l;
    cin >> n >> l;

    // 물이 새는 곳의 위치 입력
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;

        loc.push_back(temp);
    }
    
    sort(loc.begin(), loc.end()); // 정렬

    int range = loc.front() + l - 1; // 내가 막을 수 있는 범위
    int cnt = 1; // 소모한 테이프 개수(공사 시작 부터 붙이고 1개 소모하고 시작)
    
    // 공사 시작
    for(int i = 0; i < n; i++){
        if(!(loc[i] <= range)){
            range = loc[i] + l - 1;
            cnt++;
        }
    }

    // 출력
    cout << cnt;
}