#include <bits/stdc++.h>
using namespace std;

class Solution {
	// Time : O(logn)
	// Space : O(logn)
	double myPow_rec(double x, int n) {
		if(n == 1) {
			return x;
		}
		if(n == 0) {
			return 1.0;
		}
		if(n % 2 == 0) {
    		double smallAns = myPow_rec(x, n/2);
    		return (smallAns * smallAns);
    	}
    	else {
    		double smallAns = myPow_rec(x, n/2);
    		if(n > 0) {
    			return (smallAns * smallAns * x);
    		}
    		return ((smallAns * smallAns) / x);
    	}
	}

	// Time : O(n)
	// Space : O(1)
    double myPow_bf(double x, int n) {
        double ans = 1.0;
        if(n < 0) {
        	for(int i=n; i<0; i++) {
        		ans /= x;
        	}
        }
        else {
        	for(int i=1; i<=n; i++) {
        		ans *= x;
        	}
        }
        return ans;
    }

public:
	double myPow(double x, int n) {
		// double ans1 = myPow_bf(x, n);
		double ans2 = myPow_rec(x, n);
		return ans2;
	}
};

int main() {
	Solution solve;
	double x;
	int n;
	cin >> x >> n;
	double ans = solve.myPow(x, n);
	cout << fixed << setprecision(5) << ans << "\n";
	return 0;
}