#include <iostream>

using namespace std;

int main(){
    int b;
    int d;
    int min = 2001;
    int sum = 0;

    for(int i = 0; i < 3; i++){
        cin >> b;
        if(b < min){
            min = b;
        }
    }
    
    sum = min;
    min = 2001;

    for(int i = 0; i < 2; i++){
        cin >> d;
        if(d < min){
            min = d;
        }
    }

    cout << sum + min - 50;
}