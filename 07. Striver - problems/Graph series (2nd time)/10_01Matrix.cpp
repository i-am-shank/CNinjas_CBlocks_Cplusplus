#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pp;

class Solution {
	bool isValid(int x, int y, int m, int n) {
		return (x>=0 && y>=0 && x<m && y<n);
	}

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    	int m=mat.size(), n=mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n,0));
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        queue<pp> q;
        for(int i=0; i<m; i++) {
        	for(int j=0; j<n; j++) {
        		if(mat[i][j] == 0) {
        			q.push(make_pair(i,j));
        			visited[i][j] = true;
        			dist[i][j] = 0; // itself 0
        		}
        	}
        }
        while(!q.empty()) {
        	pp front = q.front();
        	q.pop();
        	int x1=front.first, y1=front.second;
        	int dx[4] = {0,0,1,-1};
        	int dy[4] = {1,-1,0,0};
        	for(int k=0; k<4; k++) {
        		int x2=x1+dx[k], y2=y1+dy[k];
        		if(isValid(x2,y2,m,n) && !visited[x2][y2]) {
        			visited[x2][y2] = true;
        			q.push(make_pair(x2,y2));
        			dist[x2][y2] = 1 + dist[x1][y1];
        		}
        	}
        }
        return dist;
    }
};

int main() {
	int m, n;
	cin >> m >> n;
	vector<vector<int>> mat(m, vector<int>(n, 0));
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cin >> mat[i][j];
		}
	}
	Solution solve;
	vector<vector<int>> ans = solve.updateMatrix(mat);
	for(int i=0; i<ans.size(); i++) {
		for(int j=0; j<ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}