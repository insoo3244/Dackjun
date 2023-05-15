#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    char* a = new char[n];
    int* arr = new int[n];
    int sum = 0;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        arr[i] = a[i] - '0';
        sum += arr[i];
    }    

    cout << sum;
    delete[] a;
    delete[] arr;
}