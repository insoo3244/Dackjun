#include <iostream>
using namespace std;

int main(){
    int a[7];
    int min = 100;
    int sum = 0;

    for(int i = 0; i < 7; i++){
        cin >> a[i];

        if(a[i] % 2 != 0){
            sum += a[i];
            if(a[i] < min){
                min = a[i];
            }
        }
    }
    if(sum == 0){
        cout << "-1";
    }
    else{
        cout << sum << endl;
        cout << min;
    }
}