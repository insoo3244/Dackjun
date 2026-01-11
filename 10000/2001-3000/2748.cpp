#include <iostream>
using namespace std;

long long fiboarr[100] = {0, 1,};

long long f(int n){
    if(n == 0 || n == 1){
        return fiboarr[n];
    }
    else if(fiboarr[n] == 0){
        fiboarr[n] = f(n-1) + f(n-2);
    }

    return fiboarr[n];
}

int main(){
    int n;
    cin >> n;
    cout << f(n);
}