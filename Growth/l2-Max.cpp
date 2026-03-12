#include <iostream>
#include <string>

using namespace std;

class StringNode {
public:
	StringNode(int value) {
		elem = value;
		next = nullptr;
	}

private:
	int elem;
	StringNode* next;

	friend class LinkedList;
};

class LinkedList {
public:
	LinkedList();
	~LinkedList();

	void print();
	void AddBack(const int& value);
	void Removeback();
	void Update(int idx, const int& value);
	void Max();

	bool empty() const {
		if (!head) { return true;  }
		else { return false; }
	}
private:
	int N;
	StringNode* head;
	StringNode* tail;
};

LinkedList::LinkedList() : N(0), head(nullptr), tail(nullptr) {}

LinkedList::~LinkedList() {
	while (empty()) { Removeback(); }
}

void LinkedList::print() {
	if (empty()) {
		cout << "empty" << '\n';
		return;
	}

	StringNode* v = head;
	while (v != tail->next) {
		cout << v->elem << ' ';
		v = v->next;
	}

	cout << '\n';
}

void LinkedList::AddBack(const int& value) {
	StringNode* v = new StringNode(value);

	if (empty()) {
		head = tail = v;
		v->next = nullptr;
	}
	else {
		tail->next = v;
		tail = v;
		tail->next = nullptr;
	}

	++N;
}

void LinkedList::Removeback() {
	if (empty()) {
		cout << "empty" << '\n';
		return;
	}

	StringNode* v = head;
	if (N == 1) {
		cout << v->elem << '\n';
		head = tail = nullptr;

	}
	else {
		while (v->next != tail) {
			v = v->next;
		}

		cout << tail->elem << '\n';
		tail = v;
		tail->next = nullptr;

		v = v->next;
	}

	delete v;
	N--;
}

void LinkedList::Update(int idx, const int& value) {
	if (idx >= N) {
		cout << "error" << '\n';
		return;
	}

	StringNode* v = head;
	int count = 0;
	while (count++ < idx) {
		v = v->next;
	}

	v->elem = value;
}

void LinkedList::Max() {
	StringNode* v = head;

	int max = 0;
	int idx = 0;
	int count = 0;

	while (v != tail->next) {
		if (v->elem > max) {
			max = v->elem;
			idx = count;
		}

		count++;
		v = v->next;
	}

	cout << idx << " " << max << '\n';
}

int main() {
	int m;
	cin >> m;

	LinkedList list;

	while (m--) {
		string cmd;
		cin >> cmd;

		if (cmd == "Print") {
			list.print();
		}
		else if (cmd == "AddBack") {
			int temp;
			cin >> temp;

			list.AddBack(temp);
		}
		else if (cmd == "RemoveBack") {
			list.Removeback();
		}
		else if (cmd == "Update") {
			int temp1, temp2;
			cin >> temp1 >> temp2;

			list.Update(temp1, temp2);
		}
		else if (cmd == "Max") {
			list.Max();
		}
	}
}