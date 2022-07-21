#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
	int source;
	int dest;
	int weight;
};

static bool sortByWeight(Edge e1, Edge e2) {
	return (e1.weight < e2.weight);
}

int findParent(int v, int *parent) {
	if(parent[v] == v) {
		return v;
	}
	return findParent(parent[v], parent);
}

// Time : O(ElogE + E*n)  ..  E -> n^2
// O(E*n) can be improved  ->  Union by Rank & Path compression
// Space : O
void kruskals(Edge *input, int n, int E) {
	sort(input, input+E, sortByWeight);
	Edge *output = new Edge[n-1];
	int *parent = new int[n];
	for(int i=0; i<n; i++) {
		parent[i] = i;
	}
	int count=0, i=0;
	while(count != n-1) {
		Edge currentEdge = input[i];
		// check if we can add the currentEdge in MST or not
		int sourceParent = findParent(currentEdge.source, parent);
		int destParent = findParent(currentEdge.dest, parent);
		if(sourceParent != destParent) {
			output[count] = currentEdge;
			count++;
			parent[sourceParent] = destParent;
		}
		i++;
	}
	for(int i=0; i<n-1; i++) {
		int minVertex = min(output[i].source, output[i].dest);
		int maxVertex = max(output[i].source, output[i].dest);
		cout << minVertex <<" "<< maxVertex <<" "<< output[i].weight << endl;
	}
	return;
}

int main() {
	int n, E;
	cin >> n >> E;
	Edge *input = new Edge[E];
	for(int i=0; i<E; i++) {
		int s, d, w;
		cin >> s >> d >> w;
		input[i].source = s;
		input[i].dest = d;
		input[i].weight = w;
	}
	kruskals(input, n, E);
}