#include <iostream>
using namespace std;
int main(){
    int t;
    cin >> t;

    int y;
    int k;
    int test{ 9 };

    int sumy{ 0 };
    int sumk{ 0 };
    while(t--){
        while(test--){
            cin >> y >> k;
            sumy += y;
            sumk += k;
        }

        if(sumy > sumk){
            cout << "Yonsei" << endl;
        }
        else if(sumy == sumk){
            cout << "Draw" << endl;
        }
        else{
            cout << "Korea" << endl;
        }

        sumy = 0;
        sumk = 0;
        test = 9;
    }
}