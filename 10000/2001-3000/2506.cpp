#include <iostream>
using namespace std;

int main(){
    int n;
    int c = 0;
    int s = 0;

    cin >> n;
    int* d = new int[n];

    for(int i = 0; i < n; i++){
        cin >> d[i];

        if(d[i] == 1){
            c++;
            s += c;
        }
        else{
            c = 0;
        }
    }

    cout << s;
    delete[] d;
}