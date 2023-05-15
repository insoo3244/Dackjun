#include <iostream>
using namespace std;

int main(){
    string a;
    cin >> a;

    int arr[91] = {0, };
    for(int i = 0; i < a.size(); i++){
        a[i] = a[i] < 97 ? a[i] : a[i] - 32;
        arr[int(a[i])]++;
    }

    int max = 0;
    int temp = 0;
    int check = 0;
    for(int i = 65; i < 91; i++){
        if(arr[i] > max){
            max = arr[i];
            temp = i;
        }
    }

    for(int i = 65; i < 91; i++){
        if(arr[i] == max){
            check++;
        }
    }

    if(check > 1){
        cout << "?";
    }
    else{
        cout << char(temp);
    }
}