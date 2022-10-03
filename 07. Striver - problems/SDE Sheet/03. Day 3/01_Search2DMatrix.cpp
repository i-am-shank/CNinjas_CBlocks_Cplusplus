#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// Time : O(m+n)
	// Space : O(1)
	// -> Visualizing sorted-matrix as a binary-search tree
	//    -> Root node is right-most element of top-row.
	//    -> Elements rightward (i.e. downward in matrix) .. greater
	//    -> Elements leftward (i.e. leftward in matrix) .. smaller
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(), n=matrix[0].size();
        int r=0, c=n-1;
        bool flag = false;
        while(r>=0 && r<m && c>=0 && c<n) {
        	// cout << r << " " << c << " " << matrix[r][c] << "\n";
        	if(matrix[r][c] == target) {
        		flag = true;
        		break;
        	}
        	else if(matrix[r][c] > target) {
        		// Move leftward.. in same row
        		c--;
        	}
        	else {
        		// Move to next row
        		r++;
        	}
        }
        return flag; // If not found, will never be marked true
    }
};

int main() {
	Solution solve;
	int m, n, target;
	cin >> m >> n >> target;
	vector<vector<int>> matrix(m, vector<int>(n,0));
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cin >> matrix[i][j];
		}
	}
	bool ans = solve.searchMatrix(matrix, target);
	cout << (ans == true ? "true" : "false") << "\n";
	return 0;
}