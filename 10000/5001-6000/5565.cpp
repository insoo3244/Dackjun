#include <iostream>
using namespace std;

int main(){
    int n;
    int a[9];

    int s = 0;
    cin >> n;
    for(int i = 0; i < 9; i++){
        cin >> a[i];
        s += a[i];
    }

    cout << n - s;
}