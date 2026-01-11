#include <iostream>
#include <string>
using namespace std;

int main(){
    // string a;
    // getline(cin, a);

    // cout << a[0];
    
    int t;
    cin >> t;
    cin.ignore();

    string a;
    while(t--){
        getline(cin, a);
        a[0] = a[0] >= 97 && a[0] <= 122 ? a[0] -= 32 : a[0];
        
        for(int i = 0; i < a.size(); i++){
            cout << a[i];
        }

        cout << endl;
    }
}