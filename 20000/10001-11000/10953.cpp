#include <iostream>
#include <string>
using namespace std;

int main(){
    int t;
    cin >> t;

    char c[3];
    int n, n2;
    int sum = 0;
    while(t--){
        for(int i = 0; i < 3; i++){
            cin >> c[i];
        }

        n = c[0] - '0';
        n2 = c[2] - '0';

        sum = n + n2;
        cout << sum << endl;
        sum = 0;
    }
}