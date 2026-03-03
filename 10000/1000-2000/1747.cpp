#include <iostream>
#include <string>

using namespace std;

bool not_prime[2000001]; // 소수 = 0, 소수 X = 1.

void sieve(){
    for(int i = 2; i < 2000001; i++){
        if(not_prime[i] == 0){
            for(int j = 2 * i; j < 2000001; j += i){
                not_prime[j] = 1;
            }
        }
    }
}
// 에라토스테네스의 체 알고리즘을 이용해, 소수를 판별하는 함수 -> notprime에 적용

bool pen(string s){
    int n = s.length();
    int m = s.length() / 2;

    for(int i = 0; i < m; i++){
        if(s[i] != s[n - 1 - i]){
            return false;
        }
    }

    return true;
}
// 팰린드롬 판별 함수

int main(){
    int n;
    cin >> n;
    not_prime[0] = 1;
    not_prime[1] = 1; // 소수가 아님을 미리 적용시킴
    sieve(); // 소수 판별

    string s;
    while(1){
        s = to_string(n); // n을 string 자료형으로 변환
        if(!not_prime[n] && pen(s)){ // 둘 다 만족하지 못 할 때, n++ 후 반복
            cout << s;
            break;
        }

        n++;
    }
}