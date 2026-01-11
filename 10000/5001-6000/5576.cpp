#include <iostream>
using namespace std;

int main(){
    int w[10];
    int k[10];
    int repeat = 0;
    int temp;
    
    while(repeat < 20){
        if(repeat < 10)
            cin >> w[repeat];
        else
            cin >> k[repeat - 10];
        
        repeat++;
    }
    
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9 - i; j++){
            if(w[j] > w[j + 1]){
                temp = w[j];
                w[j] = w[j + 1];
                w[j + 1] = temp;
            }
            
            if(k[j] > k[j + 1]){
                temp = k[j];
                k[j] = k[j + 1];
                k[j + 1] = temp;
            }
        }
    }

    cout << w[7] + w[8] + w[9] << " " << k[7] + k[8] + k[9];
}