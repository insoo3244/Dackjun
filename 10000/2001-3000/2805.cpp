// https://www.acmicpc.net/problem/2805
// 2026-02-14
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> list; // 나무 길이 리스트

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 나무의 수 n, 가져갈 나무의 길이 m
    int n, m;
    cin >> n >> m;
    
    int maxMeter = 0;

    // 나무 길이 입력
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;

        if(temp > maxMeter){
            maxMeter = temp;
        }

        list.push_back(temp);
    }

    // 이분 탐색 준비물 low high
    int low = 0;
    int high = maxMeter;
    long long int sum = 0; // 자른 나무의 길이의 합
    maxMeter = 0;

    // sum과 m의 대소비교
    while(low <= high){
        int mid = (low + high) / 2; // 이분 탐색 mid

        // 나무를 mid 만큼 자른 길이 합
        for(auto x : list){
            if(x - mid < 0){
                continue;
            }

            sum += x - mid;
        }

        // sum 분기점
        if(sum >= m){
            if(mid > maxMeter){
                maxMeter = mid;
            }

            low = mid + 1;
        }
        else{
            high = mid - 1;
        }

        sum = 0;
    }

    cout << maxMeter;
}