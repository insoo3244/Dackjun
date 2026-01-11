#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    int v, e;

    while(t--){
        cin >> v >> e;
        cout << 2 - v + e << endl;
    }
}