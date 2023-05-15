#include <iostream>
using namespace std;

int main(){
    int t;
    int n = 5;
    int score[5];
    int sum = 0;
    int max = 0;
    int min = 100;
    int temp;

    cin >> t;
    while(t--){
        for(int i = 0; i < n; i++){
            cin >> score[i];
            }
        
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4 - i; j++){
                if(score[j] > score[j + 1]){
                    temp = score[j];
                    score[j] = score[j + 1];
                    score[j + 1] = temp;
                }
            }
        }
        
        for(int i = 1; i < 4; i++){
            if(score[i] >= max){
                max = score[i];
            }
            
            if(score[i] <= min){
                min = score[i];
            }
            
            sum += score[i];
        }

        if(max - min >= 4){
            cout << "KIN" << endl;
        }
        else{
            cout << sum << endl;
        }

        n = 5;
        max = 0;
        min = 100;
        sum = 0;
    }
}