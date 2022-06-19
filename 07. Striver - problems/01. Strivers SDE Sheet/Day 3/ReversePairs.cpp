#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
	int rPairsMerge(int s, int m, int e, vector<int>& nums) {
		int i=s, j = m+1, ans = 0, k=0;
		for(int l=i; l<=m; l++) {   // Counting reverse-pairs.
			int ele = nums[l];
			while(j<=e  &&  (ll)(2*nums[j]) < ele) {
				j++;
			}
			ans += (j - (m+1));
		}
		int temp[e-s+1];
		i=s, j=m+1;
		while(i<=m && j<=e) {
			if(nums[i] < nums[j]) {
				temp[k++] = nums[i++];
			}
			else {
				temp[k++] = nums[j++];
			}
		}
		while(i <= m) {
			temp[k++] = nums[i++];
		}
		while(j <= e) {
			temp[k++] = nums[j++];
		}
		for(int i=0; i<k; i++) {
			nums[s+i] = temp[i];
		}
		return ans;
	}

	int rPairs(int s, int e, vector<int>& nums) {
		if(s >= e) {
			return 0;
		}
		int mid = (s + e) / 2;
		int smallAns1 = rPairs(s, mid, nums);
		int smallAns2 = rPairs(mid+1, e, nums);
		int smallAns3 = rPairsMerge(s, mid, e, nums);
		return (smallAns1 + smallAns2 + smallAns3);
	}

public:
    int reversePairs(vector<int>& nums) {
    	int n = nums.size();
        int ans = rPairs(0, n-1, nums);
        return ans;
    }
};

int main() {
	int n;
	cin >> n;
	vector<int> nums;
	for(int i=0; i<n; i++) {
		int ele;
		cin >> ele;
		nums.push_back(ele);
	}
	Solution solve;
	int ans = solve.reversePairs(nums);
	cout << ans << endl;
	return 0;
}