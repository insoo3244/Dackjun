#include <iostream>
#include <string>

using namespace std;

class StringNode{
public:
    StringNode(int elem){
        this->elem = elem;
        next = nullptr;
    }

private:
    int elem;
    StringNode *next;

    friend class LinkedList;
};

class LinkedList{
public:
    LinkedList();
    ~LinkedList();

    int size() { return N; }

    void print();
    void AddFront(const int &elem);
    void RemoveFront();
    void Update(int idx, const int &elem);
    void Min();

    bool empty() const;
private:
    int N;
    StringNode* head;
    StringNode* tail;
};

LinkedList::LinkedList(){
    N = 0;
    head = tail = nullptr;
}

LinkedList::~LinkedList(){
    while(!empty()) { RemoveFront(); }
}

void LinkedList::print(){
    if(empty()){
        cout << "empty" << '\n';
        return;
    }

    StringNode *cur = head;
    while(cur != tail -> next){
        cout << cur->elem << " ";
        cur = cur->next;
    }

    cout << '\n';
}

void LinkedList::AddFront(const int &elem){
    StringNode* v = new StringNode(elem);

    if(empty()){
        head = tail = v;
        tail->next = nullptr;
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

    StringNode *v = head;
    if(N == 1){
        head = tail = nullptr;
    }
    else{
        head = head->next;
    }

    delete v;

    --N;
}

void LinkedList::Min(){
    if(empty()){
        cout << "empty" << '\n';
        return;
    }

    int min = 1001;
    int count = 0;
    int minIdx = 0;
    StringNode* cur = head;
    while(cur != tail->next){
        if(cur->elem < min){
            min = cur->elem;
            minIdx = count;
        }

        cur = cur->next;
        count++;
    }

    cout << minIdx << " " << min << '\n';
}

void LinkedList::Update(int idx, const int &elem){
    if(idx >= size()){
        cout << "error" << '\n';
        return;
    }

    int count = 0;
    StringNode *v = head;

    while(count++ < idx){
        v = v->next;
    }

    v->elem = elem;
}

bool LinkedList::empty() const{
    if(!head) { return true; }
    else { return false; }
}

int main() {
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

            StringNode node(temp);
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