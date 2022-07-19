#include <bits/stdc++.h>
using namespace std;

void DFS(int **edges, int v, int i, bool* visited) {
	visited[i] = true;
	for(int j=0; j<v; j++) {
		if(edges[i][j] == 1) {
			if(i==j || visited[j]==true) {
				continue;
			}
			DFS(edges, v, j, visited);
		}
	}
	return;
}

int count(int **edges, int v) {
	bool *visited = new bool[v];
	for(int i=0; i<v; i++) {
		visited[i] = false;
	}
	int ans = 0;
	for(int i=0; i<v; i++) {
		if(visited[i] == false) {
			ans++;
			DFS(edges, v, i, visited);
		}
	}
	return ans;
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
	int ans = count(edges, v);
	cout << ans << endl;
	return 0;
}