#include <iostream>
using namespace std;

int main(){
    int t; 
    cin >> t;
    
    int sum = 0;
    int n;
    int m = 0;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> m;
            sum += m;
        }

        cout << sum << endl;
        sum = 0;
    }
}