#include <iostream> 
using namespace std;

int main(){
    int r = 0;
    int num;
    int d = 0;
    int max = 0;

    for(int i = 1; i <= 5; i++){
        for(int j = 0; j < 4; j++){
            cin >> num;
            d += num;
        }

        if(d >= max){
            max = d;
            r = i;
        }

        num = 0;
        d = 0;
    }

    cout << r << " " << max;
}