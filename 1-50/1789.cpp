#include <iostream>
using namespace std;

int main() {
	int s;
	int n{ 1 };
	int m{ 0 };

	cin >> s;

	while (m <= s) {
		m = m + n;
		n++;
	}

	cout << n;
}