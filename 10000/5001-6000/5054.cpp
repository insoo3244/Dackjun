#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;

    int n, l;
    int org = 0;
    int max = -1;
    int min = 100;
    int sum = 0;

    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> l;
            if(i == 0){
                org = l;
            }
            else{
                if(l >= max){
                    max = l;
                }

                if(l <= min){
                    min = l;
                }
            }
        }

        if(org >= max && org >= min){
            sum = (org - min) * 2;
        }
        else if(org <= max && org <= min){
            sum = (max - org) * 2;
        }else{
            sum = (max - min) * 2;
        }

        cout << sum << endl;
        org = 0;
        max = -1;
        min = 100;
        sum = 0;
    }
}
