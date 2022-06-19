#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
    double power2(double x, ll n) {
        double ans = 1.0;
        while(n > 0) {
            if(n % 2 == 1) {  // n is odd   ..   (x ^ n)    to    x * (x ^ n-1)
                ans *= x;
                n--;
            }
            else {  //  Converting (x ^ n) to ((x*x) ^ n/2)   ..   (3^4)  to  (9^2).
                x = x*x;
                n /= 2;
            }
        }
        return ans;
    }

	double power(double x, ll n) {
        if(n == 0) {
        	return 1;
        }
        if(n == 1) {
        	return x;
        }
        double smallAns = myPow(x, n/2);
        if(n % 2 == 0) {
        	if(smallAns == 0.0) {
        		return smallAns;
        	}
        	return (smallAns * smallAns);
        }
        else {
        	if(smallAns == 0.0) {
        		return smallAns;
        	}
        	return (smallAns * smallAns * x);
        }
    }

public:
    double myPow(double x, int n) {
    	ll newN = (ll)n;
    	if(n < 0) {
    		return (1 / power2(x, (-1)*newN));
    	}
    	return power2(x, newN);
    }
};

int main() {
	Solution solve;
	double x;
	int n;
	cin >> x >> n;
	double ans = solve.myPow(x, n);
	cout << fixed << setprecision(5) << ans << endl;
	return 0;
}