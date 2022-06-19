#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> majorityElement2(vector<int>& nums) {  // Boyer Moore's voting algorithm
		int first = INT_MAX, second = INT_MAX, count1 = 0, count2 = 0, n = nums.size();
		vector<int> ans;
		for(int i=0; i<n; i++) {
			if(nums[i] == first) {
				count1++;
			}
			else if(nums[i] == second) {
				count2++;
			}
			else if(count1 == 0) {
				first = nums[i];
				count1++;
			}
			else if(count2 == 0) {
				second = nums[i];
				count2++;
			}
			else {
				count1--;
				count2--;
			}
		}
		// first , second  -->  contain 2 most frequent elements of array.
		// Now check if their frequency is more than n/3 or not.
		count1 = 0, count2 = 0;
		for(int i=0; i<n; i++) {
			if(nums[i] == first) {
				count1 ++;
			}
			else if(nums[i] == second) {
				count2++;
			}
		}
		if(count1 > n/3) {
			ans.push_back(first);
		}
		if(count2 > n/3) {
			ans.push_back(second);
		}
		return ans;
	}

    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> freqMap;
        int n = nums.size();
        vector<int> ans;
        for(int i=0; i<n; i++) {
        	freqMap[nums[i]]++;
        }
        unordered_map<int, int> :: iterator it;
        for(it=freqMap.begin(); it!=freqMap.end(); it++) {
        	if(it->second > n/3) {
        		ans.push_back(it->first);
        	}
        }
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
	vector<int> ans = solve.majorityElement2(nums);
	int a = ans.size();
	for(int i=0; i<a; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}