#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int p;
    int sum = 0;
    int check = 0;

    while(n--){
        cin >> p;
        sum += p;
        check++;
    }

    cout << sum - check + 1;
}