#include <iostream>
using namespace std;

int main(){
    int n;
    int p;
    string s;
    int c;
    string name;
    int max{ 0 };
    
    cin >> n;
    while(n--){
        cin >> p;
        while(p--){
            cin >> c;
            cin >> s;

            if(c > max){
                max = c;
                name = s;
            }
        }
        
        cout << name << endl;
        max = 0;
    }
}