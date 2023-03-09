#include <iostream>
using namespace std;
int main(){
    int n;
    int d;
    int sum = 0;

    cin >> n;
    for(int i = 0; i < n; i++){
        cout << i << "번째 정수 입력: ";
        cin >> d;
        sum += d;
    }

    cout << "합계: " << sum;
}