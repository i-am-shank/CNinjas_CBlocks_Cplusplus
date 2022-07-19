#include <bits/stdc++.h>
using namespace std;

vector<int> BFS(int **edges, int v, int i, bool* visited) {
	vector<int> component;
	queue<int> pendingNodes;
	pendingNodes.push(i);
	visited[i] = true;
	while(!pendingNodes.empty()) {
		int front = pendingNodes.front();
		component.push_back(front);
		pendingNodes.pop();
		for(int j=0; j<v; j++) {
			if(edges[front][j] == 1) {
				if(front==j || visited[j]==true) {
					continue;
				}
				pendingNodes.push(j);
				visited[j] = true;
			}
		}
	}
	sort(component.begin(), component.end());
	return component;
}

vector<vector<int>> components(int **edges, int v) {
	bool *visited = new bool[v];
	for(int i=0; i<v; i++) {
		visited[i] = false;
	}
	vector<vector<int>> ans;
	for(int i=0; i<v; i++) {
		if(visited[i] == false) {
			vector<int> component = BFS(edges, v, i, visited);
			ans.push_back(component);
		}
	}
	delete []visited;
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
	vector<vector<int>> ans = components(edges, v);
	// As each component is demanded in increasing order
	// DFS will do this for us (by default)
	for(int i=0; i<ans.size(); i++) {
		for(int j=0; j<ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	for(int i=0; i<v; i++) {
		delete []edges[i];
	}
	delete []edges;
	return 0;
}