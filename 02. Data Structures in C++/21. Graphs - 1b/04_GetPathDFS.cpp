#include <bits/stdc++.h>
using namespace std;

vector<int> DFS(int **edges, int v, int v1, int v2, bool* visited) {
	vector<int> ans;
	visited[v1] = true;
	if(v1 == v2) {
		ans.push_back(v1);
		return ans;
	}
	for(int i=0; i<v; i++) {
		if(edges[v1][i] == 1) {
			if(v1==i || visited[i]==true) {
				continue;
			}
			vector<int> smallAns = DFS(edges, v, i, v2, visited);
			if(smallAns.size() != 0) {
				smallAns.push_back(v1);
				return smallAns;
			}
		}
	}
	return ans;
}

vector<int> pathDFS(int **edges, int v, int v1, int v2) {
	bool* visited = new bool[v];
	for(int i=0; i<v; i++) {
		visited[i] = false;
	}
	return DFS(edges, v, v1, v2, visited);
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
	vector<int> path = pathDFS(edges, v, v1, v2);
	for(int i=0; i<path.size(); i++) {
		cout << path[i] << " ";
	}
	cout << endl;
	for(int i=0; i<v; i++) {
		delete []edges[i];
	}
	delete []edges;
	return 0;
}