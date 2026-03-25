// https://www.acmicpc.net/problem/2164
// 2026-03-25
#include <iostream>

using namespace std;

class ArrayQueue{
public:
    ArrayQueue(int value) : N(value), n(0), elems(new int[N]), f(0), r(0) {}
    ~ArrayQueue() { delete[] elems; }

    int size() { return n; }
    bool empty() { return n == 0; }

    int front(){
        return elems[f];
    }
    int rear(){
        if(r == 0) { return elems[N - 1]; }
        else { return elems[r - 1]; }
    }

    void enqueue(int value){
        elems[r] = value;
        r = (r + 1) % N;
        n++;
    }

    void dequeue(){
        f = (f + 1) % N;
        n--;
    }

private:
    int N;
    int n;
    int* elems;
    int f, r;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    if(n == 1) { cout << "1"; return 0; }

    ArrayQueue arr(n);
    for(int i = 1; i < n + 1; i++){
        arr.enqueue(i);
    }
    
    while(arr.size() > 1){
        arr.dequeue();
        int temp = arr.front();
        arr.enqueue(temp);
        arr.dequeue();
    }

    cout << arr.front();
}