#include <iostream>
using namespace std;

int main() {
	int A{ 0 }, B{ 0 }, C{ 0 };
	int D{ 0 };

	cin >> A >> B >> C;
	cin >> D;

	int aC{ D % 60 };
	int aB{ 0 };
	int aA{ 0 };
	
	if (D / 60 >= 60) {
		aB = (D / 60) % 60;
		aA = (D / 60) / 60;
	}
	else {
		aB = D / 60;
	}
	
	int nC{ 0 };
	int nB{ 0 };
	int nA{ 0 };

	if (C + aC >= 60) {
		nC = (C + aC) % 60;
		nB = (C + aC) / 60;
	}
	else {
		nC = C + aC;
	}

	if (B + aB + nB >= 60) {
		nA = (B + aB + nB) / 60;
		nB = (B + aB + nB) % 60;
	}
	else {
		nB = B + aB + nB;
	}

	if (A + aA + nA > 23) {
		nA = (A + aA + nA) % 24;
	}
	else {
		nA = A + aA + nA;
	}

	cout << nA << " " << nB << " " << nC;
}