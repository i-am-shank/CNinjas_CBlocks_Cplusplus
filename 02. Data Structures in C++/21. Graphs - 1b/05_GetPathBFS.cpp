#include <bits/stdc++.h>
using namespace std;

vector<int> BFS(int **edges, int v, int v1, int v2, bool* visited) {
	queue<int> pendingNodes;
	pendingNodes.push(v1);
	vector<int> ans;
	vector<int> parent(v);
	bool found = false; // Checks whether v2 is found
	while(!pendingNodes.empty() && found==false) {
		int front = pendingNodes.front();
		pendingNodes.pop();
		for(int i=0; i<v; i++) {
			if(edges[i][front] == 1) {
				if(i==front || visited[i]==true) {
					continue;
				}
				pendingNodes.push(i);
				visited[i] = true;
				parent[i] = front;
				if(i == v2) {
					found = true;
					break;
				}
			}
		}
	}
	if(found == true) {
		int curr = v2;
		while(curr != v1) { // Traversing backwards from v2 to v1
			ans.push_back(curr);
			curr = parent[curr]; // With help of parent vector
		}
		ans.push_back(v1);
	}
	return ans;
}

vector<int> pathBFS(int **edges, int v, int v1, int v2) {
	bool *visited = new bool[v];
	for(int i=0; i<v; i++) {
		visited[i] = false;
	}
	return BFS(edges, v, v1, v2, visited);
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
	vector<int> path = pathBFS(edges, v, v1, v2);
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