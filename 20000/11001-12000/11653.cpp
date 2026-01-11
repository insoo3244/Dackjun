#include <iostream>

using namespace std;

int main() {
	int a;

	cin >> a;

	if (a <= 1) return 0;

	bool* PrimeArray = new bool[a + 1];

	for (int i = 2; i <= a; i++)
		PrimeArray[i] = true;

	for (int i = 2; i * i <= a; i++)
	{
		if (PrimeArray[i])
			for (int j = i * i; j <= a; j += i)
				PrimeArray[j] = false;
	}

	int i = 2;
	while (a != 1) {
		if (PrimeArray[i]) {
			if (a % i == 0) {
				while (a % i == 0) {
					cout << i << endl;
					a = a / i;
				}
			}
		}
		i++;
	}

	return 0;
}