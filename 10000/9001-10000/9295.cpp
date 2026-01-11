#include <iostream>
using namespace std;

int main(){
    int t;
    int b, d;

    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> b >> d;
        cout << "Case " << i << ": " << b + d << endl;
    }
}