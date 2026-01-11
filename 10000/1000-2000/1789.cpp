#include <iostream>
using namespace std;

int main() {
	long long s;
	int n{ 1 };
	long long m{ 0 };
	int count{ 0 };

	cin >> s;

	while (1) {
		m = m + n;
		n++;
		count++;
		if(m > s){
			count--;
			break;
		}
	}

	cout << count;
	return 0;
}	