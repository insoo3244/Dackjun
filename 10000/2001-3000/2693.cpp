#include <iostream>

using namespace std;

int main(){
    int a[10];
    int n = 3;
    int t;
    int temp;

    cin >> t;
    while(t--){
        for(int i = 0; i < 10; i++){
            cin >> a[i];
        }

        for(int i = 0 ; i < 9; i++){
            for(int j = 0; j < 9 - i; j++){
                if(a[j] > a[j + 1]){
                    temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }

        cout << a[7] << endl;
    }
}