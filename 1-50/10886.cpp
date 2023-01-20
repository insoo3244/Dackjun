#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int* t = new int[n];
    int i{ 0 };
    int count0{ 0 };
    int count1{ 0 };

    while(n--){
        cin >> t[i];
        if(t[i] == 0){
            count0++;
        }
        else{
            count1++;
        }
    }

    if(count0 > count1){
        cout << "Junhee is not cute!";
    }
    else{
        cout << "Junhee is cute!";
    }
}