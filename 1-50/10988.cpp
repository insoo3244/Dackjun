#include <iostream>
using namespace std;

int main(){
    string a;

    int count{ 0 };
    cin >> a;

    if(a.size() % 2 == 0){
        for(int i = 0; i < a.size() / 2; i++){
            if(a[i] == a[a.size() - 1 - i]){
                count++;
            }
        }

        if(a.size() / 2 == count){
            cout << "1";
        }
        else{
            cout << "0";
        }
    }
    else{
        for(int i = 0; i < (a.size() - 1) / 2; i++){
            if(a[i] == a[a.size() - 1 - i]){
                count++;
            }
        }

        if((a.size() - 1) / 2 == count){
            cout << "1";
        }
        else{
            cout << "0";
        }
    }
}