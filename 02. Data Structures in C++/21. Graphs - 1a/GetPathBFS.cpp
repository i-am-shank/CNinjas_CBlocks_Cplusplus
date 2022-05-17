#include <bits/stdc++.h>
using namespace std;

vector<int>* getPathBFS(int** edges, int n, int s, int e, bool* visited) {
	vector<int> parent(n, -1);  // parent[i] Storing .. due to which element, i reached to queue
	queue<int> q;
	q.push(s);
	visited[s] = true;
	bool found = false;
	while(!q.empty()  &&  !found==true) {
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
				visited[i] = true;
				parent[i] = front;
				if(i == e) {
					found = true;
					break;
				}
			}
		}
	}
	if(found == false) {
		return NULL;
	}
	vector<int>* ans = new vector<int> ();
	ans->push_back(e);
	int curr = e;
	while(curr != s) {
		curr = parent[curr];
		ans->push_back(curr);
	}
	return ans;
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
	int start, target;
	cin >> start >> target;
	bool* visited = new bool[v];
	for(int i=0; i<v; i++) {
		visited[i] = false;
	}
	vector<int>* ans = getPathBFS(edges, v, start, target, visited);
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