// https://www.acmicpc.net/problem/1026
// 2026-02-10
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 입력받을 배열
vector<int> a;
vector<int> b;

bool comp(const int &a, const int &b){
    return a > b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // 배열의 길이
    int n;
    cin >> n;

    // a와 b 배열 입력
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;

        a.push_back(temp);
    }

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;

        b.push_back(temp);
    }

    // 정렬
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), comp);

    int sum = 0; // 수들의 합
    for(int i = 0; i < n; i++){
        sum += a[i] * b[i];
    }

    // 출력
    cout << sum;
}