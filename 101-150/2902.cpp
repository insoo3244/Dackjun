#include <iostream>
using namespace std;

int main(){
    string a;
    cin >> a;
    
    cout << a[0];
    for(int i = 0; i < a.length(); i++){
        if(a[i] == 45){
            cout << a[i + 1];
        }
    }
}