// Codeforces  -->  C. Equalize
// Link  :  https://codeforces.com/problemset/problem/1037/C?locale=en

#include <bits/stdc++.h>
#include <string>
using namespace std;

int findCost(int n, string a, string b) {
	if(n == 0) {
		return 0;
	}
	if(n == 1) {
		if(a[0] == b[0]) {
			return 0;
		}
		return 1;
	}
	if(a[0] == b[0]) {
		return findCost(n-1, a.substr(1), b.substr(1));
	}
	else {
		if(a[1] != b[1]) {  // Adjacent chars unequal.. both swap & flips possible to minimise..
			int smallCost = findCost(n-2, a.substr(2), b.substr(2));
			if(a[0] == a[1]) {  // Swap not possible, 2 flips are needed
				return (smallCost + 2);
			}
			return (smallCost + 1);  // Else swap will minimise the cost ..distance 1
		}
		else {  // No option for minimum cost, except flips
			int smallCost = findCost(n-2, a.substr(2), b.substr(2));
			return (smallCost + 1);
		}
	}
	
}

int main() {
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	int cost = findCost(n, a, b);
	cout << cost << endl;
	return 0;
}