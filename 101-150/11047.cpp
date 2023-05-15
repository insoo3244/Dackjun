#include <iostream>
using namespace std;

int main(){
    int n;
    int k;
    int a;
    int check = 0;
    int max = 0;

    cin >> n >> k;
    int* arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    while(k != 0){
        for(int i = 0; i < n; i++){
            if(arr[i] >= max && arr[i] <= k){
                max = arr[i];
            }
        }

        k -= max;
        check++;
        max = 0;
    }

    cout << check;
    delete[] arr;
}