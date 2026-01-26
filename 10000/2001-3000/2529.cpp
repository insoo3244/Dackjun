// https://www.acmicpc.net/problem/2529
// 2026-01-26
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
    전략 구상

    부등호를 임의의 숫자만큼 입력받고,
    그 부등호의 관게에 맞는 수열을 구할 건데,
    이 수열의 최댓값과 최솟값을 구할 것임
        -> 일단 dfs로 백트래킹 구조 만들기.

    논리 구조
    1. 일단 조합대에 첫 번째 숫자 등록
    2. 첫 번째 부등호의 관계에 맞는 다음 숫자 등록
        -> 넘버셋 : 사용한 숫자는 true로 변경
    3. 쭉쭉 탐색하여 최대깊이에 도달 (부등호 개수 + 1)
    4. 숫자를 모두 이어붙여서 최대,최소 비교
    5. 이후 백트레킹 구조에 의해 모든 탐색을 마칠 때 까지 재귀

    부등호 사이사이 들어갈 수는 int 형이지만,
    숫자들을 전부 이어붙일 때에는 string 이어야 하며,
    대소 비교를 할 때에는 이어붙인 string을 다시 int로 바꾸고,
    출력을 할 때에는 다시 string으로 변환해서 출력해야 함
        -> 맨 앞자리가 0일 경우 0을 포함해서 출력해야하기 때문

    재귀할 때 마다 최댓값 최솟값을 갱신해주기
*/

vector<bool> numset(10, false); // 0 ~ 9 까지 사용 여부
vector<char> vec; // 부등호 저장 벡터
vector<int> craft; // 숫자 조합대

// 최댓값 최솟값
long long int mx_value = 0;
long long int mn_value = 10000000000; // 다행히 int 최대 값을 넘지 않음

// 탐색 함수
// 인자 : 부등호 개수 k, 현재 보유 숫자 개수 r
void dfs(int k, int r){
    // 조합대에 아무 숫자가 없을 때
    if(r == 0){
        for(int i = 0; i < 10; i++){
            // 방문 체크
            numset[i] = true;

            // 조합대에 숫자를 올리고, 재귀
            craft.push_back(i);
            dfs(k, craft.size());

            // 백 트레킹
            craft.pop_back();
            numset[i] = false;
        }   
    }

    if((r > 0 && r < k + 1)){ // 조합대에 숫자가 하나라도 들어가있을 때
        for(int i = 0; i < 10; i++){
            // 방문체크
            if(numset[i] == true){
                continue;
            }
            numset[i] = true;

            // 부등호가 성립하는 숫자를 조합대에 등록 후 재귀
            if(vec[r - 1] == '>'){
                if(craft.back() > i) craft.push_back(i);
                else {
                    numset[i] = false;
                    continue;
                }
            }
            else{
                if(craft.back() < i) craft.push_back(i);
                else {
                    numset[i] = false;
                    continue;
                }
            }
            dfs(k, craft.size());

            // 백 트레킹
            craft.pop_back();
            numset[i] = false;
        }
    }
    else if(r == k + 1){ // 조합대가 꽉 차면
        // 숫자들을 조합하기 위한 형변환 (int(-> char) -> string)
        string crfting;
        for(auto x : craft){
            char temp = (char)(x + 48);
            crfting += temp;
        }

        // 대소비교를 위한 형변환 (string -> int)
        long long int type_i = stoll(crfting);

        if(type_i > mx_value) mx_value = type_i;
        if(type_i < mn_value) mn_value = type_i;

        return;
    }
}


int main(){
    // 부등호 개수 입력
    int k;
    cin >> k;

    // 부등호 입력
    for(int i = 0; i < k; i++){
        char temp;
        cin >> temp;
        vec.push_back(temp);
    }

    // 탐색 시작
    dfs(k, 0);

    // 출력을 위한 형변환 (int -> string)
    string mx = to_string(mx_value);
    string mn = to_string(mn_value);

    // 최댓값 최솟값 자릿수에 부족한 0을 붙여서 출력
    for(int i = 0; i < (k + 1) - (int)mx.size(); i++){
        cout << '0';
    }   
    cout << mx << '\n';
    for(int i = 0; i < (k + 1) - (int)mn.size(); i++){
        cout << '0';
    }
    cout << mn;
}   