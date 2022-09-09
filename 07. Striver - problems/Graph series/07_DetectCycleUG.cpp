#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, e;
	cin >> n >> e;
	vector<vector<int>> adjList(n, vector<int>());
	for(int i=0; i<e; i++) {
		int f, s;
		cin >> f >> s;
		adjList[f].push_back(s);
		adjList[s].push_back(f);
	}
}