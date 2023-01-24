#include <iostream>
using namespace std;

int main(){
    int a = 1;
    int b = 1;

    while(a != 0 && b != 0){
        cin >> a >> b;

        if(a == 0 || b == 0){
            break;
        }

        if(a > b){
            if(a % b == 0){
                cout << "multiple" << endl;
            }
            else{
                cout << "neither" << endl;
            }
        }
        else{
            if(b % a == 0){
                cout << "factor" << endl;
            }
            else{
                cout << "neithor" << endl;
            }
            
            /*
            int* arr = new int[b];
            for(int i = 1; i <= sqrt(b); i++){
                if(b % i == 0){
                    arr[i] = i;
                }
            }

            int check{0};
            for(int i = 1; i < sqrt(b); i++){
                if(b % i == 0){
                    check = b / arr[i];
                    arr[check] = check;
                }
            }
            
            int check2{0};
            for(int i = 1; i < b; i ++){
                if(arr[i] == a){
                    check2++;
                    break;
                }
            }

            cout << "factor";
            delete[] arr;
            */
        
        }
    }
}