#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isUgly(int n) {
    	if(n <= 0) {
    		return false;
    	}
        while(n % 2 == 0) {
        	n /= 2;
        }
        while(n % 3 == 0) {
        	n /= 3;
        }
        while(n % 5 == 0) {
        	n /= 5;
        }
        return (n == 1); // All factors were 2,3 & 5.
    }
};

int main() {
	int n;
	cin >> n;
	Solution solve;
	bool ans = solve.isUgly(n);
	cout << (ans==true ? "true":"false") << "\n";
	return 0;
}