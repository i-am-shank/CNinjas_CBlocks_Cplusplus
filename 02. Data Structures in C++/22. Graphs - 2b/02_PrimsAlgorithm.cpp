#include <bits/stdc++.h>
using namespace std;

// Time : O(v)
int findVertex(bool* visited, int *weights, int v) {
	int minVertex = -1;
	for(int i=0; i<v; i++) {
		if(!visited[i] && (minVertex==-1 || weights[i]<weights[minVertex])) {
			minVertex = i;
		}
	}
	return minVertex;
}

// Time : O(v^2)
void prims(int **edges, int v) {
	bool *visited = new bool[v];
	int *weights = new int[v];
	for(int i=0; i<v; i++) {
		visited[i] = false;
		weights[i] = INT_MAX;
	}
	weights[0] = 0; // source
	int *parent = new int[v];
	parent[0] = -1;
	for(int i=0; i<v; i++) {
		int minVertex = findVertex(visited, weights, v);
		visited[minVertex] = true;
		// Explore unvisited neighbour
		for(int j=0; j<v; j++) {
			// Update parent & weight if required
			if(edges[minVertex][j]!=0 && !visited[j]) {
				if(weights[j] > edges[minVertex][j]) {
					weights[j] = edges[minVertex][j];
					parent[j] = minVertex;
				}
			}
		}
	}
	for(int i=1; i<v; i++) {
		int minVertex = min(i, parent[i]);
		int maxVertex = max(i, parent[i]);
		cout << minVertex << " " << maxVertex << " " << weights[i] << endl;
	}
	return;
}

int main() {
	int v, e;
	cin >> v >> e;
	int** edges = new int*[v];
	for(int i=0; i<v; i++) {
		edges[i] = new int[v];
		for(int j=0; j<v; j++) {
			edges[i][j] = 0;
		}
	}
	for(int i=0; i<e; i++) {
		int f, s, w;
		cin >> f >> s >> w;
		edges[f][s] = w;
		edges[s][f] = w;
	}
	prims(edges, v);
	for(int i=0; i<v; i++) {
		delete []edges[i];
	}
	delete []edges;
	return 0;
}