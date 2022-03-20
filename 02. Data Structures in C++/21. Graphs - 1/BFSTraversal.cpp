#include <iostream>
#include <queue>
using namespace std;

void printBFS(int** edges, int n, int sv, bool *visited) {
	queue<int> q;
	q.push(sv);
	while(!q.empty()) {
		int front = q.front();
		cout << front << " ";
		q.pop();
		visited[front] = true;
		for(int i=0; i<n; i++) {
			if(front == i) {  // Not work on same node multiple times.
				continue;
			}
			if(visited[i]) {  // Not push multiple times, an already queue-pushed node
				continue;
			}
			if(edges[front][i] == 1) {  // Traversing Breadth-wise.. putting nodes in queue
				q.push(i);
				visited[i] = true;  // Once gone to queue, marked visited
			}
		}
	}
	return;
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
	// Take input edges
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
	printBFS(edges, n, 0, visited);
	for(int i=0; i<n; i++) {
		delete []edges[i];
	}
	delete []edges;
	delete []visited;
	return 0;
}