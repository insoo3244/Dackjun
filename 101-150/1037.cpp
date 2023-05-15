#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int temp;

    int* d= new int[n];
    for(int i = 0; i < n; i++){
        cin >> d[i];
    }

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(d[j] > d[j + 1]){
                temp = d[j];
                d[j] = d[j + 1];
                d[j + 1] = temp;
            }
        }
    }

    cout << d[0] * d[n - 1];
    
}