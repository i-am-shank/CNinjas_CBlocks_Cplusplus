#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int majorityElement3(vector<int>& nums) {  // Time = O(N)  ..  Space = O(1)
		int currEle, count = 0, n = nums.size();
		for(int i=0; i<n; i++) {
			if(count == 0) {
				currEle = nums[i];
			}
			if(nums[i] == currEle) {  // As majority element will come more than n/2 times.
				count++;     //  It's confirm that, count will be +ve for it.. & currEle = majority
			}
			else {
				count--;
			}
		}
		return currEle;
	}

	int majorityElement2(vector<int>& nums) {  // Time = O(N)  ..  Space = O(N)
		int n = nums.size();
		unordered_map<int, int> freqMap;
		for(int i=0; i<n; i++) {
			freqMap[nums[i]]++;
			if(freqMap[nums[i]] > n/2) {
				return nums[i];
			}
		}
		return 0;  // as there is always a majority element.. code never reaches here
	}

    int majorityElement(vector<int>& nums) {  // Time = O(NlogN)  ..  Space = O(1)
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n/2];
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
	int ans = solve.majorityElement2(nums);
	cout << ans << endl;
	return 0;
}