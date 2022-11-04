#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) {
        vector<vector<int>> adj(n, vector<int>());
        vector<int> inDegree(n, 0);
        int count = 0;
        vector<int> topo;
        queue<int> q;
        for(int i=0; i<m; i++) {
        	vector<int> v = prerequisites[i];
        	int f=v[0], s=v[1];
        	adj[f].push_back(s);
        	inDegree[s]++; // f --> s
        }
        for(int i=0; i<n; i++) {
        	if(inDegree[i] == 0) {
        		q.push(i);
        	}
        }
        while(!q.empty()) {
        	int front = q.front();
        	q.pop();
        	topo.push_back(front);
        	count++;
        	for(auto it: adj[front]) {
        		inDegree[it]--; // front --> it
        		if(inDegree[it] == 0) {
        			q.push(it);
        		}
        	}
        }
        if(count == n) {
        	reverse(topo.begin(), topo.end());
        	return topo;
        }
        else {
        	vector<int> emptyVect;
        	return emptyVect;
        }
    }
};

int main() {
	Solution solve;
	int n, m;
	cin >> n >> m;
	vector<vector<int>> prerequisites(m, vector<int>());
	for(int i=0; i<m; i++) {
		int s, f;
		cin >> s >> f;
		vector<int> v;
		v.push_back(f);
		v.push_back(s);
		prerequisites[i] = v;
	}
	vector<int> ans = solve.findOrder(n, m, prerequisites);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}