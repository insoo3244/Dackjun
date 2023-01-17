#include <iostream>
using namespace std;

int main(){
    int a;
    int b;

    int t;
    cin >> t;

    while(t--){
        cin >> a >> b;
        if(a == 1 || b == 1){
            cout << a * b << endl;
        }
        else{
            int i = 2;
            int l = 2;
            int p{1};
            int q{1};
            while(1){
                while(a % i == 0 && b % i == 0){
                    a = a / i;
                    b = b / i;
                    p = p * i;
                }

                i++;
                if(a < i || b < i){
                    break;
                }
            }
            cout <<  p * a * b << endl;
        }
    }
}