#include <bits/stdc++.h>
using namespace std;

#define pp pair<int,int>
#define fi first
#define se second
#define mp make_pair

class Solution {
	vector<int> topoSort(vector<vector<pp>>& adj, int n, vector<int> inDegree) {
		queue<int> q;
		vector<int> ans;
		for(int i=0; i<n; i++) {
			if(inDegree[i] == 0) {
				q.push(i);
			}
		}
		while(!q.empty()) {
			int front = q.front();
			q.pop();
			ans.push_back(front);
			for(auto it: adj[front]) {
				int n1 = it.fi;
				// front --> n1
				inDegree[n1]--;
				if(inDegree[n1] == 0) {
					q.push(n1);
				}
			}
		}
		return ans;
	}

public:
    vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        queue<pp> q;
        vector<int> ans(n, 1e6);
        vector<vector<pp>> adj(n, vector<pp>());
        vector<int> inDegree(n, 0);
        for(int i=0; i<m; i++) {
        	int f=edges[i][0], s=edges[i][1], w=edges[i][2];
        	// f --> s
        	adj[f].push_back(mp(s,w));
        	inDegree[s]++;
        }
        vector<int> arr = topoSort(adj, n, inDegree);
        int asize=arr.size();
        ans[0] = 0;
        for(int i=0; i<asize; i++) {
        	int curr = arr[i];
        	// cout << curr << " -> ";
        	for(auto it: adj[arr[i]]) {
        		int n1=it.fi, w1=it.se;
        		ans[n1] = min(ans[n1], ans[curr]+w1);
        		// cout<<n1<<"-"<<ans[n1]<<" ";
        	}
        	// cout << "\n";
        }
        for(int i=0; i<n; i++) {
        	if(ans[i] == 1e6) {
        		ans[i] = -1; // Not reached
        	}
        }
        return ans;
    }
};

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> edges(m, vector<int>(3));
	for(int i=0; i<m; i++) {
		for(int j=0; j<3; j++) {
			cin >> edges[i][j];
		}
	}
	Solution solve;
	vector<int> ans = solve.shortestPath(n, m, edges);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}