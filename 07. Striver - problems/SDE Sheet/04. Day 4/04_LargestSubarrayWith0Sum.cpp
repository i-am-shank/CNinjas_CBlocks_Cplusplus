#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	// Time : O(n)
	// Space : O(n)
    int maxLen(vector<int>&arr, int n) {   
        vector<int> prefixSum(n);
        int sum = 0;
        for(int i=0; i<n; i++) {
        	sum += arr[i];
        	prefixSum[i] = sum;
        }
        int maxLength=0;
        unordered_map<int,int> sumMap;
        sumMap[0] = -1; // By default.. sum = 0 (index = -1)
        for(int i=0; i<n; i++) {
        	if(sumMap.find(prefixSum[i]) != sumMap.end()) {
        		// Same sum again.. subarray between sums up to 0.
        		int currLen = (i - sumMap[prefixSum[i]]);
        		maxLength = max(maxLength, currLen);
        	}
        	else {
        		sumMap[prefixSum[i]] = i;
        	}
        }
        return maxLength;
    }
};

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	Solution solve;
	int ans = solve.maxLen(arr, n);
	cout << ans << "\n";
	return 0;
}