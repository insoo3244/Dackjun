#include <iostream>
using namespace std;

int main(){
    string a;
    
    int n;
    cin >> n;

    while(n--){
        cin >> a;
        cout << a[0] << a[a.size() - 1];
        cout << endl;
    }
}