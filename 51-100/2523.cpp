#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < 2 * n - 1; i++){
        if(i < n){
            for(int j = 0; j < n; j++){
                cout << "*";
                if(j == i){
                    break;
                }
            }
        }
        else{
            for(int k = n; k > 0; k--){
                cout << "*";
                if(k == i - n + 2){
                    break;
                }
            }
        }

        cout << endl;
    }
}