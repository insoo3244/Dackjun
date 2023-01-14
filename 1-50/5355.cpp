#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
	int T{ 0 };
	double num{ 0 };

	cin >> T;
	double* list = new double[T];
	string s;

	for (int i = 0; i < T; i++) {
		cin >> num;
		
		getline(cin, s);
		for (int i = 0; i < s.size(); i++) {
			switch (s[i]) {
			case '@':
				num = num * 3.00;
				break;
			case'%':
				num = num + 5.00;
				break;
			case'#':
				num = num - 7.00;
				break;
			}
		}

		list[i] = num;
	}

	for (int i = 0; i < T; i++) {
		cout << fixed << setprecision(2) << list[i] << endl;
	}

	delete[] list;
}

/*
#include <iostream>
#include <string>
using namespace std;
int main() {
	double n, t;
	string x;
	cin >> t;
	while (t--)
	{
		cin >> n;
		getline(cin, x);
		for (int i = 0; i < x.size(); i++)
			switch (x[i])
			{
			case '@':
				n *= 3;
				break;
			case '#':
				n -= 7;
				break;
			case '%':
				n += 5;
				break;
			}
		printf("%.2f\n", n);
	}
}
*/