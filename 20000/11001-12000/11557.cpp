#include <iostream>
#include <string>
using namespace std;

int main(){
    int t;
    int n;
    int l;
    string name;
    int max = 0;
    string check;
    
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> name;
            cin >> l;
            if(l > max){
                max = l;
                check = name;
            }
        }

        cout << check << endl;

        max = 0;
    }
}