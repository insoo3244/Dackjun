#include <iostream>
#include <string>

using namespace std;

// 원소 자료형 선언
typedef string Elem;

// 노드 클래스
class StringNode{
public:
    // 생성자
    StringNode(Elem elem){
        this->elem = elem;
        next = nullptr;
    }

private:
    Elem elem; // 원소
    StringNode* next; // 다음 리스트의 주소
    
    friend class LinkedList; // 멤버 공유
};

class LinkedList{
public:
    LinkedList();
    ~LinkedList();

    int size();
    bool empty() const;
    Elem front() const;
    Elem back() const;
    void push_front(const Elem &elem);
    void push_back(const Elem &elem);
    void pop_front();
    void pop_back();
    void print(){ // 출력
        if(empty()){
            cout << "Empty List" << '\n';
            return;
        }

        StringNode* v = head; // 선두노드 시작
        
        if(size() == 1){ // 원소가 1개 일 때
            cout << v->elem;
        }
        else{ // 여러개 일 때
            while(v != tail->next){
                cout << v->elem << " ";
                v = v->next;
            }
        }

        cout << '\n';
    }

private:
    StringNode* head; // 선두노드
    StringNode* tail; // 꼬리노드
    int N; // 리스트에 있는 노드 개수
};

LinkedList::LinkedList(){ // 생성자 : 멤버변수 초기화
    N = 0;
    head = nullptr;
    tail = nullptr;
}

LinkedList::~LinkedList(){ // 소멸자 : 리스트 전부 제거
    while(!empty()) { pop_front(); }
}

int LinkedList::size(){ // 사이즈 반환
    return N;
}

bool LinkedList::empty() const{ // 리스트가 비어있는가 여부 반환
    if(head == nullptr) { return true; }
    else { return false; }
}

Elem LinkedList::front() const{ // 맨 앞 원소 반환 (선두노드)
    if (empty()){ 
        cout << "Empty List" << '\n';
        Elem exit = "Function Failed";
        return exit;
    }

    return head->elem;
}

Elem LinkedList::back() const{ // 맨 뒤 원소 반환 (후미노드)
    if(empty()){ 
        cout << "Empty List" << '\n';
        Elem exit = "Function Failed";
        return exit;
    }

    return tail->elem;
}

void LinkedList::push_front(const Elem &elem){ // 맨 앞 자리에 원소 추가
    StringNode *v = new StringNode(elem);

    if(empty()){ // 리스트가 비어있다면
        head = v;
        tail = v;
        v->next = nullptr;
        // 선두, 후미 둘 다 v, 그 다음 리스트는 NULL
    }
    else{ // 비어있지 않다면,
        v->next = head;
        head = v;
        // v의 다음 노드는 (전)선두노드, v가 선두노드로 갱신됨
    }

    ++N; // 개수 늘리기
}

void LinkedList::push_back(const Elem &elem){
    StringNode *v = new StringNode(elem);

    if(empty()){ // 리스트가 비어있다면
        head = v;
        tail = v;
        v->next = nullptr;
        // 선두, 후미 둘 다 v, 그 다음 리스트는 NULL
    }
    else{ // 비어있지 않다면,
        tail->next = v;
        tail = v;
        tail->next = nullptr;
        // (전)후미노드는 v를 가리킴, v가 후미노드로 갱신되고, v의 다음 리스트는 NULL
    }

    ++N; // 개수 늘리기
}

void LinkedList::pop_front(){
    if(empty()){ // 리스트가 비어있다면
        cout << "Empty List" << '\n';
        return;
    }

    StringNode* temp = head;
    // 노드를 지우면 리스트의 원소가 전부 사라질 때
    if(size() == 1){
        head = tail = nullptr;
        // 선두, 후미노드 둘 다 NULL
    }
    // 리스트에 원소가 충분히 존재할 때
    else{
        head = head->next;
        // 선두노드는 다음 리스트로 갱신됨
    }
    
    delete temp; // 선두노드 메모리 삭제
    --N; // 개수 줄이기
}

void LinkedList::pop_back(){
    if(empty()){ // 리스트가 비어있다면
        cout << "Empty List" << '\n';
        return;
    }

    // 머리부터 꼬리까지 탐색 시작. temp : 현재 노드
    StringNode* temp = head;

    if(temp == tail){ // 현재 노드가 꼬리면,
        head = tail = nullptr;
        delete temp;
    }
    else{ // 꼬리가 아니라면,
        // 다음 노드가 꼬리가 될 때 까지 탐색
        while(temp->next != tail){
            temp = temp->next;
        }

        // temp가 저장한 것 = 후미노드 직전의 노드
        tail = temp;
        delete tail->next;
        tail->next = nullptr;
        // 후미노드는 temp가 됨, temp의 다음 메모리를 삭제 후, NULL로 갱신
    }

    
    delete temp;
    --N; // 개수 줄이기
}

int main() {
    // 명령할 횟수 n
    int n;
    cin >> n;
    
    LinkedList link;

    while(n--){
        cout << "Please Enter the command." << '\n';

        string cmd;
        cin >> cmd;

        if(cmd == "size"){
            cout << link.size() << '\n';
        }
        else if(cmd == "empty"){
            if(link.empty()) { cout << "Empty List" << '\n'; }
            else { cout << "Exist Element(s)" << '\n'; }
        }
        else if(cmd == "front"){
            cout << link.front() << '\n';
        }
        else if(cmd == "back"){
            cout << link.back() << '\n';
        }
        else if(cmd == "push_front"){
            cout << "Please Enter the elements(string) : ";
            
            Elem elem;
            cin >> elem;
            StringNode node(elem);

            link.push_front(elem);
        }
        else if(cmd == "push_back"){
            cout << "Please Enter the elements(string) : ";
            
            Elem elem;
            cin >> elem;
            StringNode node(elem);

            link.push_back(elem);
        }
        else if(cmd == "pop_front"){
            link.pop_front();
        }
        else if(cmd == "pop_back"){
            link.pop_back();
        }
        else if(cmd == "print"){
            link.print();
        }
    }
}