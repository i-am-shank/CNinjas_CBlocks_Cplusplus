#include <bits/stdc++.h>
using namespace std;

vector<int> getPathDFSHelp(int** edges, int v, int v1, int v2, bool* visited) {
	vector<int> ans;
	visited[v1] = true;
	if(v1 == v2) {
		ans.push_back(v1);
		return ans;
	}
	for(int i=0; i<v; i++) {
		if(edges[i][v1] == 1) {
			if(i == v1) {
				continue;
			}
			if(visited[i] == true) {
				continue;
			}
			vector<int> smallAns = getPathDFSHelp(edges, v, i, v2, visited);
			if(!smallAns.empty()) {
				smallAns.push_back(v1);
				return smallAns;
			}
		}
	}
	return ans;
}

vector<int> getPathDFS(int** edges, int v, int v1, int v2) {
	bool* visited = new bool[v];
	for(int i=0; i<v; i++) {
		visited[i] = false;
	}
	vector<int> ans = getPathDFSHelp(edges, v, v1, v2, visited);
	return ans;
}

int main() {
	int v, e;  // No. of vertices  ..  No. of edges
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
	vector<int> ans = getPathDFS(edges, v, v1, v2);
	if(ans.size() != 0) {
		for(int i=0; i<ans.size(); i++) {
			cout << ans[i] << " ";
		}
	}
	return 0;
}