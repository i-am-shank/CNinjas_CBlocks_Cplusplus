// Time Complexity = O(logN)  ..  here N = max(a, b)
// Space Complexity = O(1)

// Diophantine Equation  -->  Polynomial equations having integral solutions.
// Linear Diophantine Equation :
//    ax + by = c      -->     Integral solutions exists when  ... gcd(a,b) divides c.


#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {  // a > b
	if(b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int main() {
	int x, y;
	cin >> x >> y;
	int a = max(x, y);
	int b = min(x, y);
	int ans = gcd(a, b);
	cout << ans << endl;
	return 0;
}