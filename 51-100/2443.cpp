#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
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

        cout << endl;
    }
}