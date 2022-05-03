#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// Time complexity = O(N^2)

    void rotate2(vector<vector<int>>& matrix) {   // O(N) space complexity  ..  but faster approach
        vector<vector<int>> newMatrix;
        int n = matrix.size();
        for(int i=0; i<n; i++) {
        	vector<int> temp;
        	for(int j=0; j<n; j++) {
        		temp.push_back(0);
        	}
        	newMatrix.push_back(temp);
        }
        for(int i=0; i<n; i++) {
        	for(int j=0; j<n; j++) {   //  (n x n) matrix
        		newMatrix[i][j] = matrix[(n-1)-j][i];
        	}
        }
        matrix = newMatrix;
        return;
    }

    void rotate(vector<vector<int>>& matrix) {
    	int n = matrix.size();
    	// Mirror along main diagonal.
    	for(int i=0; i<n; i++) {
    		for(int j=0; j<i; j++) {
    			int temp = matrix[i][j];
    			matrix[i][j] = matrix[j][i];
    			matrix[j][i] = temp;
    		}
    	}
    	// Mirror along middle column.
    	for(int i=0; i<n; i++) {
    		for(int j=0; j<n/2; j++) {
    			int temp = matrix[i][j];
    			matrix[i][j] = matrix[i][(n-1)-j];
    			matrix[i][(n-1)-j] = temp;
    		}
    	}
    	return;
    }
};

int main() {
	Solution solve;
	vector<vector<int>> matrix;
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		vector<int> temp;
		for(int j=0; j<n; j++) {
			int ele;
			cin >> ele;
			temp.push_back(ele);
		}
		matrix.push_back(temp);
	}
	solve.rotate(matrix);
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}