#include <iostream>
#include <cmath>
using namespace std;
//1시간 20분
int main(){
    int n;
    int p = 0;
    int sum = 0;

    cin >> n;
    while(n != -1){
        int* arr = new int[n];
        for(int i = 1; i < n; i++){
            if(n % i == 0){
                arr[p++] = i;
                sum += i;
            }
        }

        if(sum == n){
            cout << n << " = ";
            for(int i = 0; i < p; i++){
                if(i != p - 1){
                    cout << arr[i] << " + ";
                }
                else{
                    cout << arr[i];
                }
            }

            cout << endl;
        }
        else{
            cout << n << " is NOT perfect." << endl;
        }

        p = 0;
        sum = 0;
        cin >> n;
        delete[] arr;
    }
}