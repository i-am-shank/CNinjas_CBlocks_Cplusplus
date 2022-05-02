#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> row;
        unordered_set<int> col;
        int n = matrix.size(), m = matrix[0].size();
        for(int i=0; i<n; i++) {
        	for(int j=0; j<m; j++) {
        		if(matrix[i][j] == 0) {
        			row.insert(i);
        			col.insert(j);
        		}
        	}
        }
        unordered_set<int> :: iterator it;
        for(it=row.begin(); it!=row.end(); it++) {
        	int rowNum = *it;
        	for(int i=0; i<m; i++) {
        		matrix[rowNum][i] = 0;
        	}
        }
        for(it=col.begin(); it!=col.end(); it++) {
        	int colNum = *it;
        	for(int i=0; i<n; i++) {
        		matrix[i][colNum] = 0;
        	}
        }
        return;
    }
};

int main() {
	Solution solve;
	vector<vector<int>> matrix;
	int n, m;
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		vector<int> temp;
		for(int j=0; j<m; j++) {
			int ele;
			cin >> ele;
			temp.push_back(ele);
		}
		matrix.push_back(temp);
	}
	solve.setZeroes(matrix);
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}