#include <iostream>
#include <ctime>
using namespace std;

int main() {
	time_t timer;
	struct tm t;

	timer = time(NULL);
	localtime_s(&t, &timer);

	cout << t.tm_year + 1900 << "-";
	if (t.tm_mon < 10) {
		cout << "0" << t.tm_mon + 1 << "-";
	}
	else {
		cout << t.tm_mon + 1 << "-";
	}
	if (t.tm_mday < 10) {
		cout << "0" << t.tm_mday;
	}
	else {
		cout << t.tm_mday;
	}
}

