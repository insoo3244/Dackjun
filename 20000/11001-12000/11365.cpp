#include <iostream>
#include <string>
using namespace std;

bool check(string a){
    string b = "END";
    if(a == b){
        return false;
    }
    else{
        return true;
    }
}

string rev(string a){
    for(int i = a.length() - 1; i < a.length(); i--){
        cout << a[i];
    }

    cout << endl;
    return a;
}

int main(){
    string a;
    getline(cin, a);

    while(check(a)){
        rev(a);
        getline(cin, a);
    }
}