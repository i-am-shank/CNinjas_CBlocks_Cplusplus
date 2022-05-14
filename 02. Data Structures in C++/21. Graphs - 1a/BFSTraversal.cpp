#include <bits/stdc++.h>
using namespace std;

void printBFS(int** edges, int n, int sv, bool* visited) {
	queue<int> q;
	q.push(sv);
	visited[sv] = true;
	while(!q.empty()) {
		int front = q.front();
		cout << front << " ";
		q.pop();
		for(int i=0; i<n; i++) {
			if(front == i) {
				continue;
			}
			if(edges[front][i] == 1) {
				if(visited[i] == true) {
					continue;
				}
				q.push(i);
				visited[i] = true;
			}
		}
	}
	return;
}

int main() {
	int v, e;  // No. of vertices   ...   No. of edges.
	cin >> v >> e;
	int** edges = new int*[v];
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
	for(int i=0; i<v; i++) {
		if(visited[i] == false) {
			printBFS(edges, v, i, visited);
		}
	}
	delete []visited;
	for(int i=0; i<v; i++) {
		delete []edges[i];
	}
	delete []edges;
	return 0;
}