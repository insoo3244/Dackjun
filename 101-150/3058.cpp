#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    int t;
    vector<int> d;
    int sum = 0;
    int min = 100;

    cin >> t;
    while(t--){
        for(int i = 0; i < 7 ; i++){
            cin >> n;
            
            if(n % 2 == 0){
                d.push_back(n);
                sum += n;

                if(n < min){
                    min = n;
                }
            }
        }

        cout << sum << " " << min << endl;
        min = 100;
        sum = 0;
    }
}