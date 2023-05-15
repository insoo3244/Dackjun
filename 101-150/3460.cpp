#include <iostream>
using namespace std;

int main(){
    int t;
    int n;
    int c = 0;
    int origin = 0;

    cin >> t;

    while(t--){    
        cin >> n;
        origin = n;

        while(n >= 1){
            n = n / 2;
            c++;
        }

        n = origin;
        int* array = new int[c];
        array[0] = 1;
        for(int i = 1; i <= c; i++){
            if(n % 2 == 1){
                array[c - i] = 1;
            }
            else{
                array[c - i] = 0;
            }

            n = n / 2;
        }

        for(int i = 0; i < c; i++){
            if(array[c - 1 - i] == 1){
                cout << i << " ";
            }
        }

        c = 0;
        delete[] array;
    }
}