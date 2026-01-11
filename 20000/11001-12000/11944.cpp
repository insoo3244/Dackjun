#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    string s;
    int check = 0;

    for(int i = 0; i < n; i++){
        s += to_string(n);
    }

    if(s.length() > m){
        cout << s.substr(0, m);
    }
    else{
        cout << s;
    }
    // while(check < m){
    //     for(int j = 0; j < n.length(); j++){
    //         if(check >= m){
    //             break;
    //         }

    //         cout << n[j];
    //         check++;
    //     }
    // }
}