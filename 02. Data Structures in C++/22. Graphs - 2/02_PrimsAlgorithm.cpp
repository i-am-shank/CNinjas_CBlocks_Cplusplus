#include <bits/stdc++.h>
using namespace std;

// Time : O(n)  ->  Can use Priority Queue (for optimization)
//              ->  Can be optimized till O(logn)
// Space : O(1)
int findMinVertex(int* weight, bool* visited, int n) {
	int minVertex=-1;
	for(int i=0; i<n; i++) {
		if(visited[i] == true) {
			continue;
		}
		if(minVertex==-1 || weight[i]<weight[minVertex]) {
			minVertex = i;
		}
	}
	return minVertex;
}

// Prims Algo. -> finds MST of a connected-weighted graph
// Time : O(n^2)
// Space : O(n)
void prims(int **edges, int n, int e) {
	bool *visited = new bool[n];
	for(int i=0; i<n; i++) {
		visited[i] = false;
	}
	int* parent = new int[n];
	parent[0] = -1; // No parent
	for(int i=0; i<n; i++) {
		parent[i] = i;
	}
	int *weight = new int[n];
	weight[0] = 0; // taken as source
	for(int i=1; i<n; i++) {
		weight[i] = INT_MAX;
	}
	// Iterate
	// Find min. unvisited node (among edges of 0)
	for(int i=0; i<n; i++) {
		int minVertex = findMinVertex(weight, visited, n);
		visited[minVertex] = true;
		// To iterate over only connected vertices
		// -> using Adjacency-list can optimize the following loop
		for(int j=0; j<n; j++) {
			// Among all connections.. Edit weights if required
			if(edges[j][minVertex]!=0 && visited[j]==false) {
				if(weight[j] > edges[minVertex][j]) {
					weight[j] = edges[minVertex][j];
					parent[j] = minVertex;
				}
			} 
		}
	}
	for(int i=1; i<n; i++) { // Printing (f s w) of MST
		int minV = min(i,parent[i]), maxV = max(i,parent[i]);
		cout << minV << " " << maxV << " " << weight[i] << endl;
	}
}

int main() {
	int n, e;
	cin >> n >> e;
	int **edges = new int*[n];
	for(int i=0; i<n; i++) {
		edges[i] = new int[n];
		for(int j=0; j<n; j++) {
			edges[i][j] = 0;
		}
	}
	for(int i=0; i<e; i++) {
		int f, s, weight;
		cin >> f >> s >> weight;
		edges[f][s] = weight;
		edges[s][f] = weight;
	}
	prims(edges, n, e);
	return 0;
}