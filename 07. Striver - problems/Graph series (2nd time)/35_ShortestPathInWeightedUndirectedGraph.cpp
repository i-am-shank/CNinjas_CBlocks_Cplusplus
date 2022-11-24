#include <bits/stdc++.h>
using namespace std;

class Solution {
	#define pp pair<int,int>
	#define fi first
	#define se second
	#define mp make_pair

public:
	vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pp>> adj(n+1, vector<pp>());
        int src=1, dest=n;
        for(int i=0; i<m; i++) {
        	int f=edges[i][0], s=edges[i][1], w=edges[i][2];
        	adj[f].push_back(mp(s,w));
        	adj[s].push_back(mp(f,w)); // undirected edge
        }
        vector<int> ans = minPath(adj, src, dest);
        return ans;
    }
};

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> edges(m, vector<int>(3,0));
	for(int i=0; i<m; i++) {
		vector<int> edge(3,0);
		for(int j=0; j<3; j++) {
			cin >> edge[j];
		}
		edges[i] = edge;
	}
	Solution solve;
	vector<int> ans = solve.shortestPath(n, m, edges);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}