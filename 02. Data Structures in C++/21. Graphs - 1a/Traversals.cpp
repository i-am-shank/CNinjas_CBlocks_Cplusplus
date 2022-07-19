#include <bits/stdc++.h>
using namespace std;

void printBFS(int** edges, int v, int s, bool* visited) {
	queue<int> q;
	q.push(s);
	visited[s] = true;
	while(!q.empty()) {
		int front = q.front();
		q.pop();
		cout << front << " ";
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
	return;
}

void BFS(int** edges, int v) {
	bool* visited = new bool[v];
	for(int i=0; i<v; i++) {
		visited[i] = false;
	}
	for(int i=0; i<v; i++) {
		if(visited[i] == false) {
			printBFS(edges, v, i, visited);
		}
	}
	cout << endl;
	return;
}

void printDFS(int** edges, int v, int s, bool* visited) {
	cout << s << " ";
	visited[s] = true;
	for(int i=0; i<v; i++) {
		if(edges[i][s] == 1) {
			if(i == s) {
				continue;
			}
			if(visited[i] == true) {
				continue;
			}
			printDFS(edges, v, i, visited);
		}
	}
	return;
}

void DFS(int** edges, int v) {
	bool* visited = new bool[v];
	for(int i=0; i<v; i++) {
		visited[i] = false;
	}
	for(int i=0; i<v; i++) {
		if(visited[i] == false) {
			printDFS(edges, v, i, visited);
		}
	}
	cout << endl;
	return;
}

int main() {
	int v, e;  // No. of vertices  ..  edges
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
	cout << "DFS :" << endl;
	DFS(edges, v);
	cout << "BFS :" << endl;
	BFS(edges, v);
	return 0;
}