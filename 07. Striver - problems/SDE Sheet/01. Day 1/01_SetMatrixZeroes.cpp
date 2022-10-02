#include <bits/stdc++.h>
using namespace std;

// Approach 1 :-     (Space : O(1)) .. but not-possible
                  // ..as the 3rd value is captured by elements
	// Convert required boxes to a 3rd value
	// ..so that the overlapping problem doesn't exists
	// Convert all 2's back to 0s
// Approach 2 :-     (Space : O(m+n))
	// Store the rows & column-nos. having 0s
	// Iterate again in matrix.. if row or column is stored -> convert to 0

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    	int m=matrix.size(), n=matrix[0].size();
    	unordered_set<int> rows;
		unordered_set<int> cols;
        for(int i=0; i<m; i++) {
        	for(int j=0; j<n; j++) {
        		if(matrix[i][j] == 0) {
        			rows.insert(i);
        			cols.insert(j);
        		}
        	}
        }
        for(int i=0; i<m; i++) {
        	for(int j=0; j<n; j++) {
        		if(rows.find(i) != rows.end()) {
        			matrix[i][j] = 0;
        		}
        		else if(cols.find(j) != cols.end()) {
        			matrix[i][j] = 0;
        		}
        	}
        }
        return;
    }
};

int main() {
	int m, n;
	cin >> m >> n;
	vector<vector<int>> matrix(m, vector<int>(n,0));
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cin >> matrix[i][j];
		}
	}
	Solution solve;
	solve.setZeroes(matrix);
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}