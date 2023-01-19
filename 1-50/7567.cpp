#include <iostream>
#include <string>
using namespace std;

int main(){
    string a;
    int len{ 0 };
    int s{ 0 };

    cin >> a;
    unsigned int size{ a.size() };

    while(size > 0){
        if(size == a.size()){
            len = len + 10;        
        }
        else{
            if(a[s] == a[s - 1]){
                len = len + 5;
            }
            else{
                len = len + 10;
            }
        }

        size--;
        s++;
    }
    cout << len;
}