#include <iostream>
using namespace std;

int main(){
    string a;
    cin >> a;
    int c = 0;

    for(int i = 0; i < a.size(); i++){
        if(a[i] == 97 || a[i] == 101 || a[i] == 105 || a[i] == 111 || a[i] == 117){
            c++;
        }
    }

    cout << c;
}