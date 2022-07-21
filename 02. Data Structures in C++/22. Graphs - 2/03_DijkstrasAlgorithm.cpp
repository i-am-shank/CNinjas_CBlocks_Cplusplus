#include <bits/stdc++.h>
using namespace std;

// Time : O(n)
// Space : O(1)
int findMinVertex(bool* visited, int *distance, int n) {
	int minVertex = -1;
	for(int i=0; i<n; i++) {
		if(visited[i] == true) {
			continue;
		}
		if(minVertex==-1 || distance[i]<distance[minVertex]) {
			minVertex = i;
		}
	}
	return minVertex;
}

// Dijkstras Algorithm  ->  similar to Prim's algorithm
// operate on distance  ..  operate on weights
// Parent not needed    ..  Parent needed (to create MST at end)
// Time : O(n^2)
// Space : O(n)

void dijkstras(int** edges, int n, int e) {
	bool *visited = new bool[n];
	int *distance = new int[n];
	for(int i=0; i<n; i++) {
		visited[i] = false;
	}
	distance[0] = 0;
	for(int i=1; i<n; i++) {
		distance[i] = INT_MAX;
	}
	for(int i=0; i<n; i++) {
		int minVertex = findMinVertex(visited, distance, n);
		visited[minVertex] = true;
		for(int j=0; j<n; j++) {
			if(visited[j]==false && edges[j][minVertex]!=0) {
				if(distance[j] > distance[minVertex]+edges[minVertex][j]) {
					distance[j] = distance[minVertex] + edges[minVertex][j];
				}
			}
		}
	}
	for(int i=0; i<n; i++) {
		cout << i << " " << distance[i] << endl;
	}
	return;
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
		int f, s, w;
		cin >> f >> s >> w;
		edges[f][s] = w;
		edges[s][f] = w;
	}
	dijkstras(edges, n, e);
	return 0;
}