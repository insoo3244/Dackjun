#include <iostream>
using namespace std;

int main(){
    int a, b, c = 0;

    cin >> a >> b;
    
    int d = a;
    int pd = b;

    if(a > b){
        while(a % b != 0){
            c = a % b;
            a = b;
            b = c;
        }

        cout << b << endl;
        cout << d * pd / b;
    }
    else{
        while(b % a != 0){
            c = b % a;
            b = a;
            a = c;
        }

        cout << a << endl;
        cout << d * pd / a;
    }
}