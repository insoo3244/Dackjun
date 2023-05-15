#include <iostream>
#include <vector>
using namespace std;

vector<int> sort(vector<int> target) {
    int n = target.size();
    int temp;

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(target[j] > target[j + 1]){
                temp = target[j];
                target[j] = target[j + 1];
                target[j + 1] = temp;
            }
        }
    }

    return target;
}

int main(){
    int n = 8;
    int sum = 0;
    vector<int> digit(8);
    vector<int> copy(8);

    for(int i = 0; i < 8; i++){
        cin >> digit[i];
        copy[i] = digit[i];
    }

    auto score = sort(digit);

    for(int i = 0; i < 5; i++){
        cout << score[7 - i] << endl;
        sum += score[7 - i];
    }
    
    cout << sum << endl;

    for(int i = 0 ; i < 8; i++){
        if(copy[i] >= score[3]){
            cout << i + 1 << " ";
        }
    }
}
