#include <iostream>
using namespace std;

int main(){
    int k;
    cin >> k;
    int n;
    int max = 0;
    int min = 100;
    int gap = 0;
    int temp;

    for(int i = 0; i < k; i++){
        cin >> n;
        
        int* s = new int[n];
        for(int j = 0; j < n; j++){
            cin >> s[j];
            
            if(s[j] >= max){
                max = s[j];
            }

            if(s[j] <= min){
                min = s[j];
            }
        }

        for(int j = 0; j < n - 1; j++){
            for(int l = 0; l < n - j - 1; l++){
                if(s[l] < s[l + 1]){
                    temp = s[l];
                    s[l] = s[l + 1];
                    s[l + 1] = temp;
                }
            }
        }

        for(int j = 0; j < n - 1; j++){
            if(s[j] - s[j + 1] >= gap){
                gap = s[j] - s[j + 1];
            }
        }

        cout << "Class " << i + 1 << endl;
        cout << "Max " << max;
        cout << ", Min " << min;
        cout << ", Largest gap " << gap << endl;

        gap = 0;
        max = 0;
        min = 100;
        temp = 0;
        delete[] s;
    }
}