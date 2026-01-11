#include <iostream>
using namespace std;

int main(){
    string a;
    cin >> a;
    int check = 0;

    for(int i = 0; i < a.size(); i++){
        if(a[i] == 44){
            check++;
        }
    }

    cout << check + 1;
}