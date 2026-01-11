#include <iostream>
using namespace std;

int main(){
    int f[21];
    f[0] = 0;
    f[1] = 1;

    for(int i = 2; i < 21; i++){
        f[i] = f[i - 1] + f[i - 2];
    }

    int n;
    cin >> n;
    cout << f[n];
}

// int f(int n){
//     if(n < 2){
//         return n;
//     }

//     int a[21];
//     a[0] = 0;
//     a[1] = 1;

//     for(int i = 2; i < 21; i++){
//         a[i] = a[i - 1] + a[i - 2];
//     }

//     return a[n];
// }

// int main(){
//     int n;
//     cin >> n;
//     cout << f(n);
// }