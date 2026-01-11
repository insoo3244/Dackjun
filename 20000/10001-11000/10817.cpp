#include <iostream>
using namespace std;

int main() {
	int a[3];

	for (int i = 0; i < 3; i++) {
		cin >> a[i];
	}

	if (a[0] >= a[1]) {
		if (a[1] >= a[2]) {
			cout << a[1];
		}
		else {
			cout << min(a[0], a[2]);
		}
	}
	else {
		if (a[1] <= a[2]) {
			cout << a[1];
		}
		else {
			cout << max(a[0], a[2]);
		}
	}
}