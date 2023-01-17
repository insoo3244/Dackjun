#include <iostream>

using namespace std;

int main(){
    int a;
    int b;

    cin >> a >> b;

    while(1){
        if(a > b){
            cout << "Yes" << endl;
        }
        else if(a == 0 && b == 0){
            break;
        }
        else {
            cout << "No" << endl;
        }

        cin >> a >> b;
    }
}