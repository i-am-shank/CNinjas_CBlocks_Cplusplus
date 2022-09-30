#include <bits/stdc++.h>
using namespace std;

typedef pair<pair<int,int>, int> pp;

class Solution {
	bool isValid(int x, int y, int m, int n) {
		return (x>=0 && y>=0 && x<m && y<n);
	}

public:
	// Time : O(m*n)
	// Space : O(m*n)
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    	int m = mat.size(), n = mat[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pp> q;
        for(int i=0; i<m; i++) {
        	for(int j=0; j<n; j++) {
        		if(mat[i][j] == 0) {
        			pp ele;
        			ele.first.first=i, ele.first.second=j;
        			ele.second = 0; // Distance from 0 (itself 0)
        			q.push(ele);
        			visited[i][j] = true;
        		}
        	}
        }
        vector<vector<int>> dist(m, vector<int>(n,0));
        while(!q.empty()) {
        	int s = q.size();
        	for(int i=0; i<s; i++) {
        		pp front = q.front();
        		q.pop();
        		int x1=front.first.first, y1=front.first.second;
        		int d1=front.second;
        		dist[x1][y1] = d1; // Change distances
        		int dx[4] = {0,0,1,-1};
        		int dy[4] = {1,-1,0,0};
        		for(int k=0; k<4; k++) {
        			int x2=(x1+dx[k]), y2=(y1+dy[k]);
        			int d2 = (1+d1);
        			if(isValid(x2,y2,m,n) && !visited[x2][y2]) {
        				visited[x2][y2] = true;
        				pp ele;
        				ele.first.first=x2, ele.first.second=y2;
        				ele.second=d2;
        				q.push(ele);
        			}
        		}
        	}
        }
        return dist;
    }
};

int main() {
	Solution solve;
	int m, n;
	cin >> m >> n;
	vector<vector<int>> mat(m, vector<int>(n,0));
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cin >> mat[i][j];
		}
	}
	vector<vector<int>> ans = solve.updateMatrix(mat);
	for(int i=0; i<ans.size(); i++) {
		for(int j=0; j<ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}