#include <iostream>
using namespace std;

int main(){
    int n;
    int m;
    int sum = 0;
    int min = 100000000;

    cin >> n >> m;

    for(int i = 1; i * i <= m; i++){
        if(i * i >= n){
            sum += i * i;
            if(i * i < min){
                min = i * i;
            }
        }
    }
    
    if(sum == 0){
        cout << "-1";
    } 
    else{
        cout << sum << endl;
        cout << min;  
    }
    
}