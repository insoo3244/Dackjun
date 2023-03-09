#include <iostream>
using namespace std;

int main(){
    int n = 3;
    int a[4];

    int cf = 0;
    int cb = 0;
    while(n--){
        for(int i = 0; i < 4; i++){
            cin >> a[i];
            if(a[i] == 0){
                cf++;
            }
            if(a[i] == 1){
                cb++;
            }
        }

        if(cf == 1){
            cout << "A" << endl;
        }
        else if(cf == 2){
            cout << "B" << endl;
        }
        else if(cf == 3){
            cout << "C" << endl;
        }
        else if(cf == 4){
            cout << "D" << endl;
        }
        else if(cb == 4){
            cout << "E" << endl;
        }

        cf = 0;
        cb = 0;
    }
}