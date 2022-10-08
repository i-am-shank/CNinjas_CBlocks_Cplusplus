#include <bits/stdc++.h>
using namespace std;

vector<int> buildZ(string str) {
	int n = str.size();
	vector<int> z(n, 0);
	// z[i] -> stores max-length of prefix, starting from index i.
	int l=0, r=0; // Between which indices, pattern seen
	for(int i=1; i<n; i++) {
		if(i > r) { // Answer doesn't pre-exists
			l=i, r=i;
			while(r<n && str[r-l]==str[r]) {
				r++;
			}
			z[i] = (r-l);
			r--; // r-index should have not been matched
		}
		else { // Answer may be pre-calculated
			int k = (i-l);
			if(z[k] <= (r-i)) { // withing range
				z[i] = z[k];
			}
			else { // out of range
				// Some part of z is already included
				// You have to start matching further
				l = i; // starting point of prefix
				while(r<n && str[r-l]==str[r]) {
					r++; // Calculating count beyond old - r
				}
				z[i] = (r-l);
				r--;
			}
		}
	}
	return z;
}

void searchPattern(string str, string pattern) {
	string str2 = pattern + "$" + str;
	vector<int> z = buildZ(str2);
	int n = str2.size(), ns = str.size(), np = pattern.size();
	vector<int> found;
	for(int i=0; i<n; i++) {
		if(z[i] == np) {
			int idx = (i - (np + 1));
			// Index in actual string, str
			found.push_back(idx);
		}
	}
	return found;
}

int main() {
	string str, pattern;
	cin >> str >> pattern;
	vector<int> found = searchPattern(str, pattern);
	for(int i=0; i<found.size(); i++) {
		cout << found[i] << " ";
	}
	cout << "\n";
	return 0;
}