#include <bits/stdc++.h>
using namespace std;

void printDFSHelp(int** edges, int n, int sv, bool* visited) {
	cout << sv << " ";
	visited[sv] = true;
	for(int i=0; i<n; i++) {
		if(sv == i) {
			continue;
		}
		if(edges[i][sv] == 1) {
			if(visited[i] == true) {
				continue;
			}
			printDFSHelp(edges, n, i, visited);
		}
	}
	return;
}

void printDFS(int** edges, int n) {
	bool *visited = new bool[n];
	for(int i=0; i<n; i++) {
		visited[i] = false;
	}
	for(int i=0; i<n; i++) {
		if(visited[i] == false) {
			printDFSHelp(edges, n, i, visited);
		}
	}
	cout << endl;
	return;
}

void printBFSHelp(int** edges, int n, int sv, bool* visited) {
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

void printBFS(int** edges, int n) {
	bool *visited = new bool[n];
	for(int i=0; i<n; i++) {
		visited[i] = false;
	}
	for(int i=0; i<n; i++) {
		if(visited[i] == false) {
			printBFSHelp(edges, n, i, visited);
		}
	}
	cout << endl;
	return;
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
	cout << "DFS " << endl;
	printDFS(edges, v);
	cout << "BFS " << endl;
	printBFS(edges, v);
	return 0;
}