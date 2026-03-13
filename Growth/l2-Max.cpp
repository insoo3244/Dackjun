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
    void AddBack(const int& value);
    void RemoveBack();
    void Update(int idx, const int& value);
    void Max();

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
    while(empty()) { RemoveBack(); }
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

void LinkedList::AddBack(const int& value){
    StringNode* v = new StringNode(value);
    
    if(empty()){
        head = tail = v;
		tail->next = nullptr;
    }
    else{
        tail->next = v;
		tail = v;
        tail->next = nullptr;
    }

    ++N;
}

void LinkedList::RemoveBack(){ // 자꾸 헷갈림
    if(empty()){
        cout << "empty" << '\n';
        return;
    }

    StringNode* v = head;
    if(N == 1){
		cout << v->elem << '\n';
        head = tail = nullptr;
		delete v;
    }
    else{
        while(v->next != tail){
			v = v->next;
		}

		tail = v;
		cout << tail->next->elem << '\n';
		delete tail->next;
		tail->next = nullptr;
    }

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

void LinkedList::Max(){
    int max = 0;
    int maxIdx = 0;
    int count = 0;

    StringNode* v = head;
    while(v != tail->next){
        if(v->elem > max){
            max = v->elem;
            maxIdx = count;
        }

        count++;
        v = v->next;
    }
    
    cout << maxIdx << " " << max << '\n';
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
        else if(cmd == "AddBack"){
            int temp;
            cin >> temp;

            list.AddBack(temp);
        }
        else if(cmd == "RemoveBack"){
            list.RemoveBack();
        }
        else if(cmd == "Update"){
            int temp1, temp2;
            cin >> temp1 >> temp2;
            
            list.Update(temp1, temp2);
        }
        else if(cmd == "Max"){
            list.Max();
        }
    }
}