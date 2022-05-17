#include <bits/stdc++.h>
using namespace std;

void printBFS(int** edges, int n, int sv, bool* visited) {
	vector<int> v;
	queue<int> q;
	q.push(sv);
	v.push_back(sv);
	visited[sv] = true;
	while(!q.empty()) {
		int front = q.front();
		q.pop();
		for(int i=0; i<n; i++) {
			if(edges[i][front] == 1) {
				if(i == front) {
					continue;
				}
				if(visited[i] == true) {
					continue;
				}
				q.push(i);
				v.push_back(i);
				visited[i] = true;
			}
		}
	}
	sort(v.begin(), v.end());
	for(int i=0; i<v.size(); i++) {
		cout << v[i] << " ";
	}
	return;
}

void printConnected(int** edges, int n) {
	bool* visited = new bool[n];
	for(int i=0; i<n; i++) {
		visited[i] = false;
	}
	for(int i=0; i<n; i++) {
		if(visited[i] == false) {
			printBFS(edges, n, i, visited);
			cout << endl;
		}
	}
	return;
}

int main() {
	int v, e;
	cin >> v >> e;
	int** edges = new int*[v];
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
	printConnected(edges, v);
	return 0;
}