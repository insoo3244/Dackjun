// https://www.acmicpc.net/problem/11399
// 2026-02-09
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// DP 사용 ? 
/*
    dp 를 활용해보자
    피보나치 문제를 풀었을 때를 떠올려

    일단 리스트에 모든 인출시간을 받고, 정렬
    이후, dp에 인자를 넘김
    자료형 없음 dp(현재 탐색 인덱스, 사람 수, 지금까지 더한 시간){
        -> if(조건 : 현재 탐색 인덱스 < 사람 수){
            dp[현재 탐색 인덱스] = 지금까지 더한 시간 + list[현재 탐색 인덱스];
            return dp(현재탐색인덱스 + 1, 사람 수, 지금까지 더한 시간)
        } 아니면,{
            return; (함수 종료)
        }
    }

    출력은 
    for(int i = 0; i < n; i++){
        카운트 += dp_arr[i];
    }
    cout << 카운트;
*/


vector<int> list; // 인출하는 순서
int dp_arr[1000]; // 다이나믹 프로그래밍

// DP : 현재 탐색 인덱스, 사람 수, 지금까지 더한 시간
void dp(int idx, int n, int time){
    if(idx < n){
        dp_arr[idx] = time + list[idx];
        return dp(idx + 1, n, dp_arr[idx]);
    }
    else{
        return;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // 사람의 수
    int n;
    cin >> n;
    
    // 사람 수에 따라 인출할 시간 입력
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;

        list.push_back(temp);
    }

    sort(list.begin(), list.end()); // 정렬

    // 시간들을 합해서 dp에 저장
    dp(0, n, 0);

    // 출력
    int cnt = 0; // 시간 총 합
    for(int i = 0; i < n; i++){
        cnt += dp_arr[i];
    }
    cout << cnt;
}