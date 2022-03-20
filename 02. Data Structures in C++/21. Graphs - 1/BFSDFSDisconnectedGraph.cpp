#include <bits/stdc++.h>
#include <queue>
using namespace std;

void printBFS(int **edges, int n, int sv, bool *visited) {
	queue<int> q;
	q.push(sv);
	visited[sv] = true;
	while(!q.empty()) {
		int front = q.front();
		q.pop();
		cout << front << " ";
		for(int i=0; i<n; i++) {
			if(front == i) {
				continue;
			}
			if(visited[i]) {
				continue;
			}
			if(edges[front][i] == 1) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
	return;
}

void BFS(int **edges, int n) {
	bool *visited = new bool [n];
	for(int i=0; i<n; i++) {
		visited[i] = false;
	}
	for(int i=0; i<n; i++) {
		if(visited[i] == false) {
			printBFS(edges, n, i, visited);
		}
	}
	cout << endl;
	delete []visited;
}

void printDFS(int **edges, int n, int sv, bool *visited) {
	cout << sv << " ";
	visited[sv] = true;
	for(int i=0; i<n; i++) {
		if(edges[sv][i] == 1) {
			if(sv == i) {
				continue;
			}
			if(visited[i] == true) {
				continue;
			}
			printDFS(edges, n, i, visited);
		}
	}
}

void DFS(int **edges, int n) {
	bool *visited = new bool [n];
	for(int i=0; i<n; i++) {
		visited[i] = false;
	}
	for(int i=0; i<n; i++) {
		if(visited[i] == false) {
			printDFS(edges, n, i, visited);
		}
	}
	cout << endl;
	delete []visited;
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
		int f, s;
		cin >> f >> s;
		edges[f][s] = 1;
		edges[s][f] = 1;
	}
	cout << "BFS :" << endl;
	BFS(edges, n);
	cout << "DFS :" << endl;
	DFS(edges, n);
	return 0;
}