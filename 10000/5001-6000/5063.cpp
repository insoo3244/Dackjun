#include <iostream>
using namespace std;

int main(){
    int r, e, c;
    int t;

    cin >> t;
    
    while(t--){
        cin >> r >> e >> c;
        if(r + c < e){
            cout << "advertise" << endl;
        }
        else if(r + c == e){
            cout << "does not matter" << endl;
        }
        else if(r + c > e){
            cout << "do not advertise" << endl;
        }
    }
}