#include <iostream>
using namespace std;

int main(){
    int n{ 0 };
    int a, b, c;
    int p{ 0 };

    cin >> n;
    int* arr = new int[n];
    int size{ n };
    while(n > 0){
        cin >> a >> b >> c;

        if(a == b && b == c){
            arr[p] = 10000 + a * 1000;
        }
        else if(a == b || a == c){
            arr[p] = 1000 + a * 100;
        }
        else if(b == c){
            arr[p] = 1000 + b * 100;
        }
        else{
            if(a >= b){
                if(a >= c){
                    arr[p] = a * 100;
                }
                else{
                    arr[p] = c * 100;
                }
            }
            else{
                if(b >= c){
                    arr[p] = b * 100;
                }
                else{
                    arr[p] = c * 100;
                }
            }
        }

        p++;
        n--;
    }

    int max{ arr[0] };
    for(int i = 0; i < size; i++){
        if(arr[i] >= max){
            max = arr[i];
        }
    }

    cout << max;

    delete[] arr;
}