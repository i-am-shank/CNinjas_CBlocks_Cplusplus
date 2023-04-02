#include <bits/stdc++.h>
using namespace std;

int main() {
	bool a = false, b = false, c = true;
	if(a) {
		if(b && !c) {
			cout << "Goodbye Cruel World!";
		}
		else if(!b && !c) {
			cout << "Nothing here";
		}
	}
	else {
		if(!b) {
			if(!a && (!b && c)) {
				cout << "Hello, World!";
			}
			else {
				cout << "Goodbye World!";
			}
		}
		else {
			cout << "Not quite.";
		}
	}
	return 0;
}