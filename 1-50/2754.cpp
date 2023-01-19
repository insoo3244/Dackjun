#include <iostream>
#include <string>
using namespace std;

int main(){
    string a;
    
    cin >> a;
    
    if(a[0] == 'A'){
        switch(a[1]){
            case '+':
                cout << "4.3";
                break;
            case '0':
                cout << "4.0";
                break;
            case '-':
                cout << "3.7";
                break;
        }
    }
    else if(a[0] == 'B'){
        switch(a[1]){
            case '+':
                cout << "3.3";
                break;
            case '0':
                cout << "3.0";
                break;
            case '-':
                cout << "2.7";
                break;
        }

    }
    else if(a[0] == 'C'){
        switch(a[1]){
            case '+':
                cout << "2.3";
                break;
            case '0':
                cout << "2.0";
                break;
            case '-':
                cout << "1.7";
                break;
        }

    }
    else if(a[0] == 'D'){
        switch(a[1]){
            case '+':
                cout << "1.3";
                break;
            case '0':
                cout << "1.0";
                break;
            case '-':
                cout << "0.7";
                break;
        }
    }
    else{
        cout << "0.0";
    }
}