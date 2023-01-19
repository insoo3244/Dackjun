#include <iostream>
using namespace std;

int main(){
    int v;
    cin >> v;
    char* t = new char[v];
    int scra = 0;
    int scrb = 0;

    for(int i = 0; i < v; i++){
        cin >> t[i];
        if(t[i] == 'A'){
            scra++;
        }
        else{
            scrb++;
        }
    }

    if(scra > scrb){
        cout << "A";
    }
    else if(scrb > scra){
        cout << "B";
    }
    else{
        cout << "Tie";
    }

    delete[] t;
}