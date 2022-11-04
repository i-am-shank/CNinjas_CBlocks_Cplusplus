#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        int e = prerequisites.size();
        vector<vector<int>> adj(n, vector<int>());
        vector<int> inDegree(n, 0);
        for(int i=0; i<e; i++) {
        	vector<int> v = prerequisites[i];
        	int f = v[0], s = v[1];
        	adj[f].push_back(s);
        	inDegree[s]++;
        }
        queue<int> q;
        int count = 0;
        for(int i=0; i<n; i++) {
        	if(inDegree[i] == 0) {
        		q.push(i);
        	}
        }
        while(!q.empty()) {
        	int front = q.front();
        	q.pop();
        	count++;
        	for(auto it: adj[front]) {
        		inDegree[it]--;
        		if(inDegree[it] == 0) {
        			q.push(it);
        		}
        	}
        }
        return (count == n); // Non-cyclic -> can Finish tasks
    }
};

int main() {
	Solution solve;
	int n, e;
	cin >> n >> e;
	vector<vector<int>> prerequisites;
	for(int i=0; i<e; i++) {
		int s, f;
		cin >> s >> f;
		vector<int> ele;
		ele.push_back(f);
		ele.push_back(s);
		prerequisites.push_back(ele);
	}
	bool ans = solve.canFinish(n, prerequisites);
	cout << (ans == true ? "true" : "false") << "\n";
	return 0;
}