#include <iostream>
using namespace std;

int main(){
    string a;
    int n;
    int scr{ 0 };
    int check{ 0 };

    cin >> n;
    while(n--){
        cin >> a;

        for(int i = 0; i < a.size(); i++){ 
            if(a[i] == 'O'){
                scr++;
                if(check != 0){
                    scr = scr + check;
                }

                check++;
            }
            else{
                check = 0;
            }
        }

        cout << scr << endl;
        scr = 0;
        check = 0;
    }
}