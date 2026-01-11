#include <iostream>
using namespace std;

int main(){
    int t;
    int c, v;

    cin >> t;
    while(t--){
        cin >> c >> v;
        cout << "You get " << c / v << " piece(s) and your dad gets " << c % v <<  " piece(s)." << endl;
    }
}