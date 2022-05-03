#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        unordered_map<int, int> freqMap;
        for(int i=0; i<n; i++) {
            if(freqMap.find(nums[i]) != freqMap.end()) {
                ans = nums[i];
                break;
            }
            freqMap[nums[i]] = 1;
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
    int ans = solve.findDuplicate(nums);
    cout << ans << endl;
    return 0;
}