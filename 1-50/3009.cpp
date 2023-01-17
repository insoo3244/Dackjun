#include <iostream>
using namespace std;
int main(){
    int a[3];
    int b[3];
    int ac, bc;

    for(int i = 0; i < 3; i++){
        cin >> a[i] >> b[i];
    }

    if(a[0] == a[1]){
        ac = a[2];
    }
    else if(a[0] == a[2]){
        ac = a[1];
    }
    else if(a[1] == a[2]){
        ac = a[0];
    }

    if(b[0] == b[1]){
        bc = b[2];
    }
    else if(b[0] == b[2]){
        bc = b[1];
    }
    else if(b[1] == b[2]){
        bc = b[0];
    }

    cout << ac << " " << bc;
    return 0;
}