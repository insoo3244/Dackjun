#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;

    int d;
    string w;

    while(t--){
        cin >> d;
        cin >> w;

        w[d - 1] = '\0';

        for(int i = 0; i < w.length(); i++){
            cout << w[i];
        }

        cout << endl;
    }
}