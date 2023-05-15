#include <iostream>

using namespace std;

int main(){
    int d[5];
    int sum = 0;
    int temp;

    for(int i = 0; i < 5; i++){
        cin >> d[i];
        sum += d[i];
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4 - i; j++){
            if(d[j] > d[j + 1]){
                temp = d[j];
                d[j] = d[j + 1];
                d[j + 1] = temp;
            }
        }
    }

    cout << sum / 5 << endl;
    cout << d[2];
}