#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int z = n & 1;
	if(z == 0) {
		cout << "Even" << endl;
	}
	else {
		cout << "Odd" << endl;
	}
	return 0;
}