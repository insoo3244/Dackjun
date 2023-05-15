#include <iostream>
using namespace std;

int main(){
    long long n[3];
    int temp;

    for(int i = 0; i < 3; i++){
        cin >> n[i];
    }

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2 - i; j++){
            if(n[j] > n[j + 1]){
                temp = n[j];
                n[j] = n[j + 1];
                n[j + 1] = temp;
            }
        }
    }

    for(int i = 0; i < 3; i++){
        cout << n[i] << " ";
    }
}