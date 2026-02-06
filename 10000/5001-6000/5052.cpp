// https://www.acmicpc.net/problem/5052
// 2026-02-06
#include <iostream>
#include <vector>
#include <algorithm>

/*
    새로 알아간 부분
    find()함수
    -> algorithm 헤더파일에 포함된 함수
    -> 특정 원소를 찾는 함수가 아니라, 문자열 내에서 특정 문자열을 찾는 함수
    -> 문자열.find(찾을 문자열) 형태로 사용
    근데 이걸 쓴게 아님
    
    내가 쓴 find()는 아래에 해당 됨
    -> '''''string 클래스'''''의 멤버 함수
    -> 특정 문자열이 처음으로 나타나는 위치의 인덱스를 반환
    -> 찾는 문자열이 없으면 string::npos 반환
    npos는 string 클래스에 정의된 정적 멤버 상수로, 일반적으로 -1로 정의되어 있음
    
*/

using namespace std;

vector<string> list; // 전화번호 목록

int main() {
    // ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // 테스트 케이스 t, 전화번호 수 n
    int t, n;
    cin >> t;

    // 전화번호 입력
    for (int i = 0; i < t; i++) {
        cin >> n;
        for (int j = 0; j < n; j++) {
                string phone;
                cin >> phone;
                list.push_back(phone);
        }

        sort(list.begin(), list.end()); // 사전 순 정렬

        // 접두어 검사
        bool isConsistent = true;
        for (int j = 0; j < n - 1; j++) {
            if (list[j + 1].find(list[j]) == 0) { // 접두어인 경우
                isConsistent = false;
                break;
            }
        }

        list.clear(); // 다음 테스트 케이스를 위해 초기화

        // 결과 출력
        if (isConsistent) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
}