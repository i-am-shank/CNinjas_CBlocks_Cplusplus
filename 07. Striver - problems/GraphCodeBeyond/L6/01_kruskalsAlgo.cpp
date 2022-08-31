#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int,int>> pp;

class DSU {
private:
	vector<int> parent;
	vector<int> size;

public:
	DSU(int n) {
		for(int i=0; i<=n; i++) {
			parent.push_back(i); // Self-parent
			size.push_back(1); // Self-component
		}
	}

	int findParent(int n) {
		if(n == parent[n]) {
			return n;
		}
		int par = findParent(parent[n]);
		// parent[n] = par; // Trimming height of DSU (not needed here)
		return par;
	}

	void unionBySize(int u, int v) {
		int par_u = findParent(u);
		int par_v = findParent(v);
		if(par_u == par_v) {
			return;
		}
		else if(size[par_u] > size[par_v]) {
			parent[par_v] = par_u;
			size[par_u] += size[par_v];
		}
		else {
			parent[par_u] = par_v;
			size[par_v] += size[par_u];
		}
		return;
	}
};

vector<vector<pair<int,int>>> kruskal(vector<vector<pair<int,int>>>& adjList, int n) {
	vector<pair<int,pair<int,int>>> edges;
	for(int i=1; i<=n; i++) {
		for(auto it: adjList[i]) {
			int n1=i, n2=it.second, w=it.first;
			pp ele;
			ele.first=w, ele.second.first=n1, ele.second.second=n2;
			edges.push_back(ele);
		}
	}
	vector<vector<pair<int,int>>> graph(n+1, vector<pair<int,int>>());
	sort(edges.begin(), edges.end());
	DSU dsu(n);
	for(int i=0; i<edges.size(); i++) {
		pp edge = edges[i];
		int w=edge.first, n1=edge.second.first, n2=edge.second.second;
		int p1=dsu.findParent(n1), p2=dsu.findParent(n2);
		if(p1 != p2) { // Need to connect an edge
			dsu.unionBySize(p1, p2);  //  p1 <---> p2
			graph[p1].push_back(make_pair(w,p2));
			graph[p2].push_back(make_pair(w,p1));
		}
	}
	return graph;
}

int main() {
	int n, e;
	cin >> n >> e;
	vector<vector<pair<int,int>>> adjList(n+1, vector<pair<int,int>>());
	for(int i=0; i<e; i++) {
		int f, s, w;
		cin >> f >> s >> w;
		adjList[f].push_back(make_pair(w,s));
		adjList[s].push_back(make_pair(w,f));
	}
	vector<vector<pair<int,int>>> mst = kruskal(adjList, n);
	for(int i=1; i<mst.size(); i++) {
		cout << i << " - ";
		for(int j=0; j<mst[i].size(); j++) {
			cout << "(" << mst[i][j].first << ",";
			cout << mst[i][j].second << ") , ";
		}
		cout << endl;
	}
	return 0;
}