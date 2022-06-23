#include <bits/stdc++.h>
using namespace std;

// Tabulation -> space optimization
// Time : O(n)
// Space : O(1)
int training_dp_space(int n, vector<vector<int>>& points) {
	vector<int> dp(4, 0);
	for(int last=0; last<4; last++) {  // Initialization -> base case
		int maxVal = 0;
		for(int task=0; task<3; task++) {
			if(task != last) {
				maxVal = max(maxVal, points[0][task]);
			}
		}
		dp[last] = maxVal;
	}
	for(int i=1; i<=n; i++) { // iterating on day
		vector<int> temp(4, 0);
		for(int last=0; last<4; last++) { // iterating on last
			temp[last] = 0;
			for(int task=0; task<3; task++) {
				if(task != last) {
					int smallAns = points[i][task] + dp[task];
					temp[last] = max(temp[last], smallAns);
				}
			}
		}
		dp = temp;
	}
	return dp[3];
}

// Tabulation
// Time : O(n)
// Space : O(n)
int training_dp(int n, vector<vector<int>>& points) {
	vector<vector<int>> dp(n+1, vector<int>(4, 0));
	for(int last=0; last<4; last++) {  // Initialization -> base case
		int maxVal = 0;
		for(int task=0; task<3; task++) {
			if(task != last) {
				maxVal = max(maxVal, points[0][task]);
			}
		}
		dp[0][last] = maxVal;
	}
	for(int i=1; i<=n; i++) { // iterating on day
		for(int last=0; last<4; last++) { // iterating on last
			int maxPoint = 0;
			for(int task=0; task<3; task++) {
				if(task != last) {
					int smallAns = points[i][task] + dp[i-1][task];
					maxPoint = max(maxPoint, smallAns);
				}
			}
			dp[i][last] = maxPoint;
		}
	}
	return dp[n][3];
}

// Memoization
// Time : (n*3)
// Space : (n*3)
int training_mem_help(int n, vector<vector<int>>& points, int last, vector<vector<int>>& dp) {
	if(dp[n][last] != -1) {
		return dp[n][last];
	}
	if(n == 0) {
		int maxVal = 0;
		for(int i=0; i<3; i++) {
			if(i != last) {
				maxVal = max(maxVal, points[n][i]);
			}
		}
		dp[n][last] = maxVal;
		return dp[n][last];
	}
	int ans = 0;
	for(int i=0; i<3; i++) {
		if(i != last) {
			int smallAns = points[n][i] + training_mem_help(n-1, points, i, dp);
			ans = max(ans, smallAns);
		}
	}
	dp[n][last] = ans;
	return dp[n][last];
}

int training_mem(int n, vector<vector<int>> &points, int last) {
	vector<vector<int>> dp(n+1, vector<int> (4, -1));
	int ans = training_mem_help(n, points, last, dp);
	return ans;
}

// Recursion
// Time : O(3^n)
// Space : O(1)
int training_rec(int n, vector<vector<int>> &points, int last) {
	if(n == 0) {
		int maxVal = 0;
		for(int i=0; i<3; i++) {
			if(i != last) {
				maxVal = max(maxVal, points[n][i]);
			}
		}
		return maxVal;
	}
	int ans = 0;
	for(int i=0; i<3; i++) {
		if(i != last) {
			int smallAns = points[n][i] + training_rec(n-1, points, i);
			ans = max(ans, smallAns);
		}
	}
	return ans;
}

int ninjaTraining(int n, vector<vector<int>> &points){
    /*int ans1 = training_rec(n-1, points, 3);
    int ans2 = training_mem(n-1, points, 3);
    int ans3 = training_dp(n-1, points);*/
    int ans4 = training_dp_space(n-1, points);
    return ans4;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<vector<int>> points;
		for(int i=0; i<n; i++) {
			vector<int> dayPoints;
			for(int i=0; i<3; i++) {
				int point;
				cin >> point;
				dayPoints.push_back(point);
			}
			points.push_back(dayPoints);
		}
		int ans = ninjaTraining(n, points);
		cout << ans << endl;
	}
	return 0;
}