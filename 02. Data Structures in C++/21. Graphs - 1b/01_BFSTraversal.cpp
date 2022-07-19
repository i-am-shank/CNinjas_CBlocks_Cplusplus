// Graph  ->  min-Connected == Tree
// n-vertices  ->  (n-1) edges
// No. of edges  :  O(n) , O(n^2)


#include <bits/stdc++.h>
using namespace std;

void BFS(int **edges, int s, int v, bool* visited) {
	queue<int> pendingNodes;
	pendingNodes.push(s);
	visited[s] = true;
	while(!pendingNodes.empty()) {
		int front = pendingNodes.front();
		cout << front << " ";
		pendingNodes.pop();
		for(int i=0; i<v; i++) {
			if(edges[i][front] == 1) {
				if(i==front  ||  visited[i]) {
					continue;
				}
				pendingNodes.push(i);
				visited[i] = true;
			}
		}
	}
	return;
}

void printBFS(int** edges, int v) {
	bool* visited = new bool[v];
	for(int i=0; i<v; i++) {
		visited[i] = false;
	}
	for(int i=0; i<v; i++) {
		if(visited[i] == false) {
			BFS(edges, i, v, visited);
		}
	}
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
	printBFS(edges, v);
	for(int i=0; i<v; i++) {
		delete []edges[i];
	}
	delete []edges;
	return 0;
}