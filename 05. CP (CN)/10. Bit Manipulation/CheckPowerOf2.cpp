#include <bits/stdc++.h>
using namespace std;

bool checkPower2Better(int n) {   //  Time Complexity = O(1).
	int temp = n-1;
	if((n & temp) == 0) {  // if n == 2^i  ..  ith bit is 1 and all bits < i are 0.
		return true;         //  And in n-1  ..  all bits < i are 1.  .. so there & is 0.
	}
	return false;
}

bool checkPower2(int n) {   //  Time Complexity = O(log N)  
	                            // ..  same as  % operation  to check even
	int temp = n;
	int countSetBits = 0;
	while(temp != 0) {
		int x = temp & 1;
		if(x != 0) {
			countSetBits ++;
		}
		temp = temp >> 1;
	}
	if(countSetBits <= 1) {
		return true;
	}
	return false;
}

int main() {
	int n;
	cin >> n;
	bool ans = checkPower2Better(n);
	cout << (ans == true ? "Yes" : "No") << endl;
	return 0;
}