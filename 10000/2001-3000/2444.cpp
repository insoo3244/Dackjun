#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < 2 * n - 1; i++){
        if(i < n){
            for(int j = 0; j < 2 * n - 1; j++){
                if(j >= n - i - 1 && j <= n + i - 1){
                    cout << "*";
                    if(j == n + i - 1){
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
                if(k <= 2 * n - (i - n) - 3 && k >= i - n + 1){
                    cout << "*";
                    if(k == 2 * n - (i - n) - 3) {
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