#include <iostream>
using namespace std;

int main(){
    int a[10];
    int count = 0;
    int d = 0;
    int check = 0;
    int b[10];

    for(int i = 0; i < 10; i++){
        cin >> a[i];
        a[i] = a[i] % 42;
        b[i] = -1;
    }

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(j == i){
                continue;
            }
            else{
                for(int k = 0; k < 10; k++){
                    if(a[i] == b[k]){
                        check++;
                        break;
                    }
                }
        
                if(check > 0){
                    continue;
                }
                else{
                    if(a[i] != a[j]){
                        count++;
                    }
                    else{
                        b[j] = a[j];
                        d++;
                    }
                }
            }
        }

        if(count >= 9){
            d++;
        }

        check = 0;
        count = 0;
    }

    cout << d;
}