#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < 2 * n - 1; i++){
        if(i < n){
            for(int j = 0; j < 2 * n - 1; j++){
                if(j >= i && j <= 2 * n - 2 - i){
                    cout << "*";
                    if(j == 2 * n - 2 - i){
                        break;
                    }
                }
                else{
                    cout << " ";
                }
            }
        }
        else{
            for(int k = 0; k < 2 * n - 1; k++){
                if(k >= 2 * n - i - 2 && k <= i){
                    cout << "*";
                    if(k == i){
                        break;
                    }
                }
                else{
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
}