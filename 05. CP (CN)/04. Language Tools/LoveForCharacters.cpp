#include <bits/stdc++.h>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int counta=0, counts=0, countp=0;
	for(int i=0; i<n; i++) {
		if(s[i] == 'a') {
			counta ++;
		}
		else if(s[i] == 's') {
			counts ++;
		}
		else if(s[i] == 'p') {
			countp ++;
		}
		else {
			continue;
		}
	}
	cout << counta << " " << counts << " " << countp << endl;
	return 0;
}