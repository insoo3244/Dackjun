#include <iostream>
using namespace std;

int main(){
    int d[10];
    int sum = 0;
    int c = 0;
    int f = 0;
    int p = 0;

    for(int i = 0; i < 10; i++){
        cin >> d[i];

        sum += d[i];
    }

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(d[i] == d[j]){
                c++;
            }
        }

        if(c >= f){
            f = c;
            p = i;
        }

        c = 0;
    }
    
    cout << sum / 10 << endl;
    cout << d[p];
}