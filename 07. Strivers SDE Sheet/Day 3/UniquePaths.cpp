#include <bits/stdc++.h>
using namespace std;

class Solution {
	int uniquePaths2Help(int m, int n, int** arr) {  // Memoization  ..  Time = O(m*n)
		if(arr[m][n] != -1) {
			return arr[m][n];
		}
		if(m<=0 || n<=0) {
			arr[m][n] = 0;
			return 0;
		}
		if(m==1 && n==1) {
			arr[m][n] = 1;
			return 1;
		}
		arr[m][n-1] = uniquePaths2Help(m, n-1, arr);
		arr[m-1][n] = uniquePaths2Help(m-1, n, arr);
		arr[m][n] = (arr[m][n-1] + arr[m-1][n]);
		return arr[m][n];
	}

public:
	// Top-down DP
	int uniquePaths3(int m, int n) {
		int **arr = new int*[m+1];  // Initialisation
		for(int i=0; i<m+1; i++) {
			arr[i] = new int[n+1];
			for(int j=0; j<n+1; j++) {
				arr[i][j] = 0;
			}
		}
		for(int i=1; i<m+1; i++) {  // No need to iterate over 0th row OR 0th column.
			for(int j=1; j<n+1; j++) {
				if(i==1 && j==1) {
					arr[i][j] = 1;
					continue;
				}
				arr[i][j] = arr[i-1][j] + arr[i][j-1];
			}
		}
		int ans = arr[m][n];
		for(int i=0; i<m+1; i++) {
			delete []arr[i];
		}
		delete []arr;
		return ans;
	}

	// Memoization
	int uniquePaths2(int m, int n) {
		int **arr = new int*[m+1];
		for(int i=0; i<m+1; i++) {
			arr[i] = new int[n+1];
			for(int j=0; j<n+1; j++) {
				arr[i][j] = -1;
			}
		}
		int ans = uniquePaths2Help(m, n, arr);
		for(int i=0; i<m+1; i++) {
			delete []arr[i];
		}
		delete []arr;
		return ans;
	}

    int uniquePaths(int m, int n) {  // Time = O(2^(m*n))  ..  Space = O(1)
        if(m<=0 || n<=0) {
        	return 0;
        }
        if(m==1 && n==1) {
        	return 1;
        }
        int smallAns1 = uniquePaths(m, n-1);
        int smallAns2 = uniquePaths(m-1, n);
        return (smallAns1 + smallAns2);
    }
};

int main() {
	Solution solve;
	int m, n;
	cin >> m >> n;
	int ans = solve.uniquePaths3(m, n);
	cout << ans << endl;
	return 0;
}