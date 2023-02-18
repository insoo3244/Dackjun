#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < 2 * n - 1; i++){
        if(i < n){
            for(int j = 0; j < n; j++){
                if(j < n - i - 1){
                    cout << " ";
                }
                else{
                    cout << "*";
                }
            }
        }
        else{
            for(int k = 0; k < n; k++){
                if(k < i - n + 1){
                    cout << " ";
                }
                else{
                    cout << "*";
                }
            }
        }

        cout << endl;
    }
}