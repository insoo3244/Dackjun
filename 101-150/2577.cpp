#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    int n;
    int t = 1;
    int p = 0;

    cin >> a >> b >> c;
    n = a * b * c;
    
    while(1){
        if(t > n){
            break;
        }
        else{
            t *= 10;
        }

        p++;
    }

    t = 10;
    int* d = new int[p];
    for(int i = 0; i < p; i++){
        if(i == 0){
            d[i] = n % t;
        }
        else if(i == p - 1){
            d[i] = n / (t / 10);
        }
        else{
            d[i] = n % t == 0 ? 0 : (n % t) / (t / 10);
        }

        t *= 10;
    }

    int num[10]{ 0 };
    for(int i = 0; i < p; i++){
        switch(d[i]){
            case 0:
                num[0]++;
                break;
            case 1:
                num[1]++;
                break;
            case 2:
                num[2]++;
                break;
            case 3:
                num[3]++;
                break;
            case 4:
                num[4]++;
                break;
            case 5:
                num[5]++;
                break;
            case 6:
                num[6]++;
                break;
            case 7:
                num[7]++;
                break;
            case 8:
                num[8]++;
                break;
            case 9:
                num[9]++;
                break;
            default:
                break;
        }
    }

    for(int i = 0; i < 10; i++){
        cout << num[i] << endl;
    }
}