#include <iostream>
using namespace std;

int main(){
    string a, b;
    int n;
    cin >> n;
    int sub = 0;

    while(n--){
        cin >> a >> b;
        cout << "Distances: ";
        
        for(int i = 0; i < a.size(); i++){
            if(a[i] <= b[i]){
                cout << b[i] - a[i] << " ";
            }
            else{
                cout << b[i] + 26 - a[i] << " ";
            }
        }
        
        cout << endl;
    }
}