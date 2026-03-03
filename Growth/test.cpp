#include <iostream>
#include <vector>
#include <array>

using namespace std;

class Array{
public:
    explicit Array(int n); // 크기가 N인 배열 생성
    ~Array(); // 소멸자

    void putIn(){
        for(int i = 0; i < N; i++){
            int temp = 0;
            cin >> temp;

            *(elements + i) = temp;
        }
    }

    int size(); // 크기 반환 함수
    int at(int idx); // idx 번째 원소 반환
    void set(int idx, int value); // idx 번째 원소를 value로 치환
    void insert(int idx, int value); // idx 번째 원소에 value 삽입 (마지막 원소를 손실시키고 자리 밀어내기)
    void erase(int idx); // idx 번째 인덱스 소멸 (idx 번째 원소를 손실시키고 자리 당겨오기)

private:
    int N;
    int* elements;
};

// 교수님의 코드 : 멤버 이니셜라이저를 통해 멤버변수 초기화 (elements는 동적할당)
Array::Array(int n) : N(N), elements(new int[N]){
    for(int i = 0; i < N; i++){
        // 포인터를 이용한 배열 초기화
        *(elements + i) = 0;
    }
}

// 내가 쓴 코드
// Array::Array(int n){
//     N = n;
    
//     for(int i = 0; i < N; i++){
//         // 포인터를 이용한 배열 생성
//         *(elements + i) = 0;
//     }
// }

Array::~Array(){ }

int Array::size(){
    return N;
}

int Array::at(int idx){
    // 예외 처리(Out of Bounds)
    if(idx < 0 || idx >= N){
        return -1;
    }

    return *(elements + idx);
}

void Array::set(int idx, int value){
    // 예외 처리(Out of Bounds)
    if(idx < 0 || idx >= N){
        cout << "Out of Bounds" << '\n';
        return;
    }

    *(elements + idx) = value;
}

void Array::insert(int idx, int value){
    // 예외 처리(Out of Bounds)
    if(idx < 0 || idx >= N){
        cout << "Out of Bounds" << '\n';
        return;
    }

    for(int i = N - 1; i > idx; i--){
        *(elements + i) = *(elements + i - 1);
    }

    *(elements + idx) = value;
}

void Array::erase(int idx){
    // 예외 처리(Out of Bounds)
    if(idx < 0 || idx >= N){
        cout << "Out of Bounds" << '\n';
        return;
    }

    for(int i = idx; i < N - 1; i++){
        *(elements + i) = *(elements + i + 1);
    }

    *(elements + N - 1) = 0;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    int N, Q;
    cin >> N >> Q;

    Array array(N);

    array.putIn();

    while(Q--){
        string cmd;
        cin >> cmd;

        if(cmd == "size"){
            cout << array.size() << '\n';
        }
        else if(cmd == "at"){
            int idx;
            cin >> idx;
            cout << array.at(idx) << '\n';
        }
        else if(cmd == "set"){
            int idx, value;
            cin >> idx >> value;

            array.set(idx, value);
        }
        else if(cmd == "insert"){
            int idx, value;
            cin >> idx >> value;

            array.insert(idx, value);
        }
        else if(cmd == "erase"){
            int idx;
            cin >> idx;

            array.erase(idx);
        }
    }
}