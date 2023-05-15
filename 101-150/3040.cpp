#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n[9];
    int s[9];
    int temp;
    int sum = 0;

    for(int i = 0; i < 9; i++){
        cin >> n[i];
    }

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(j == i){
                continue;
            }

            for(int k = 0; k < 9; k++){
                if(k == i || k == j){
                    continue;
                }
                else{
                    sum += n[k];
                }
            }

            if(sum == 100){
                for(int k = 0; k < 9; k++){
                    if(k == i || k == j){
                        continue;
                    }
                    else{
                        cout << n[k] << endl;
                    }
                }

                return 0;
            }
            else{
                sum = 0;
            }
        }
    }
}