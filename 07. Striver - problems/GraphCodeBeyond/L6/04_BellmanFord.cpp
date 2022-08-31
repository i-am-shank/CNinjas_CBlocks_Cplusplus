// Shortest Path
// For -ve weight edges, Dijkstra doesn't work
// Even Bellman-Ford doesn't work, but tells answer

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, e;
	cin >> n >> e;
	vector<vector<int>> edges;
	vector<vector<int>> adjList(n, vector<int>());
	for(int i=0; i<e; i++) {
		int f, s, w;
		cin >> f >> s >> w;
		vector<int> edge;
		edge.push_back(f);
		edge.push_back(s);
		edge.push_back(w);
		edges.push_back(edge);
	}
	vector<int> dist(n,1e9);
	for(int i=0; i<n-1; i++) { // (n-1) iterations
		for(auto it: edges) {
			int n1=it[0], n2=it[1], w=it[2];
			if(dist[n1]+w < dist[n2]) { // condition
				dist[n2] = dist[n1]+w; // transformation
			}
		}
	}
	for(auto it: edges) {
		int n1=it[0], n2=it[1], w=it[2];
		if(dist[n1]+w < dist[n2]) { // condition
			dist[n2] = dist[n1]+w; // transformation
			cout << "Exists a cycle" << endl;
			break;
		}
	}
	for(int i=1; i<=n; i++) {
		cout << dist[i] << " ";
	}
	cout << endl;
	return 0;
}