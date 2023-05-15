#include <iostream>
#include <string>
using namespace std;

// int count(string a){
//     int check = 0;
//     for(int i = 0; i < a.size(); i++){
//         if(a[i] == '0'){
//             check++;
//         }
//     }

//     return check;
// }

int count(string a, string b){
    int num1 = stoi(a);
    int num2 = stoi(b);
    int check = 0;
    string sub;

    for(int i = num1; i <= num2; i++){
        sub = to_string(i);
        for(int j = 0; j < sub.size(); j++){
            if(sub[j] == '0'){
                check++;
            }
        }
    }

    return check;
}

int main(){
    int n;
    cin >> n;

    string a;
    string b;

    while(n--){
        cin >> a >> b;
        
        cout << count(a, b) << endl;
    }
}