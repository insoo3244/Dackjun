#include <iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    int a[123];
    for(int i = 0; i < 123; i++){
        a[i] = -1;
    }

    for(int i = 0; i < s.length(); i++){
        if(a[s[i]] == -1){
            a[s[i]] = i;
        }
        else{
            continue;
        }
    }

    for(int i = 97; i < 123; i++){
        cout << a[i] << " ";
    }
}