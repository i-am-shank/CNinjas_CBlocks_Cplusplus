#include <bits/stdc++.h>
using namespace std;

void BFS(int** edges, int s, int v, bool* visited) {
	queue<int> q;
	q.push(s);
	visited[s] = true;
	while(!q.empty()) {
		int front = q.front();
		q.pop();
		for(int i=0; i<v; i++) {
			if(edges[i][front] == 1) {
				if(i == front) {
					continue;
				}
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

bool isConnectedBFS(int** edges, int v) {
	bool* visited = new bool[v];
	for(int i=0; i<v; i++) {
		visited[i] = false;
	}
	BFS(edges, 0, v, visited);
	bool ans = true;
	for(int i=0; i<v; i++) {
		if(visited[i] == false) {
			ans = false;
			break;
		}
	}
	return ans;
}

void DFS(int** edges, int s, int v, bool* visited) {
	visited[s] = true;
	for(int i=0; i<v; i++) {
		if(edges[s][i] == 1) {
			if(s == i) {
				continue;
			}
			if(visited[i] == true) {
				continue;
			}
			DFS(edges, i, v, visited);
		}
	}
	return;
}

bool isConnectedDFS(int** edges, int v) {
	bool* visited = new bool[v];
	for(int i=0; i<v; i++) {
		visited[i] = false;
	}
	DFS(edges, 0, v, visited);
	bool ans = true;
	for(int i=0; i<v; i++) {
		if(visited[i] == false) {
			ans = false;
			break;
		}
	}
	return ans;
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
		int f, s;
		cin >> f >> s;
		edges[f][s] = 1;
		edges[s][f] = 1;
	}
	bool ans = isConnectedDFS(edges, v);  // answer from DFS
	bool ansBFS = isConnectedBFS(edges, v);  // answer from BFS
	cout << (ansBFS == true ? "true" : "false") << endl;
	for(int i=0; i<v; i++) {
		delete []edges[i];
	}
	delete []edges;
	return 0;
}