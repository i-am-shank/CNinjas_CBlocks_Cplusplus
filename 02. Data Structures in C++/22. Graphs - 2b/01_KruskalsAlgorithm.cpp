#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
	int source, dest, weight;
};

static bool sortByWeight(Edge e1, Edge e2) {
	return (e1.weight < e2.weight);
}

// Union find algorithm
// Time : O(v)
// Space : O(v) .. Recursion stack
int findParent(int i, vector<int> parent) {
	if(i == parent[i]) {
		return i;
	}
	return findParent(parent[i], parent);
}

// Kruskal's algorithm
// Time : O(eloge) + O(e*v)
// Space : O(v)
void kruskals(Edge* edges, int v) {
	// First accessing edge with min. weight
	sort(edges, edges+v, sortByWeight);
	vector<int> parent(v);
	vector<Edge> output;
	for(int i=0; i<v; i++) {
		parent[i] = i;
	}
	int k=0, i=0; // traversing in edges & output
	while(i < v-1) {
		int f = edges[k].source;
		int s = edges[k].dest;
		int pf = findParent(f, parent);
		int ps = findParent(s, parent);
		if(pf != ps) {
			// Will not form cycle, if connected
			parent[ps] = pf;
			output.push_back(edges[i]);
			i++;
		}
		k++;
	}
	for(int i=0; i<v-1; i++) {
		int minVertex = min(output[i].source, output[i].dest);
		int maxVertex = max(output[i].source, output[i].dest);
		cout << minVertex << " " << maxVertex << " " << output[i].weight << endl;
	}
}

int main() {
	int v, e;
	cin >> v >> e;
	// As we have to use edges in increasing order of weight
	// Adjacency matrix will not fulfill the need
	Edge* edges = new Edge[e];
	for(int i=0; i<e; i++) {
		int f, s, w;
		cin >> f >> s >> w;
		Edge ele;
		ele.source = f;
		ele.dest = s;
		ele.weight = w;
		edges[i] = ele;
	}
	kruskals(edges, v);
	return 0;
}