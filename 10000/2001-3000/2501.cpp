#include <iostream>
using namespace std;

int main(){
    int n, k;
    int c = 0;

    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            c++;
        }

        if(c == k){
            cout << i;
            break;
        }
    }

    if(c < k){
        cout << "0";
    }
}