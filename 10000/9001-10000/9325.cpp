#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;

    int s;
    int n;
    int q, p;

    int sum = 0;
    while(t--){
        cin >> s;
        cin >> n;
        
        while(n--){
            cin >> q >> p;
            sum += q * p;
        }

        cout << sum + s << endl;
        sum = 0;
    }
}