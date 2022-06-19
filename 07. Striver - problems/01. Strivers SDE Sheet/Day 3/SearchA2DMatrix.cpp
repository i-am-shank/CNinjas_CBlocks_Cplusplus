#include <bits/stdc++.h>
using namespace std;

class Solution {
	bool search(vector<int> arr, int target) {
		int n = arr.size();
		if(n == 0) {
			return false;
		}
		int s = 0, e = n-1;
		bool flag = false;
		while(s <= e) {
			int mid = (s+e) / 2;
			if(arr[mid] == target) {
				flag = true;
				break;
			}
			else if(arr[mid] > target) {
				e = mid-1;
			}
			else {
				s = mid+1;
			}
		}
		return flag;
	}

public:

	bool searchMatrix2(vector<vector<int>>& matrix, int target) {
		int rows = matrix.size();
		int cols = matrix[0].size();
		int r = 0, c = cols-1;
		while(r<rows && c>=0) {
			if(matrix[r][c] == target) {
				return true;
			}
			else if(matrix[r][c] > target) {
				c--;
			}
			else {
				r++;
			}
		}
		return false;
	}

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int row = n-1;
        for(int i=0; i<n; i++) {
        	if(matrix[i][0] > target) {
        		if(i == 0) {
        			return false;
        		}
        		row = i-1;
        		break;
        	}
        }
        vector<int> arr = matrix[row];
        int m = arr.size();
        bool ans = search(arr, target);
        return ans;
    }
};

int main() {
	vector<vector<int>> matrix;
	int m, n;
	cin >> m >> n;
	for(int i=0; i<m; i++) {
		vector<int> temp;
		for(int j=0; j<n; j++) {
			int ele;
			cin >> ele;
			temp.push_back(ele);
		}
		matrix.push_back(temp);
	}
	int target;
	cin >> target;
	Solution solve;
	bool ans = solve.searchMatrix(matrix, target);
	cout << (ans == true ? "True" : "False") << endl;
	return 0;
}