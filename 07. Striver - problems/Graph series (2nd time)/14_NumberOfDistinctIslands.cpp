#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pp;

class Solution {
	bool isValid(int x, int y, int n, int m) {
		return (x>=0 && y>=0 && x<n && y<m);
	}

	void dfs(vector<vector<int>>& grid, int x, int y, int n, int m, vector<pp>& island, vector<vector<bool>>& visited) {
		int dx[4] = {0,0,1,-1};
		int dy[4] = {1,-1,0,0};
		for(int k=0; k<4; k++) {
			int x2=x+dx[k], y2=y+dy[k];
			if(isValid(x2,y2,n,m) && !visited[x2][y2] && grid[x2][y2]==1) {
				island.push_back(make_pair(x2,y2));
				visited[x2][y2] = true;
				dfs(grid, x2, y2, n, m, island, visited);
			}
		}
		return;
	}

  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        set<vector<pp>> islands;
        vector<vector<bool>> visited(n, vector<bool>(m,false));
        for(int i=0; i<n; i++) {
        	for(int j=0; j<m; j++) {
        		if(!visited[i][j] && grid[i][j]==1) {
        			visited[i][j] = true;
        			vector<pp> island;
        			island.push_back(make_pair(i,j));
        			dfs(grid, i, j, n, m, island, visited);
        			for(int k=0; k<island.size(); k++) {
        				pp ele = island[k];
        				ele.first -= i;
        				ele.second -= j;
        				island[k] = ele;
        			}
        			sort(island.begin(), island.end());
        			islands.insert(island);
        		}
        	}
        }
        int count = islands.size();
        return count;
    }
};

int main() {
	Solution solve;
	int n, m;
	cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m,0));
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> grid[i][j];
		}
	}
	int ans = solve.countDistinctIslands(grid);
	cout << ans << "\n";
	return 0;
}