#include <iostream>
using namespace std;

void printDFS(int** edges, int n, int sv, bool* visited) {
	cout << sv << " ";
	visited[sv] = true;
	for(int i=0; i<n; i++) {
		if(sv == i) {  // Avoid recursion call on same node .. avoid infinite loop
			continue;
		}
		if(edges[sv][i] == 1) {  // If edge exist, then only call recursion
			if(visited[i]) {  // Must avoid this condition .. whole graph will never be traversed
				continue;
			}
			printDFS(edges, n, i, visited);
		}
	}
	return;
}

int main() {
	int n;  // No. of vertices
	cin >> n;
	int e;  // No. of edges
	cin >> e;
	int **edges = new int*[n];
	for(int i=0; i<n; i++) {
		edges[i] = new int[n];
		for(int j=0; j<n; j++) {
			edges[i][j] = 0;
		}
	}
	// Take input of e edges
	for(int i=0; i<e; i++) {
		int f, s;
		cin >> f >> s;
		edges[f][s] = 1;
		edges[s][f] = 1;
	}
	bool *visited = new bool[n];
	for(int i=0; i<n; i++) {
		visited[i] = false;
	}
	printDFS(edges, n, 0, visited);  // DFS - Depth First Search
	cout << endl;
	for(int i=0; i<n; i++) {
		delete []edges[i];
	}
	delete []edges;
	delete []visited;
	return 0;
}