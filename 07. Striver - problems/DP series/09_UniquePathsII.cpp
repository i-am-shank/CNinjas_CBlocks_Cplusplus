#include <bits/stdc++.h>
using namespace std;

class Solution {
    // Tabulation  ->   space optimization
    // Time : O(m*n)
    // Space : O(n)
    int count_dp_space(vector<vector<int>>& obstacleGrid, int m, int n) {
        vector<int> prevRow(n+1, 0);
        for(int i=0; i<=m; i++) {
            vector<int> currRow(n+1, 0);
            for(int j=0; j<=n; j++) {
                if(i==0 && j==0) {
                    currRow[0] = 1;
                }
                if(obstacleGrid[i][j] == 1) {
                    currRow[j] = 0;
                }
                else {
                    if(i > 0) {
                        currRow[j] += prevRow[j];
                    }
                    if(j > 0) {
                        currRow[j] += currRow[j-1];
                    }
                }
            }
            prevRow = currRow; // For next iteration
        }
        return prevRow[n];
    }

    // Tabulation
    // Time : O(m*n)
    // Space : O(m*n)
    int count_dp(vector<vector<int>>& obstacleGrid, int m, int n) {
        vector<vector<int>> dp (m+1, vector<int>(n+1, 0));
        dp[0][0] = 1;
        for(int i=0; i<=m; i++) {
            for(int j=0; j<=n; j++) {
                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                }
                else {
                    if(i > 0) {
                        dp[i][j] += dp[i-1][j];
                    }
                    if(j > 0) {
                        dp[i][j] += dp[i][j-1];
                    }
                }
            }
        }
        return dp[m][n];
    }

    // Memoization
    // Time : O(m*n)
    // Space : O(m*n)     ..  + O(m+n)  -> Recursion stack
    int count_mem_help(vector<vector<int>>& obstacleGrid, int m, int n, vector<vector<int>>& dp) {
        if(dp[m][n] != -1) {
            return dp[m][n];
        }
        if(m>=0 && n>=0 && obstacleGrid[m][n]==1) {
            dp[m][n] = 0;
            return dp[m][n];
        }
        if(m==0 && n==0) {
            dp[m][n] = 1;
            return dp[m][n];
        }
        int ans1 = count_rec(obstacleGrid, m-1, n);
        int ans2 = count_rec(obstacleGrid, m, n-1);
        dp[m][n] = (ans1 + ans2);
        return dp[m][n];
    }

    int count_mem(vector<vector<int>>& obstacleGrid, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        return count_mem_help(obstacleGrid, m, n, dp);
    }

    // Recursion
    // Time : O(2^n)
    // Space : O(2^n) .. Recursion stack
    int count_rec(vector<vector<int>>& obstacleGrid, int m, int n) {
        if((m>=0 && n>=0 && obstacleGrid[m][n]==1) || (m<0 || n<0)) {
            return 0;
        }
        if(m==0 && n==0) {
            return 1;
        }
        int ans1 = count_rec(obstacleGrid, m-1, n);
        int ans2 = count_rec(obstacleGrid, m, n-1);
        return (ans1 + ans2);
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        /*
        int ans1 = count_rec(obstacleGrid, m-1, n-1);
        int ans2 = count_mem(obstacleGrid, m-1, n-1);
        int ans3 = count_dp(obstacleGrid, m-1, n-1);
        */
        int ans4 = count_dp_space(obstacleGrid, m-1, n-1);
        return ans4;
    }
};

int main() {
	Solution solve;
    int m, n;
    cin >> m >> n;
    vector<vector<int>> obstacleGrid;
    for(int i=0; i<m; i++) {
        vector<int> row;
        for(int j=0; j<n; j++) {
            int ele;
            cin >> ele;
            row.push_back(ele);
        }
        obstacleGrid.push_back(row);
    }
    int ans = solve.uniquePathsWithObstacles(obstacleGrid);
    cout << ans << endl;
    return 0;
}