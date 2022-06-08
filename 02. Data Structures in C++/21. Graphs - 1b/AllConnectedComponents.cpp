#include <bits/stdc++.h>
using namespace std;

vector<int> BFS(int** edges, int v, int s, bool* visited) {
	queue<int> q;
	vector<int> ans;
	q.push(s);
	visited[s] = true;
	while(!q.empty()) {
		int front = q.front();
		ans.push_back(front);
		q.pop();
		for(int i=0; i<v; i++) {
			if(edges[i][front] == 1) {
				if(i == front) {
					continue;
				}
				if(visited[i] == true) {
					continue;
				}
				q.push(i);
				visited[i] = true;
			}
		}
	}
	return ans;
}

vector<vector<int>> allComponents(int** edges, int v) {
	vector<vector<int>> ans;
	bool* visited = new bool[v];
	for(int i=0; i<v; i++) {
		visited[i] = false;
	}
	for(int i=0; i<v; i++) {
		if(visited[i] == false) {
			vector<int> smallAns = BFS(edges, v, i, visited);
			ans.push_back(smallAns);
		}
	}
	delete []visited;
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
	vector<vector<int>> ans = allComponents(edges, v);
	for(int i=0; i<ans.size(); i++) {
		vector<int> temp = ans[i];
		sort(temp.begin(), temp.end());
		for(int j=0; j<temp.size(); j++) {
			cout << temp[j] << " ";
		}
		cout << endl;
	}
	for(int i=0; i<v; i++) {
		delete []edges[i];
	}
	delete []edges;
	return 0;
}