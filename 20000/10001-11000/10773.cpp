#include <iostream>
#include <vector>
using namespace std;

int main(){
    int k;
    int sum = 0;
    int temp;

    cin >> k;
    vector <int> number;
    
    for(int i = 0; i < k; i++){
        cin >> temp;

        if(temp == 0){
            number.pop_back();
        }
        else{
            number.push_back(temp);
        }
    }

    for(int i = 0; i < number.size(); i++){
        sum += number[i];
    }

    cout << sum;

    // int* n = new int[k];

    // for(int i = 0; i < k; i++){
    //     cin >> n[i];

    //     if(n[i] == 0){
    //         for(int j = i; j >= 0; j--){
    //             if(n[j] != 0){
    //                 n[j] = 0;
    //                 break;
    //             }
    //             else{
    //                 continue;
    //             }
    //         }
    //     }
    // }

    // for(int i = 0; i < k; i++){
    //     sum += n[i];
    // }

    // cout << sum;
    // delete[] n;
}