// https://www.acmicpc.net/problem/3649
// 2026-02-05
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 블록의 길이 리스트
vector<int> list;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 구멍의 너비 x
    int x;

    // 구멍의 너비를 입력하는 것으로 반복문 시작
    // eof가 입력될 때 까지 무한 반복
    while(cin >> x){
        x *= 10000000;
        
        // 레고 조각 수 n
        int n;
        cin >> n;

        // 블록의 길이 입력 (나노미터)
        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;

            list.push_back(temp);
        }

        sort(list.begin(), list.end()); // 리스트 오름차순 정렬

        // 탐색은 양쪽에서 시작
        int start = 0; // 시작 포인터
        int end = n - 1; // 끝 포인터

        // 두 포인터가 서로 교차할 때 까지 반복
        // 답이 존재하지 않는 경우를 위한 bool isAns = false;
        bool isAns = false;
        while(start < end){
            int sum = list[start] + list[end]; // 두 포인터의 합

            if(sum == x){ // 합이 x면,
                cout << "yes " << list[start] << " " << list[end] << '\n'; // 출력
                isAns = true;
                break;
            }
            else if(sum > x){ // x를 넘으면,
                end--; // 앞으로 이동
            }
            else if(sum < x){ // x를 넘지 못하면,
                start++; // 뒤로 이동
            }
        }
        
        // 초기화
        list.clear();

        // 정답이 없다면,
        if(!isAns){
            cout << "danger" << '\n';
            continue;
        }
    }
}