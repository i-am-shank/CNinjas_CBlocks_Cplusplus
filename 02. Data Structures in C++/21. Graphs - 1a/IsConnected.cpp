#include <bits/stdc++.h>
using namespace std;

void DFSTraversal(int** edges, int n, int sv, bool* visited) {
	visited[sv] = true;
	for(int i=0; i<n; i++) {
		if(edges[i][sv] == 1) {
			if(i == sv) {
				continue;
			}
			if(visited[i] == 1) {
				continue;
			}
			visited[i] = 1;
			DFSTraversal(edges, n, i, visited);
		}
	}
	return;
}

bool isConnected1(int** edges, int n) {
	bool *visited = new bool[n];
	for(int i=0; i<n; i++) {
		visited[i] = false;
	}
	DFSTraversal(edges, n, 0, visited);
	int count = 0;
	for(int i=0; i<n; i++) {
		if(visited[i] == false) {
			count++;
			break;
		}
	}
	if(count == 0) {
		return true;
	}
	return false;
}

void BFSTraversal(int** edges, int n, int sv, bool* visited) {
	queue<int> q;
	q.push(sv);
	visited[sv] = true;
	while(!q.empty()) {
		int front = q.front();
		q.pop();
		for(int i=0; i<n; i++) {
			if(edges[i][front] == 1) {
				if(i == front) {
					continue;
				}
				if(visited[i] == true) {
					continue;
				}
				visited[i] = 1;
				BFSTraversal(edges, n, i, visited);
			}
		}
	}
	return;
}

bool isConnected2(int** edges, int n) {
	bool* visited = new bool[n];
	for(int i=0; i<n; i++) {
		visited[i] = false;
	}
	BFSTraversal(edges, n, 0, visited);
	int count = 0;
	for(int i=0; i<n; i++) {
		if(visited[i] == false) {
			count++;
			break;
		}
	}
	if(count == 0) {
		return true;
	}
	return false;
}

int main() {
	int v, e;
	cin >> v >> e;
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
	bool ans = isConnected1(edges, v);
	cout << (ans == true ? "true" : "false") << endl;
	bool ans2 = isConnected2(edges, v);
	cout << (ans2 == true ? "true" : "false") << endl;
	return 0;
}