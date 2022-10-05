#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// Time : O(n)
	// Space : O(n) .. max. possible size of map
    int lengthOfLongestSubstring(string s) {
        int maxLen=0, currLen=0, start=0;
        int i=0, n=s.size();
        unordered_map<char,int> indexMap;
        while(i < n) {
        	if(indexMap.find(s[i]) != indexMap.end()) {
        		// cout << s[i] << " Update ";
        		start = max(start, indexMap[s[i]] + 1);
        		indexMap[s[i]] = i; // maintain latest occurence
        		currLen = (i - start) + 1;
        		// cout << currLen << "\n";
        		maxLen = max(maxLen, currLen);
        	}
        	else {
        		// cout << s[i] << " keep adding ";
        		currLen++;
        		// cout << currLen << "\n";
        		maxLen = max(maxLen, currLen);
        		indexMap[s[i]] = i; // If not there.. do an entry
        	}
        	i++;
        }
        return maxLen;
    }
};

int main() {
	string s;
	cin >> s;
	Solution solve;
	int ans = solve.lengthOfLongestSubstring(s);
	cout << ans << "\n";
	return 0;
}