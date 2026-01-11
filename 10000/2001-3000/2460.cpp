#include <iostream>
using namespace std;

int main(){
    int p = 0;
    int in = 0; 
    int out = 0;
    int max = 0;

    for(int i = 0; i < 10; i++){
        cin >> out >> in;

        p = p - out + in;

        if(p >= max){
            max = p;
        }
    }

    cout << max;
}