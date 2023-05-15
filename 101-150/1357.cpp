#include <iostream>
using namespace std;

int rev(int n){
    int copy = n;
    int check = 0;
    int mul = 1;
    while(copy >= 10){
        copy /= 10;
        check++;
    }
    
    int n2 = 0;
    int* arr = new int[check + 1];
    for(int i = 0; i < check + 1; i++){
        arr[i] = mul;
        mul *= 10;
    }
    
    int temp;
    mul = 10;
    for(int i = check; i >= 0; i--){
        if(i == 0){
            mul /= 10;
            n2 += (n / mul) * arr[i];
        } 
        else if(i == check){
            n2 += (n % mul) * arr[i];
        }
        else{
            temp = mul / 10;
            n2 += ((n % mul) / temp) * arr[i];
        }
        
        mul *= 10;
    }

    delete[] arr;
    return n2;
}

int main(){
    int x, y;
    cin >> x >> y;

    cout << rev(rev(x) + rev(y));
}