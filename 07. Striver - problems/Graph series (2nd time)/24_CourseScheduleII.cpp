#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        int e = prerequisites.size();
        vector<vector<int>> adj(n, vector<int>());
        vector<int> inDegree(n, 0);
        for(int i=0; i<e; i++) {
        	vector<int> v = prerequisites[i];
        	int f = v[0], s = v[1];
        	adj[f].push_back(s); // f --> s;
        	inDegree[s]++;
        }
        queue<int> q;
        for(int i=0; i<n; i++) {
        	if(inDegree[i] == 0) {
        		q.push(i);
        	}
        }
        vector<int> ans;
        int count = 0;
        while(!q.empty()) {
        	int front = q.front();
        	q.pop();
        	ans.push_back(front);
        	count++;
        	for(auto it: adj[front]) {
        		inDegree[it]--;
        		if(inDegree[it] == 0) {
        			q.push(it);
        		}
        	}
        }
        if(count == n) {
        	reverse(ans.begin(), ans.end());
        	return ans;
        }
        else {
        	vector<int> emptyVector;
        	return emptyVector;
        }
    }
};

int main() {
	int n, e;
	cin >> n >> e;
	vector<vector<int>> prerequisites(e, vector<int>());
	for(int i=0; i<e; i++) {
		vector<int> v;
		int s, f; // f --> s
		cin >> s >> f;
		v.push_back(f);
		v.push_back(s);
		prerequisites[i] = v;
	}
	Solution solve;
	vector<int> ans = solve.findOrder(n, prerequisites);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}