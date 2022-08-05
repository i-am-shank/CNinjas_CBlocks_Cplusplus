#include <bits/stdc++.h>
using namespace std;

// Time : O(n * log(m * 10^7))
// Space : O(1)
double findNthRootOfM(int n, int m) {
    double s=1, e=m;
    // Finding answer with 6-decimal place
    // So diff > -1e8  ..  keep searching (searching till 7th decimal)
    //   -> then answer will be rounded-off.
    while(e-s > 0.00000001) {
        double prod=1;
        double mid = s + ((e-s)/2.0);
        for(int i=0; i<n; i++) {
            prod *= mid;
        }
        if(prod > m) {
            e = mid;
        }
        else {
            s = mid;
        }
    }
    return s;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		double ans = findNthRootOfM(n, m);
		cout << ans << endl;
	}
	return 0;
}