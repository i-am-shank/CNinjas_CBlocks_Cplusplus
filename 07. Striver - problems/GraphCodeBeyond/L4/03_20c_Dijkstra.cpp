#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void shortestDist(vector<vector<pair<ll,ll>>>& adjList, ll n) {
	vector<ll> dist(n+1, LONG_LONG_MAX);
	vector<bool> visited(n+1, false);
	vector<ll> parent(n+1, 0); // Initially all have 0 as parent
	dist[1] = 0; // source node
	set<pair<ll,ll>> ourset;
	ourset.insert(make_pair(0,1));
	parent[1] = 1; // source node (parent of itself)
	// The node which gets ith node the smallest dist, is parent of ith node
	while(!ourset.empty()) {
		auto front = ourset.begin();
		ourset.erase(front);
		ll node = front->second;
		ll w = front->first;
		if(visited[node] == true) {
			continue; // All neighbours already pushed
		}
		visited[node] = true; // Else mark visited & process
		for(auto it: adjList[node]) {
			ll node2 = it.second, w2 = it.first;
			if(dist[node2] > (ll)(w+w2)  &&  !visited[node2]) {
				dist[node2] = (ll)(w+w2); // Shorter path possible
				parent[node2] = node; // As node2 is reached by node
				ourset.insert(make_pair((ll)(w+w2),node2));
			}
		}
	}
	stack<ll> path;
	ll node = n;
	path.push(node);
	while(parent[node]!=node && parent[node]!=0) {
		node = parent[node];
		path.push(node);
	}
	if(node == 1) {
		while(!path.empty()) {
			cout << path.top() << " ";
			path.pop();
		}
		return;
	}
	else {
		cout << -1;
		return;
	}
}

int main() {
	ll n, m;
	cin >> n >> m;
	vector<vector<pair<ll,ll>>> adjList(n+1, vector<pair<ll,ll>>());
	for(ll i=0; i<m; i++) {
		ll f, s, w;
		cin >> f >> s >> w;
		// Undirected graph
		adjList[f].push_back(make_pair(w,s));
		adjList[s].push_back(make_pair(w,f));
	}
	// Finding shortest path from 1 to n
	// 1  ->  source node
	// Find distance of node (n) from source node
	shortestDist(adjList, n);
	return 0;
}