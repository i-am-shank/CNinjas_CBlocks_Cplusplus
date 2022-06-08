#include <bits/stdc++.h>
using namespace std;

void print(int** edges, int sv, int n, bool* visited) {
	cout << sv << endl;
	visited[sv] = true;
	for(int i=0; i<n; i++) {
		if(edges[i][sv] == 1) {
			if(i == sv) {
				continue;
			}
			if(visited[i] == true) {
				continue;
			}
			print(edges, i, n, visited);
		}
	}
	return;
}

int main() {
	int e, v;  // No. of edges  ..  No. of vertices.
	cin >> e >> v;  // If no. of vertices = n   ...   vertices are 0, 1, 2, ..., n-1 (assume)
	int **edges = new int*[v];
	for(int i=0; i<v; i++) {
		edges[i] = new int[v];
		for(int j=0; j<v; j++) {
			edges[i][j] = 0;
		}
	}
	for(int i=0; i<e; i++) {
		int f, s;
		cin >> f >> s;
		edges[f][s] = 1;
		edges[s][f] = 1;
	}
	bool* visited = new bool[v];
	for(int i=0; i<v; i++) {
		visited[i] = false;
	}
	print(edges, 0, v, visited);
	delete []visited;
	for(int i=0; i<v; i++) {
		delete []edges[i];
	}
	delete []edges;
	return 0;
}