#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// Time : O(n^2)
	// Space : O(1)
    void rotate(vector<vector<int>>& matrix) {
    	int n = matrix.size();
        for(int i=0; i<n/2; i++) {
        	for(int j=0; j<n; j++) {
        		int temp = matrix[i][j];
        		matrix[i][j] = matrix[(n-1)-i][j];
        		matrix[(n-1)-i][j] = temp;
        	}
        }
        for(int i=0; i<n; i++) {
        	for(int j=0; j<i; j++) {
        		int temp = matrix[i][j];
        		matrix[i][j] = matrix[j][i];
        		matrix[j][i] = temp;
        	}
        }
        return;
    }
};

int main() {
	int n;
	cin >> n;
	vector<vector<int>> matrix(n, vector<int>(n,0));
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> matrix[i][j];
		}
	}
	Solution solve;
	solve.rotate(matrix);
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}