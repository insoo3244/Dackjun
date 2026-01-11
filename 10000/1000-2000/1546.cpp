#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int max = 0;

    float* s= new float[n];
    for(int i = 0; i < n; i++){
        cin >> s[i];

        if(s[i] >= max){
            max = s[i];
        }
    }

    float sum = 0;
    for(int i = 0; i < n; i++){
        s[i] = (s[i] / max) * 100;
        sum += s[i];
    }

    cout << sum / float(n);
    delete[] s;
}