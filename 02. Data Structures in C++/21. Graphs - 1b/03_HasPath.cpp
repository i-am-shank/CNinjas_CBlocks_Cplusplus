#include <bits/stdc++.h>
using namespace std;

// Time : O(n^2)
// Space : O(n)  ..  Auxiliary space  ->  visited array
void BFS(int **edges, int v, int v1, bool* visited) {
	queue<int> pendingNodes;
	pendingNodes.push(v1);
	visited[v1] = true;
	while(!pendingNodes.empty()) {
		int front = pendingNodes.front();
		pendingNodes.pop();
		for(int i=0; i<v; i++) {
			if(edges[i][front] == 1) {
				if(i==front || visited[i]==true) {
					continue;
				}
				pendingNodes.push(i);
				visited[i] = true;
			}
		}
	}
	return;
}

bool hasPath(int **edges, int v, int v1, int v2) {
	bool* visited = new bool[v];
	for(int i=0; i<v; i++) {
		visited[i] = false;
	}
	BFS(edges, v, v1, visited); // doing BFS from v1
	return (visited[v2] == true); // If v2 visited (has path)
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
	cout << (ans == true ? "true" : "false") << endl;
	for(int i=0; i<v; i++) {
		delete []edges[i];
	}
	delete []edges;
	return 0;
}