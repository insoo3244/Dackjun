// https://www.acmicpc.net/problem/1759
// 2026-01-22
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<char> word;
vector<char> ans;

// 인자 : 출발점, 암호 길이, 문자 풀 수
void dfs(int idx, int l, int c) {
    // 1. 탈출 조건 (ans 크기가 L이면?)
    //    -> 모음/자음 개수 체크하고 출력 후 return

    if(ans.size() == l){
        int vo = 0; // 모음 개수
        int co = 0; // 자음 개수

        // 자음, 모음 개수 세기
        for(auto x : ans) {
            if((x == 'a') || (x == 'e') || (x == 'i') || (x == 'o') || (x == 'u')){
                vo++;
            }
            else{
                co++;
            }
        }
    
        // 조건에 맞으면 출력
        if(vo > 0 && co > 1){
            for(auto x : ans) 
                cout << x;
            
            cout << endl;
        }

        return;
    }

    // 2. 반복문 (idx부터 C까지)
    //    -> ans에 word[i] 넣기 (Push)
    //    -> 재귀 호출 (다음 인덱스는 i+1)
    //    -> ans에서 맨 뒤 요소 빼기 (Pop) -> 이게 핵심!
    for(int i = idx; i < c; i++){
        ans.push_back(word[i]);
        dfs(i + 1, l, c);
        ans.pop_back();
    }
}

int main(){
    // l : 자릿수, c : 문자 수
    int l, c;
    cin >> l >> c;

    // 문자 풀 입력하기
    for(int i = 0; i < c; i++){
        char temp;
        cin >> temp;
        word.push_back(temp);
    }

    // 정렬
    sort(word.begin(), word.end());

    // dfs 굴리기
    dfs(0, l, c);
}


// /*
// 전략 구상

// c 개의 문자 중에, l 개의 문자수로 구성된 암호
// 구성될 수 있는 모든 경우의 수 중에,
// 1. 사전순으로 구성될 것
// 2. 모음이 적어도 하나 이상 포함 될 것
// 위 조건을 충족하는 모든 문자열 출력하기

// 사전 순으로 구성되어야 하기 때문에 일단 오름차순 정렬

// 문자열의 자릿수, 조합에 이용되는 문자 수 모두 사용자의 임의 입력임
// 조건을 걸고 만족 시 탈출하는, 재귀를 통해서 풀어보자

// 전역변수 : 문자저장벡터, 재귀 카운트, 
// 1. 벡터에 입력한 문자 정렬
// 2. 재귀함수 (인자 : 자릿수, )
//     선두에 위치하는 문자를 기준으로 가능한 모든 경우의 수를 출력할 것
//     자릿수 만큼 재귀할 것임


// */

// vector<char> word; // 암호 저장 벡터
// vector<char> ans; // 가능한 문자열 저장 벡터

// // 단어 구성 함수 output
// // l = 자릿수, cnt = 선두문자 위치, size = 벡터 사이즈
// // rep = 재귀 횟수, vis = 방문 체크 배열 (참조)
// void output(int l, int cnt, int size, int rep, bool vis[]){
//     // 재귀 : ans에 단어 차곡차곡 쌓기
//     for(int i = cnt; i < size; i++){
//         if(vis[i] == false){
//             cout << word[i] << endl;
//             ans.push_back(word[i]); // 철자 하나 쌓기
//             *(vis + i) = true; // 방문 체크
//             rep++; // 반복횟수 증가
            
//             if(rep >= l){ // 재귀 횟수가 자릿수만큼 차면, 탈출
//                 break;
//             }

//             output(l, cnt, size, rep, vis);
//         }
//     }

//     if(rep >= l){ // 재귀 횟수가 자릿수만큼 차면, 탈출
//         return;
//     }

// }

// int main(){
//     // 자릿수, 문자 수 입력
//     int l, c;
//     cin >> l >> c;

//     // 방문체크 동적할당 배열 선언 및 초기화
//     bool* vis = new bool[c];
//     for(int i = 0; i < c; i++){
//         vis[i] = 0;
//     }

//     // 철자 입력 및 word에 저장
//     char temp;
//     for(int i = 0; i < c; i++){
//         cin >> temp;
//         word.push_back(temp);        
//     }

//     // 정렬
//     sort(word.begin(), word.end());
//     for(auto x : word) cout << x << " ";
//     cout << endl;
//     cout << word.size() << endl;
    
//     // 가능한 암호 출력 시작
//     int by = c - l + 1; // 여기까지 탐색
//     int cnt = 0; // 선두 문자 위치
//     int rep = 1; // 반복 횟수
//     while(cnt < by){ 
//         ans.push_back(word[cnt]); // ans에 선두문자 부터 저장
//         vis[cnt] = 1; // 방문체크까지
//         cout << word[cnt] << endl;

//         // 재귀 시작 : ans에 자릿수만큼 문자 채우기
//         output(l, cnt, word.size(), rep, vis);
        
//         // 모음 검사하기
//         bool isAns = false; // 모음이 있나?
//         for(auto x : ans) {
//             if((x == 'a') || (x == 'e') || (x == 'i') || (x == 'o') || (x == 'u')){
//                 isAns = true;
//                 break;
//             }
//         }

//         if(isAns){
//             for(auto x : ans) 
//                 cout << x;
            
//             cout << endl;
//         }
        
//         ans.clear();
//         for(int i = 0; i < c; i++){
//             vis[i] = false;
//         }

//         cnt++;
//         rep = 1;
//     }

//     delete[] vis;
// }