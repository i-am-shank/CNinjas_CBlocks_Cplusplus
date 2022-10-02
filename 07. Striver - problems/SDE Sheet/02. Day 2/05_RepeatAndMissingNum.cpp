#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
	vector<int> repeatedNumber(vector<int>& nums) {
		ll n = nums.size();
		ll sum = (n * (n+1)) / 2;
		ll sq = (n * (n+1) * ((2*n)+1)) / 6;
		for(ll i=0; i<n; i++) {
			sum -= (ll)(nums[i]);
			sq -= (ll)(nums[i]*nums[i]);
		}
		// m -> missing no.  ,  d -> duplicate no.
		// sum = (sum - (sum-m+d)) = (m-d)
		// square = (square - (square - m2 + d2))  =  (m2 - d2)
		// square  =  (m2 - d2)  =  (m+d) * (m-d)
		ll diff = sum; // m - d
		ll add = (sq / diff); // m + d
		int missing = (int)((diff + add) / 2);
		int duplicate = (int)((add - diff) / 2);
		vector<int> ans;
		ans.push_back(duplicate);
		ans.push_back(missing);
		return ans;
	}
};

int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i=0; i<n; i++) {
		cin >> nums[i];
	}
	Solution solve;
	vector<int> ans = solve.repeatedNumber(nums);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}