#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int c = 0;
    int c2 = 0;
    int d;
    while(n--){
        cin >> d;
        if(d == 1){
            continue;
        }
        else if(d == 2){
            c2++;
            continue;
        }
        else{
            for(int i = 2; i < d; i++){
                if(d % i == 0){
                    c++;
                    break;
                }
            }
        }

        if(c == 0){
            c2++;
        }

        c = 0;
    }

    cout << c2;
}