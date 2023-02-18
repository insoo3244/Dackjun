#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < 2 * n - 1; i++){
        if(i < n){
            for(int j = 0 ; j < 2 * n; j++){
                if(j >= i + 1 && j < 2 * n - i - 1){
                    cout << " ";
                }
                else{
                    cout << "*";
                }
            }
        }
        else{
            for(int k = 0; k < 2 * n; k++){
                if(k < 2 * n - i - 1 || k > i){
                    cout << "*";
                }
                else{
                    cout << " ";
                }
            }
        }

        cout << endl;
    }
}