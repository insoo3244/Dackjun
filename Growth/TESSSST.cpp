#include <iostream>
#include <string>

using namespace std;

class Array {
public:
	Array(int n);
	~Array();

	void shuffle(int idx, int value);
	void reverse(int idx, int value);
	void print();
	void count_odd();

private:
	int N;
    int* elements;
};

Array::Array(int n) : N(n), elements(new int[N]){
    if (n <= 0) {
        cout << "!!! Error: n is " << n << " !!!" << endl;
        elements = nullptr; 
        return;
    }

	for (int i = 0; i < N; i++) {
		*(elements + i) = i;
	}
}

Array::~Array() {
	delete[] elements;
}

void Array::shuffle(int idx, int value){
    if(idx < 0 || idx >= N){
        cout << "Out of Bounds" << '\n';
        return;
    }

    elements[idx]++;
    elements[value]++;

    int temp = elements[idx];
    elements[idx] = elements[value];
    elements[value] = temp;
}

void Array::reverse(int idx, int value){
    if(idx < 0 || idx >= N){
        cout << "Out of Bounds" << '\n';
        return;
    }

    int* temp = new int[value - idx + 1];
    int a = 0;
    for(int i = value; i >= idx; i--){
        temp[a] = elements[i];
        a++;
    }

    a = 0;
    for(int i = idx; i <= value; i++){
        elements[i] = temp[a];
        a++;
    }

    delete[] temp;
}

void Array::print(){
    for(int i = 0; i < N; i++){
        cout << elements[i] << " ";
    }

    cout << '\n';
}

void Array::count_odd(){
    int count = 0;

    for(int i = 0; i < N; i++){
        if(elements[i] % 2 != 0){
            count++;
        }
    }

    cout << count << '\n';
}

int main() {
	int t;
    cin >> t;

    while(t--){
        int n, q;
        cin >> n >> q;

        Array array(n);
        
        int temp1, temp2;

        while(q--){    
            string cmd;
            cin >> cmd;

            if(cmd == "reverse"){
                cin >> temp1 >> temp2;
                array.reverse(temp1, temp2);
            }
            else if(cmd == "shuffle"){
                cin >> temp1 >> temp2;

                array.shuffle(temp1, temp2);
            }
            else if(cmd == "count_odd"){
                array.count_odd();
            }
            else if(cmd == "print"){
                array.print();
            }
        }
    }
}