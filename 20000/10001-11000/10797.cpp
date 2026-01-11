#include <iostream>
using namespace std;

int main(){
    int n;
    int i[5];
    int check = 0;
    cin >> n;
    for(int j = 0; j < 5; j++){
        cin >> i[j];

        if(i[j] == n){
            check++;
        }
    }

    cout << check;
}