#include <bits/stdc++.h>
using namespace std;

void DFS(int** edges, int v, int i, bool* visited) {
	cout << i << " ";
	visited[i] = true;
	for(int j=0; j<v; j++) {
		if(edges[i][j] == 1) {
			if(i==j || visited[j]==true) {
				continue;
			}
			DFS(edges, v, j, visited);
		}
	}
	return;
}

void printDFS(int** edges, int v) {
	bool *visited = new bool[v];
	for(int i=0; i<v; i++) {
		visited[i] = false;
	}
	for(int i=0; i<v; i++) {
		if(visited[i] == false) {
			DFS(edges, v, i, visited);
		}
	}
	return;
}

int main() {
	int e, v;
	cin >> v >> e;
	int **edges = new int*[e];
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
	printDFS(edges, v);
	return 0;
}