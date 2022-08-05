#include <bits/stdc++.h>
using namespace std;



int main() {
	int n;
	cin >> n;
	vector<int>* edges = new vector<int>(n);
	int m;
	cin >> m;
	for(int i=0; i<m; i++) {
		int f, s;
		cin >> f >> s;
		edges[f-1].push_back(s-1);
		edges[s-1].push_back(f-1);
	}
	unordered_set<unordered_set<int>*>* components = getComponents(edges, n);
	// Print components
}