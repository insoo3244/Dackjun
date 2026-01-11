#include <iostream>
#include <string>
using namespace std;

string rot(string a){
    for(int i = 0; i < a.size(); i++){
        if(a[i] >= 78 && a[i] <= 90){
            a[i] -= 13;
        }
        else if(a[i] >= 65 && a[i] <= 77){
            a[i] += 13;
        }
        else if(a[i] >=97 && a[i] <= 109){
            a[i] += 13;
        }
        else if(a[i] >= 110 && a[i] <= 122){
            a[i] -= 13;
        }
    }

    return a;
}

int main(){
    string a;
    getline(cin, a);

    cout << rot(a);
}