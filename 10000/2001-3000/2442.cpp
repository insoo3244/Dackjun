#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        if(i == 0){
            for(int j = 0; j < n; j++){
                if(j == n - 1){
                    cout << "*";
                }
                else{
                    cout << " ";
                }
            }
        }
        else{
            for(int k = 0; k < 2 * n - 1; k++){
                if(k >= n - i - 1 && k <= n + i - 1){
                    cout << "*";
                    if(k == n + i - 1){
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