#include <iostream>

using namespace std;

int main(){
    int k;
    int n;
    int m;

    cin >> k >> n >> m;

    int money{k * n - m > 0 ? k * n - m : 0};
    cout << money;
}
