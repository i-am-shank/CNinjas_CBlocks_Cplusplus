#include <bits/stdc++.h>
using namespace std;

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
		parent[n] = par;
		return par;
	}

	void unionBySize(int u, int v) {
		int par_u = findParent(u), par_v = findParent(v);
		if(par_u == par_v) {
			// No need to change anything
			return;
		}
		else if(size[par_u] < size[par_v]) {
			parent[par_u] = par_v;
			size[par_v] += size[par_u];
		}
		else {
			parent[par_v] = par_u;
			size[par_u] += size[par_v];
		}
		return;
	}
};

int main() {
	int n;
	cin >> n;
	DSU dsu(n);
	vector<pair<int,int>> wasteRoads;
	for(int i=1; i<=n-1; i++) {
		int ai, bi;
		cin >> ai >> bi; // Input roads
		int pa=dsu.findParent(ai), pb=dsu.findParent(bi);
		if(pa == pb) {
			// Waste-road (already connected cities)
			wasteRoads.push_back(make_pair(ai,bi));
		}
		else {
			// Disconnected cities getting connected
			dsu.unionBySize(ai,bi); // Join cities
		}
	}
	// Find minimum days to -- remove & join roads
	// To connect all cities (all having same parent)
	int wastes = wasteRoads.size(), widx=0;
	if(wastes == 0) {
		cout << 0 << endl;
		return 0;
	}
	cout << wastes << endl;
	for(int i=1; i<n && wastes>0; i++) {
		for(int j=i+1; j<=n && wastes>0; j++) {
			int pi = dsu.findParent(i);
			int pj = dsu.findParent(j);
			if(pi != pj) {
				// A disconnected pair found
				dsu.unionBySize(i,j);
				cout << wasteRoads[widx].first << " " << wasteRoads[widx].second << " ";
				cout << i << " " << j << endl;
				widx++;
				wastes--;
			}
		}
	}
	return 0;
}