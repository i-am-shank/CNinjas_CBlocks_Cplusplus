#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while(columnNumber != 0) {
        	int x = columnNumber % 26;
        	// cout << columnNumber << " " << x << "\n";
        	bool toBreak = (columnNumber == 26);
        	if(x == 0) {
        		ans = "Z" + ans;
        		columnNumber = (columnNumber/26) - 1;
        	}
        	else {
        		char curr = ('A' + (x-1));
        		ans = curr + ans;
        		columnNumber /= 26;
        	}
        	if(toBreak) {
        		break;
        	}
        }
        return ans;
    }
};

int main() {
	int columnNumber;
	cin >> columnNumber;
	Solution solve;
	string ans = solve.convertToTitle(columnNumber);
	cout << ans << "\n";
	return 0;
}