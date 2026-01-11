#include <iostream>
using namespace std;

int main(){
    string a;
    cin >> a;

    int arr[123] = {0, };

    for(int i = 0; i < a.size(); i++){
        arr[int(a[i])]++;
    }

    for(int i = 97; i < 123; i++){
        cout << arr[i] << " ";
    }
}