// https://www.acmicpc.net/problem/2003
// 2026-02-13
#include <iostream>
#include <vector>

using namespace std;

vector<int> list; // 숫자 리스트

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // 배열의 크기 n, 목표 m
    int n, m;
    cin >> n >> m;

    // 숫자 입력
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;

        list.push_back(temp);
    }

    int sum = 0; // 수의 합
    int cnt = 0; // 경우의 수

    // 투 포인터
    int first = 0;
    int second = 0;
    
    // 반복 시작
    /*
        1. sum과 m 비교
            1) sum < m : sum += list[second], second++
            2) sum >= m : cnt++(sum == m), sum -= list[first], first++;
        2. n이 second에 도달하면
            1) first++; sum -= list[first]
            2) sum이 m보다 작아질 때 종료
    */
    while(1){
        if(sum >= m){
            if(sum == m) { cnt++; }

            sum -= list[first];
            first++;
        }
        else if(second == n){
            if(sum < m){
                break;
            }
        }
        else{
            sum += list[second];
            second++;
        }
    }

    // 출력
    cout << cnt;
}