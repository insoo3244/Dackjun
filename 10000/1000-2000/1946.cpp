// https://www.acmicpc.net/problem/1946
// 2026-02-03
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    풀이 전략

    논리 구조
    1. 테스트 케이스 입력
    2. 지원자 수 입력
    3. 지원자 수 만큼 성적 입력

    합격자 수 결정 알고리즘
    1. 서류 성적 순으로 오름차순 정렬
    2. 서류 1등 pass 푸쉬
    3. 서류 1등 면접성적 (이하 temp) 저장
    4. temp보다 높은 성적을 보유한 지원자 전부 pass 푸쉬
    
    5. 면접 성적 순으로 오름차순 정렬
    6. 면접 1등 서류성적 (이하 temp) 저장
    7. temp보다 높은 성적을 보유한 지원자 중,
        이미 pass에 들어가있는 지원자면, cnt++ 

    8. cnt 출력
    ===================== 위에꺼 시간초과 뜸 =======================

    내부 논리만 다시 생각해보자
    pass를 따로 쓸 필요가 없음
    
    1. 서류 순 성적 정렬
    2. 서류 1등의 면접 성적(이하 temp) 저장
    3. 이후 탐색 부터 temp보다 성적이 좋은 지원자를 만날 때 마다 
        -> cnt++;
        -> temp 를 해당 지원자의 성적으로 갱신
    이렇게 하면, 한 번의 반복으로 모든 탐색이 가능함

    이후 cnt 출력
    
*/


// 서류 성적, 면접 성적 리스트 <서류,면접>
vector<pair<int,int>> list;


// 면접 성적 기준 오름차순 정렬
bool comp(const pair<int,int> &a, const pair<int,int> &b){
    return a.second < b.second;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 테스트 케이스, 지원자의 수
    int t, n;
    cin >> t;

    // 테스트 케이스 반복
    for(int i = 0; i < t; i++){
        // 직원 수 입력 후, 성적 입력
        cin >> n;
        for(int j = 0; j < n; j++){
            // 서류성적, 면접성적
            int dtem, item;
            cin >> dtem >> item;

            list.push_back({dtem, item});
        }

        // 서류 성적 순으로 정렬
        sort(list.begin(), list.end());

        // 서류 성적 1등의 면접 성적 저장
        int itv = list.front().second;
        int cnt = 0; // 합격자 수 카운트
        
        // 합격자 수 구하기
        for(auto x : list){
            if(x.second < itv){
                cnt++;
                itv = x.second;
            }
        }

        // 출력
        cout << cnt + 1 << endl;

        // 초기화
        list.clear();
        cnt = 0;
    }

}
