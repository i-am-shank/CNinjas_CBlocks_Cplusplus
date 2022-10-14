#include <bits/stdc++.h>
using namespace std;

void printName(string s, int n) {
	if(n == 0) {
		return; // Printed N times
	}
	cout << s << "\n";
	printName(s, n-1);
	return;
}

int main() {
	int n;
	cin >> n;
	printName("Shashank", n);
	return 0;
}