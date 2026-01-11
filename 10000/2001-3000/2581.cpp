#include <iostream>
using namespace std;

int main(){
    int n;
    int m;
    int c = 0;
    int c2 = 0;
    int sum = 0;

    cin >> m >> n;
    int min = n;

    for(int i = m; i <= n; i++){
        for(int j = 2; j < i; j++){
            if(i % j == 0){
                c++;
                break;
            }
        }

        if(i == 1){
            c++;
        }
        
        if(c == 0){
            c2++;
            if(i < min){
                min = i;
            }

            sum += i;
        }

        c = 0;
    }
    
    if(c2 == 0){
        cout << "-1";
    }
    else{
        cout << sum << endl;
        cout << min;
    }
}