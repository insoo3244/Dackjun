// https://www.acmicpc.net/problem/1966
// 2026-03-26
#include <iostream>

using namespace std;

class Node{
public:
    Node(int v, int p) : elem(v), imp(p), next(nullptr) {}
private:
    int elem;
    int imp;
    Node* next;

    friend class ListQueue;
};

class ListQueue{
public:
    ListQueue() : n(0), f(nullptr), r(nullptr), cnt(0) {}
    ~ListQueue() {}

    int size() { return n; }
    bool empty() { return f == nullptr; }

    int frontE() {
        return f->elem;
    }

    int frontI() {
        return f->imp;
    }

    void goRear(){
        Node* v = f;
        
        f = f->next;
        r->next = v;
        r = v;
        v->next = nullptr;
    }
    
    /*  find()가 할 일
        1. 가장 맨 앞 원소의 중요도 체크
            -> 해당 원소의 중요도 보다 더 높은 중요도의 원소가 있다면,
            -> 해당 원소는 goRear();
        2. 가장 맨 앞 원소가 가장 중요도가 높다면, 해당 원소는 dequeue()
            -> 만약 해당 원소의 번호가 target(= m)과 같다면, 
                해당 원소가 출력된 차례를 출력함
        3. 테스트 케이스 종료
    */

    void find(int target){
        Node* v = f;
        bool isGo = false; // goRear를 실행했나?
        

        while(!isGo){           
            // 일단 imp 가져와 
            int fImp = frontI();

            // 노드 전체 순회하면서 
            // fImp보다 큰 노드를 발견하면, goRear().
            // v가 null에 도달할 때까지 반복
            while(v != nullptr){
                if(v->imp > fImp){
                    goRear();
                    isGo = true;
                    break;
                }

                v = v->next;
            }

            // 만약 goRear을 실행했다?
            if(isGo){ 
                // isGo를 초기화하고, 다시 처음부터 탐색
                isGo = false;
                v = f;
            }
            // 실행하지 않았다?
            else {
                // dequeue를 실행하기 전 마지막 검사
                // 해당 노드넘버가 target과 일치한다면,
                if(frontE() == target){
                    // 해당 노드넘버의 차례순서를 출력 후, 함수 종료
                    cout << ++cnt << '\n';
                    return;
                }   
                // 일치하지 않는다면,
                else{
                    // 해당 노드 삭제 후, 처음부터 다시
                    isGo = false;
                    dequeue();
                    v = f;
                }
            }
        }
    }

    void enqueue(int value, int p) {
        Node* v = new Node(value, p);

        if(n == 0){
            f = r = v;
        }
        else{
            r->next = v;
            r = v;
            r->next = nullptr;
        }

        n++;
    }

    void dequeue() {
        Node* v = f;

        if(n == 1){
            f = r = nullptr;
        }
        else{
            f = f->next;
        }

        delete v;
        n--;
        cnt++;
    }

private:
    int n;
    Node* f;
    Node* r;
    int cnt;
};

int main() {
    int t; // 테스트 케이스
    cin >> t;

    while(t--){
        // 문서 개수 n
        // 몇 번째로 인쇄되었는지 궁금한 문서가 현재 queue 에서
        // 몇 번째에 놓여있는지를 나타내는 정수 m
        int n, m;
        cin >> n >> m;

        ListQueue que;
        int imp = 0;
        for(int i = 0; i < n; i++){
            cin >> imp;
            
            que.enqueue(i, imp);
        }
    
        que.find(m);
    }

}   