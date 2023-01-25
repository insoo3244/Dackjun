#include <iostream>
using namespace std;

int main(){
    int n;
    int p{ 0 };


    cin >> n;
    while(n != -1){
        int* arr = new int[n];
        for(int i = 1; i < n; i++){
            if(n % i == 0){
                arr[p++] = i;
            }
        }

        int sum = 0;
        for(int i = 0; i < p; i++){
            sum += arr[i];
        }

        if(sum == n){
            cout << n << " = ";
            for(int i = 0; i < n; i++){
                if(i == p - 1){
                    cout << arr[i];
                    break;
                }
                else{
                    cout << arr[i] << " + ";
                }
            }

            cout << endl;
        }
        else{
            cout << n << " is NOT perfect." << endl;
        }

        sum = 0;
        p = 0;
        delete[] arr;

        cin >> n;
    }
}