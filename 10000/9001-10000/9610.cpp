#include <iostream>
using namespace std;

int main(){
    int n;
    int x, y;

    cin >> n;
    int q[6]{ 0 };

    while(n--){
        cin >> x >> y;

        if(x == 0 || y == 0){
            q[5]++;
            
        }   
        else if(x > 0){
            if(y > 0){
                q[1]++;
            }
            else{
                q[4]++;
                
            }
        }
        else if(x < 0){
            if(y > 0){
                q[2]++;
                
            }
            else{
                q[3]++;
                
            }
        }
    }

    for(int i = 1; i < 6; i++){
        if(i < 5){
            cout << "Q" << i << ": " << q[i] << endl;
        }
        else{
            cout << "AXIS: " << q[i] << endl;
        }
    }
}