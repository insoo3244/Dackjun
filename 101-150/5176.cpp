#include <iostream>
using namespace std;

int main(){
    int k;
    cin >> k;

    int p;
    int m;
    int seat = 0;
    int check = 0;

    while(k--){
        cin >> p >> m;
        bool* s = new bool[m + 1];
        for(int i = 0; i < m + 1; i++){
            s[i] = false;
        }

        while(p--){
            cin >> seat;
            if(seat > m){
                check++;
                continue;
            }

            if(s[seat] == false){
                s[seat] = true;
            }
            else{
                check++;
            }
        }

        cout << check << endl;
        check = 0;
        delete[] s;
    }
}