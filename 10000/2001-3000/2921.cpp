#include <iostream>
using namespace std;

int main(){
    int n;
    int d;
    int sum = 0;

    cin >> n;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= i; j++){
            sum += i + j;
        }
    }

    cout << sum;
}