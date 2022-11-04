#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pp;
#define fi first
#define se second

class Solution {
public:
	bool isPossible(int n, vector<pp>& prerequisites) {
	    vector<vector<int>> adj(n, vector<int>());
	    int e = prerequisites.size();
	    vector<int> inDegree(n, 0);
	    for(int i=0; i<e; i++) {
	    	pp ele = prerequisites[i];
	    	int f=ele.fi, s=ele.se;
	    	adj[f].push_back(s); // f --> s
	    	inDegree[s]++;
	    }
	    queue<int> q;
	    int count = 0; // count of toposort elements
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
	    		inDegree[it]--; // remove edge front --> it
	    		if(inDegree[it] == 0) {
	    			q.push(it);
	    		}
	    	}
	    }
	    return (count == n); // if count == n .. Acyclic graph
	    // i.e. Toposort possible
	}
};

int main() {
	Solution solve;
	int n, e;
	cin >> n >> e;
	vector<pp> prerequisites(e);
	for(int i=0; i<e; i++) {
		int s, f; // f --> s
		cin >> s >> f; // for task s, first do task f
		prerequisites[i] = make_pair(f,s);
	}
	bool ans = solve.isPossible(n, prerequisites);
	cout << (ans == true ? "true" : "false") << "\n";
	return 0;
}