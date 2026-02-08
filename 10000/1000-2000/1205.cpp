// https://www.acmicpc.net/problem/1205
// 2026-02-04
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    어떻게 풀까

    점수를 전부 받아냄
    일단 내 점수가 들어갈 자리를 찾아야 함

    지금까지 받은 리스트에 내가 넣은 점수도 추가함
    그 다음 내림차순 정렬

    내 점수에 해당되는 인덱스 찾기 -> 문제 해결

    출력 : 
    인덱스 번호 + 1 을 출력해서 내 등수 출력
        -> 근데 점수판이 꽉차서 안드감
            -> 내 점수가 맨 끝자락이다 ? -1 출력
            -> 그게 아니면, 인덱스 번호 + 1 출력
        
        -> 드가긴 했는데 나랑 동점자가 있음 
            -> 걔랑 나랑 같은 등수 판정
    
    ==== 시간초과 발생 -> 다시 생각해보기 ====
    
    등수를 찾는 방법 : '나보다 점수가 높은 사람 수 + 1' 또한 등수를 의미함

*/


bool comp(const int &a, const int &b){
    return a > b;
}

int main(){
    // 리스트에 있는 점수 n개, 점수 score, 점수 최대 개수 p
    int n, score, p;
    cin >> n >> score >> p;

    // 점수 리스트 및 내 점수 투입
    vector<int> list;

    // 점수 입력
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        list.push_back(temp);
    }

    // 점수 정렬 내림차순
    sort(list.begin(), list.end(), comp);

    // 점수판이 꽉 차있을 때, (그리고 점수판에 등록된 점수가 적어도 1개 이상일 때)
    if(n == p && n > 0){ // n = 0 이면, 아래 조건문에서 아웃오브바운드가 생길 수 있음
        if(*(list.end() - 1) >= score){ // 맨 마지막 성적이 내 점수와 같다면,
            cout << "-1"; // 내 점수는 점수판에 들어가지 못함
            return 0;
        }
    }
    else if (n == 0){
        cout << "1";
        return 0;
    }

    // 탐색 시작
    int cnt = 0; // 나 보다 등수가 높은 사람 수
    for(auto x : list){
        if(x > score){
            cnt++;
        }
    }
    
    cout << cnt + 1;
}