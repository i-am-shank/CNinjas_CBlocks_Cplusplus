#include <bits/stdc++.h>
using namespace std;

bool hasPathDFS(int** edges, int n, int x, int y, bool* visited) {
	if(x == y) {
		return true;
	}
	visited[x] = true;
	for(int i=0; i<n; i++) {
		if(i == x) {
			continue;
		}
		if(edges[i][x] == 1) {
			if(visited[i] == true) {
				continue;
			}
			bool smallAns = hasPathDFS(edges, n, i, y, visited);
			if(smallAns == true) {
				return true;
			}
		}
	}
	return false;
}

bool hasPathBFS(int** edges, int n, int x, int y, bool* visited) {
	queue<int> q;
	q.push(x);
	visited[x] = true;
	while(!q.empty()) {
		int front = q.front();
		q.pop();
		if(front == y) {
			return true;
		}
		for(int i=0; i<n; i++) {
			if(i == front) {
				continue;
			}
			if(edges[i][front] == 1) {
				if(visited[i] == true) {
					continue;
				}
				q.push(i);
				visited[i] = true;
			}
		}
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
	int x, y;
	cin >> x >> y;
	bool *visited = new bool[v];
	for(int i=0; i<v; i++) {
		visited[i] = false;
	}
	bool ans = hasPathDFS(edges, v, x, y, visited);
	bool ans2 = hasPathBFS(edges, v, x, y, visited);
	cout << (ans == true ? "True" : "False") << endl;
	cout << (ans2 == true ? "true" : "false") << endl;
	return 0;
}