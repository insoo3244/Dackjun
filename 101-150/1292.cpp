#include <iostream>
using namespace std;

int main(){
    int a, b;
    int check = 1;
    int before = 0;
    int d[1001];
    int r = 0;
    int sum = 0;

    cin >> a >> b;

    for(int i = 0; i < 1001; i++){
        d[i] = -1;
    }

    for(int i = 1; i <= 1000; i++){
        if(d[1000] != -1){
            break;
        }
        d[check] = i;
        before = check;
        check += i;
        for(int j = before; j < check; j++){
            if(d[1000] != -1){
                break;
            }
            d[j] = i;
        }
    }

    for(int i = a; i <= b; i++){
        sum += d[i];
    }  
    
    cout << sum;
}