#include <bits/stdc++.h>
using namespace std;

bool hasPathBFS(int** edges, int v, int v1, int v2, bool* visited) {
	queue<int> q;
	q.push(v1);
	visited[v1] = true;
	while(!q.empty()) {
		int front = q.front();
		q.pop();
		if(front == v2) {
			return true;
		}
		for(int i=0; i<v; i++) {
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

bool hasPathDFS(int** edges, int v, int v1, int v2, bool* visited) {
	if(v1 == v2) {
		return true;
	}
	visited[v1] = true;
	for(int i=0; i<v; i++) {
		if(edges[i][v1] == 1) {
			if(i == v1) {
				continue;
			}
			if(visited[i] == true) {
				continue;
			}
			int smallAns = hasPathBFS(edges, v, i, v2, visited);
			if(smallAns == true) {
				return true;
			}
		}
	}
	return false;
}

bool hasPath(int** edges, int v, int v1, int v2) {
	bool *visited = new bool[v];
	for(int i=0; i<v; i++) {
		visited[i] = false;
	}
	bool ansDFS = hasPathDFS(edges, v, v1, v2, visited);
	for(int i=0; i<v; i++) {  // Preparing visited array again for BFS.
		visited[i] = false;
	}
	bool ansBFS = hasPathBFS(edges, v, v1, v2, visited);
	return ansBFS;
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
	int v1, v2;
	cin >> v1 >> v2;
	bool ans = hasPath(edges, v, v1, v2);
	cout << (ans == true ? "Yes" : "No") << endl;
	return 0;
}