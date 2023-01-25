#include <iostream>
using namespace std;
//17분이었음
int main() {
    string a, b;
    
    cin >> a >> b;
    int asize{ a.size() };
    int bsize{ b.size() };
    int check{ 0 };
    char* result = new char[asize > bsize ? asize + 1 : bsize + 1];

    if(asize > bsize){
        for(int i = asize - 1; i > 0; i--){
            if(a[i] + b[bsize] > 10){
                
            }
            else{
                result[bsize] = a[i] + b[bsize];
            }
        }
    }
    else if(asize == bsize){

    }
    else{

    }

    delete[] result;
}