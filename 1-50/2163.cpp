#include <iostream>
using namespace std;

int main(){
	int N{ 0 }, M{ 0 };
	int num{ 0 };

	cin >> N >> M;

	if (N == 1 && M == 1) {
		cout << "0";
	}
	else if (N == 1) {
		cout << M - 1;
	}
	else if (M == 1) {
		cout << N - 1;
	}
	else {
		while (N != 1) {
			N--;
			num++;
			for (int i = 0; i < M - 1; i++) {
				num++;
			}
		}

		cout << num + M - 1;
	}
}