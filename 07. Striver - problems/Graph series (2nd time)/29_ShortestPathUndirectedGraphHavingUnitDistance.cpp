#include <bits/stdc++.h>
using namespace std;

#define pp pair<int,int>
#define fi first
#define se second
#define mp make_pair

class Solution {
public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n, int e, int src){
    	vector<vector<int>> adj(n, vector<int>());
        for(int i=0; i<e; i++) {
        	int f=edges[i][0], s=edges[i][1];
        	// f -- s  (undirected edge .. weight = 1)
        	adj[f].push_back(s);
        	adj[s].push_back(f);
        }
        vector<bool> visited(n, false);
        queue<pp> q;
        q.push(mp(src,0)); // as src is source node
        visited[src] = true;
        vector<int> dist(n, 1e8);
        while(!q.empty()) {
        	pp front = q.front();
        	q.pop();
        	int n1=front.fi, d1=front.se;
        	if(dist[n1] > d1) { // a shorter dist. available
        		dist[n1] = d1;
        	}
        	for(auto it: adj[n1]) {
        		if(!visited[it]) {
        			int d2 = d1+1;
	        		q.push(mp(it,d2));
	        		visited[it] = true;
        		}
        	}
        }
        for(int i=0; i<n; i++) {
        	if(dist[i] == 1e8) {
        		dist[i] = -1; // Not reachable from src
        	}
        }
        return dist;
    }
};

int main() {
	int n, e, src;
	cin >> n >> e >> src;
	vector<vector<int>> edges(e, vector<int>(2,0));
	for(int i=0; i<e; i++) {
		int f, s;
		cin >> f >> s;
		vector<int> edge;
		edge.push_back(f);
		edge.push_back(s);
		edges[i] = edge;
	}
	Solution solve;
	vector<int> ans = solve.shortestPath(edges, n, e, src);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}