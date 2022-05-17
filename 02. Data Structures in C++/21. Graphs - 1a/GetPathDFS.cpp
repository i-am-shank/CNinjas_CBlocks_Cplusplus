#include <bits/stdc++.h>
using namespace std;

vector<int>* pathDFS(int** edges, int n, int s, int e, bool* visited) {
	if(s == e) {
		vector<int>* ans = new vector<int> ();
		ans->push_back(e);
		return ans;
	}
	visited[s] = true;
	for(int i=0; i<n; i++) {
		if(edges[i][s] == 1) {
			if(i == s) {
				continue;
			}
			if(visited[i] == true) {
				continue;
			}
			vector<int>* smallAns = pathDFS(edges, n, i, e, visited);
			if(smallAns != NULL) {
				smallAns->push_back(s);
				return smallAns;
			}
		}
	}
	return NULL;
}

int main() {
	int v, e;  // No. of vertices   ...   No. of edges
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
	int start, target;
	cin >> start >> target;
	bool* visited = new bool[v];
	for(int i=0; i<v; i++) {
		visited[i] = false;
	}
	vector<int>* ans = pathDFS(edges, v, start, target, visited);
	if(ans != NULL) {
		for(int i=0; i<ans->size(); i++) {
			cout << ans->at(i) << " ";
		}
	}
	cout << endl;
	delete []visited;
	for(int i=0; i<v; i++) {
		delete []edges[i];
	}
	delete []edges;
	return 0;
}