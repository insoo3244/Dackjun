#include <iostream>
using namespace std;

int main(){
    int a = 100;
    int b = 100;
    int n;
    int d1;
    int d2;
    
    cin >> n;
    while(n--){
        cin >> d1 >> d2;
        if(d1 > d2){
            b -= d1;
        }
        else if(d1 == d2){

        }
        else{
            a -= d2;
        }
    }

    cout << a << endl;
    cout << b;
}