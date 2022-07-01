#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// Time : O(n)
	// Space : O(n)
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        unordered_map<int, int> FoundSum;
        FoundSum.insert({0,1}); // Inserting 1 for sum = 0   ->   As when k gets fully consumed, we have to search for 0 sum
        int prefixSum = 0;
        for(int i=0; i<n; i++) {
        	prefixSum += nums[i];
        	if(FoundSum.find(prefixSum-k) != FoundSum.end()) {  // The extra value in prefixSum found before.. k-sum by removing those prefix.
        		count += FoundSum[prefixSum-k];  // Keep adding these counts
        	}
        	FoundSum[prefixSum]++;  // Keep storing this prefixSum after every index. (So, when required this prefix can be removed to get k)
        }
        return count;
    }
};

int main() {
	Solution solve;
	int n;
	cin >> n;
	vector<int> nums;
	for(int i=0; i<n; i++) {
		int ele;
		cin >> ele;
		nums.push_back(ele);
	}
	int k;
	cin >> k;
	int ans = solve.subarraySum(nums, k);
	cout << ans << endl;
	return 0;
}