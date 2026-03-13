#include <iostream>
#include <string>

using namespace std;

class StringNode{
public:
    StringNode(int value){
        elem = value;
        next = nullptr;
    }
private:
    int elem;
    StringNode* next;

    friend class LinkedList;
};

class LinkedList{
public:
    LinkedList();
    ~LinkedList();

    void print();
    void AddFront(const int& value);
    void RemoveFront();
    void Update(int idx, const int& value);
    void Min();

    bool empty() const{
        if(!head) { return true; }
        else { return false; }
    }

private:
    int N;
    StringNode* head;
    StringNode* tail;
};

LinkedList::LinkedList() : N(0), head(nullptr), tail(nullptr){ }

LinkedList::~LinkedList() {
    while(empty()) { RemoveFront(); }
}

void LinkedList::print(){
    if(empty()){
        cout << "empty" << '\n';
        return;
    }

    StringNode* v = head;
    while(v != tail->next){
        cout << v->elem << " ";
        v = v->next;
    }

    cout << '\n';
}

void LinkedList::AddFront(const int& value){
    StringNode* v = new StringNode(value);
    
    if(empty()){
        head = tail = v;
    }
    else{
        v->next = head;
        head = v;
    }

    ++N;
}

void LinkedList::RemoveFront(){
    if(empty()){
        cout << "empty" << '\n';
        return;
    }

    StringNode* v = head;
    cout << v->elem << '\n';
    if(N == 1){
        head = tail = nullptr;
    }
    else{
        head = head->next;
    }

    delete v;
    N--;
}

void LinkedList::Update(int idx, const int& value){
    if(idx < 0 || idx >= N){
        cout << "error" << '\n';
        return;
    }

    StringNode* v = head;
    int count = 0;

    while(count++ < idx){
        v = v->next;
    }
    
    v->elem = value;
}

void LinkedList::Min(){
    int min = 1001;
    int minIdx = 0;
    int count = 0;

    StringNode* v = head;
    while(v != tail->next){
        if(v->elem < min){
            min = v->elem;
            minIdx = count;
        }

        count++;
        v = v->next;
    }
    
    cout << minIdx << " " << min << '\n';
}

int main(){
    int m;
    cin >> m;

    LinkedList list;
    while(m--){
        string cmd;
        cin >> cmd;

        if(cmd == "Print"){
            list.print();
        }
        else if(cmd == "AddFront"){
            int temp;
            cin >> temp;

            list.AddFront(temp);
        }
        else if(cmd == "RemoveFront"){
            list.RemoveFront();
        }
        else if(cmd == "Update"){
            int temp1, temp2;
            cin >> temp1 >> temp2;
            
            list.Update(temp1, temp2);
        }
        else if(cmd == "Min"){
            list.Min();
        }
    }
}