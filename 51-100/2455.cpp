#include <iostream>
using namespace std;

int main(){
    int n = 4;
    int in;
    int out;
    int p = 0;
    int max = 0;

    while(n--){
        cin >> out >> in;
        p = p + in - out;

        if(p >= max){
            max = p;
        }
    }

    cout << max;
}