#include <bits/stdc++.h>
using namespace std;

#define pp pair<int,int>
// node, dist
#define fi first
#define se second
#define mp make_pair

// Dijkstra algorithm isn't valid for -ve weights
// As it will force the graph to traverse in an infinite loop
// .. After every traversal --> Cost is decreasing. (-1 -2 ..)

// So, only applicable for graphs with +ve edges.

// Assuming heap-size = H  (worst case)
// Time : O(n * (logH + (n*logH)))
//  ..  O(H) --> size of min-heap (all nodes come atleast once)
//  ..  O(logH + n*logH) --> logH (finding top() of pq)
//                       -->  n   (iterating on edges of pq.top())
//                              ..worst case (edge with every node)
//                       -->   *logH (pushing into heap)
// Time : O(n * (logH * (1+n)))   =    O(n^2 * logH)

// In worst case, every node is pushing every other node into heap
// Heap size (H)  =  O(n^2)  .. approx
// Time : O((n^2) * log(n^2))
//     =  O((n^2) * 2*log(n))
//     =  O(E * 2 * log(n))   =   O(E * log(n))
// If everyone is having edge with everyone
// No. of edges = (n^2) = E

// Space : O(n)

vector<int> dijkstra(int n, vector<vector<pp>>& adj, int src) {
	vector<int> dist(n, INT_MAX);
	priority_queue<pp, vector<pp>, greater<pp>> minHeap;
	minHeap.push(mp(0,src));
	dist[src] = 0;
	while(!minHeap.empty()) {
		pp front = minHeap.top();
		minHeap.pop();
		int d1=front.fi, n1=front.se;
		for(auto it: adj[n1]) {
			int d2=d1+it.fi, n2=it.se;
			if(d2 < dist[n2]) {
				dist[n2] = d2;
				minHeap.push(mp(d2,n2));
			}
		}
	}
	return dist;
}

vector<int> dijkstra_usingSet(int n, vector<vector<pp>>& adj, int src) {
	vector<int> dist(n, INT_MAX);
	set<pp> check;
	check.insert(mp(0,src));
	dist[src] = 0;
	while(!check.empty()) {
		pp top = *check.begin();
		// Erase this entry from set
		check.erase(top);
		int d1=top.fi, n1=top.se;
		for(auto it: adj[n1]) {
			int d2=d1+it.fi, n2=it.se;
			if(d2 < dist[n2]) {
				check.erase(mp(dist[n2],n2));
				// No need of above entry.. got a better path
				// So, erased it (for a better time complexity)
				dist[n2] = d2;
				check.insert(mp(d2,n2));
			}
		}
	}
	return dist;
}

int main() {
	int n, e;
	cin >> n >> e;
	vector<vector<pp>> adj(n, vector<pp>());
	for(int i=0; i<e; i++) {
		int f, s, w;
		cin >> f >> s >> w;
		adj[f].push_back(mp(w,s));
		adj[s].push_back(mp(w,f));
	}
	int src;
	cin >> src;
	vector<int> ans = dijkstra(n, adj, src);
	vector<int> ans2 = dijkstra_usingSet(n, adj, src);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	for(int i=0; i<ans2.size(); i++) {
		cout << ans2[i] << " ";
	}
	cout << "\n";
	return 0;
}