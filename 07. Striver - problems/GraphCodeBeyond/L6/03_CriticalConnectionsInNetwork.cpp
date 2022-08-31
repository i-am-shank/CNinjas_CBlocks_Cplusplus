#include <bits/stdc++.h>
using namespace std;

class Solution {
	void dfs(vector<vector<int>>& adjList, int node, int par, vector<bool>& visited, int& timer, vector<int>& low, vector<int>& tin, vector<vector<int>>& bridges) {
		visited[node] = true;
		timer++;
		tin[node] = timer;
		low[node] = timer;
		for(auto adjNode: adjList[node]) {
			if(adjNode == par) {
				continue;
			}
			else {
				if(!visited[adjNode]) {
					dfs(adjList, adjNode, node, visited, timer, low, tin, bridges);
					low[node] = min(low[node], low[adjNode]);
					// If adjNode is connected by some-other path to node..
					// Above line will help in indicating this
					if(low[adjNode] > tin[node]) {
						// Has reached to adjNode only from node
						// No other path to adjNode .. from node
						// Bridge found !!
						vector<int> bridge;
						bridge.push_back(adjNode);
						bridge.push_back(node);
						bridges.push_back(bridge);
					}
				}
				else {
					// Already visited before.. backtracking
					low[node] = min(low[node], low[adjNode]);
				}
			}
		}
		return;
	}

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    	int m = connections.size();
        vector<vector<int>> adjList(n, vector<int>());
        for(int i=0; i<m; i++) { // adjList formed
        	int c1=connections[i][0], c2=connections[i][1];
        	adjList[c1].push_back(c2);
        	adjList[c2].push_back(c1);
        }
        vector<bool> visited(n, false);
        vector<vector<int>> bridges;
        vector<int> tin(n);
        vector<int> low(n);
        int timer=0;
        for(int i=0; i<n; i++) {
        	if(!visited[i]) {
        		dfs(adjList, i, -1, visited, timer, tin, low, bridges);
        	}
        }
        return bridges;
    }
};

int main() {
	Solution solve;
	int n, m;
	cin >> n >> m;
	vector<vector<int>> connections(m, vector<int>(2,0));
	for(int i=0; i<m; i++) {
		for(int j=0; j<2; j++) {
			cin >> connections[i][j];
		}
	}
	vector<vector<int>> ans = solve.criticalConnections(n, connections);
	for(int i=0; i<ans.size(); i++) {
		for(int j=0; j<ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}