// https://www.acmicpc.net/problem/11866
// 2026-03-25
#include <iostream>

using namespace std;

class Node{
public:
    Node(int value) : elems(value), next(nullptr) { }
private:
    int elems;
    Node* next;

    friend class LinkedQueue;
};

class LinkedQueue{
public:
    LinkedQueue() : n(0), f(nullptr), r(nullptr) { }
    ~LinkedQueue() { while(!empty()) { dequeue(); }}

    int size() { return n; }
    bool empty() { return f == nullptr; }

    int front(){
        return f->elems;
    }
    int rear(){
        return r->elems;
    }

    void enqueue(int value){
        Node* v = new Node(value);

        if(n == 0){
            f = r = v;
        }
        else{
            r->next = v;
            r = v;
        }

        n++;
    }

    void dequeue(){
        Node* v = f;

        if(n == 1){
            f = r = nullptr;
        }
        else{
            f = f->next;
        }

        delete v;
        n--;
    }

    void goRear(){
        Node* v = f;

        f = f->next;
        r->next = v;
        r = v;
        v->next = nullptr;
    }

private:
    int n;
    Node* f;
    Node* r;
};

int main() {
    int n, k;
    cin >> n >> k;

    LinkedQueue q1;
    for(int i = 0; i < n; i++){
        q1.enqueue(i + 1);
    }

    int itv = 0;
    cout << "<";
    while(q1.size() != 1){
        // 제미나이 버전
        for(int i = 0; i < k - 1; i++){
            q1.goRear();
        }

        cout << q1.front() << ", ";
        q1.dequeue();
        
        // 내가 쓴 버전
        // itv++;
        // if((itv % k == 0) && (itv != 0)){
        //     cout << q1.front() << ", ";
        //     q1.dequeue();
        // }
        // else{
        //     q1.goRear();
        // }
    }

    cout << q1.front() << ">";
}