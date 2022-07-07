#include <bits/stdc++.h>
using namespace std;

class Solution {
	// Recursion
	// Time : O(n)
	// Space : O(n)
	int maxArea2(int n, vector<int>& heights) {
		int leftSmaller[n], rightSmaller[n];
		stack<int> stk;
		for(int i=0; i<n; i++) {
			while(!stk.empty() && heights[stk.top()] >= heights[i]) {
				stk.pop();
			}
			if(!stk.empty()) {
				leftSmaller[i] = stk.top() + 1;
			}
			else {
				leftSmaller[i] = 0;
			}
			stk.push(i);
		}
		while(!stk.empty()) {
			stk.pop();
		}
		for(int i=n-1; i>=0; i--) {
			while(!stk.empty() && heights[stk.top()] >= heights[i]) {
				stk.pop();
			}
			if(!stk.empty()) {
				rightSmaller[i] = stk.top() - 1;
			}
			else {
				rightSmaller[i] = n-1;
			}
			stk.push(i);
		}
		int area = 0;
		for(int i=0; i<n; i++) {
			area = max(area, (heights[i]*(rightSmaller[i]-leftSmaller[i]+1)));
		}
		return area;
	}

	// Brute-force
	// Time : O(n^2)
	// Space : O(n) .. Recursion stack
	int maxArea_bf(int n, int i, vector<int>& heights) {
		if(i == n) {
			return 0;
		}
		int count = 1;
		int j = i-1;
		// Count left-heights
		while(j>=0 && heights[j]>=heights[i]) {
			j--;
			count++;
		}
		j = i+1;
		// Count right-heights
		while(j<n && heights[j]>=heights[i]) {
			j++;
			count++;
		}
		int area = (count * heights[i]);
		int nextArea = maxArea_bf(n, i+1, heights);
		return max(area, nextArea);
	}

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        // int ans1 = maxArea_bf(n, 0, heights);
        int ans2 = maxArea2(n, heights);
        return ans2;
    }
};

int main() {
	Solution solve;
	int n;
	cin >> n;
	vector<int> heights;
	for(int i=0; i<n; i++) {
		int ele;
		cin >> ele;
		heights.push_back(ele);
	}
	int ans = solve.largestRectangleArea(heights);
	cout << ans << endl;
	return 0;
}