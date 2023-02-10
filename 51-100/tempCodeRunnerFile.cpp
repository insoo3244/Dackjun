#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int t;
    int n;
    int c;
    float g;

    int s = 0;
    float h = 0;
    cin >> t;
    while(t--){
        cin >> n;
        int check = n;
        while(n--){
            cin >> c;
            cin >> g;
            s += c;
            h += g;
        }

        cout << s << " " << fixed << setprecision(1) << h / check << endl;
        s = 0;
        h = 0;
    }
}