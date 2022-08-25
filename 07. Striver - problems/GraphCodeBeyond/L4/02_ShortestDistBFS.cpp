#include <bits/stdc++.h>
using namespace std;

vector<int> shortestDist_set(vector<vector<pair<int,int>>>& adjList, int n) {
	set<pair<int,int>> ourset;
	vector<int> dist(n+1, INT_MAX);
	dist[1] = 0; // source node
	ourset.insert(make_pair(1,0));
	while(!ourset.empty()) {
		auto front = ourset.begin(); // Iterator of 1st entry
		ourset.erase(front); // Erase that entry from set
		int node = front->first, w = front->second;
		for(auto it: adjList[node]) {
			int node2=it.first, w2 = it.second;
			if(dist[node2] > (w+w2)) {
				dist[node2] = (w+w2);
				ourset.insert(make_pair(node2, (w+w2)));
			}
		}
	}
	return dist;
}

// Time : O(nlogn + e)
// Space : O(n)
vector<int> shortestDist(vector<vector<pair<int,int>>>& adjList, int n) {
	vector<int> dist(n+1, INT_MAX);
	dist[1] = 0; // source node
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
	minHeap.push(make_pair(1,0));
	while(!minHeap.empty()) {
		int node = minHeap.top().first;
		int w = minHeap.top().second;
		minHeap.pop();
		for(auto it: adjList[node]) {
			int node2 = it.first;
			int w2 = it.second;
			if(dist[node2] > (w+w2)) {
				minHeap.push(make_pair(node2,(w+w2)));
				dist[node2] = (w+w2); // Update min. distance
			}
		}
	}
	return dist;
}

int main() {
	int n, e;
	cin >> n >> e;
	vector<vector<pair<int,int>>> adjList(n+1, vector<pair<int,int>>());
	for(int i=0; i<e; i++) {
		int f, s, w;
		cin >> f >> s >> w;
		adjList[f].push_back(make_pair(s,w));
		adjList[s].push_back(make_pair(f,w));
	}
	cout << "Shortest path using BFS & Priority Queue :- " << endl;
	vector<int> dist1 = shortestDist(adjList, n);
	for(int i=1; i<dist1.size(); i++) {
		cout << i << " - " << dist1[i] << endl;
	}
	cout << "Shortest path using BFS & Set :- " << endl;
	vector<int> dist2 = shortestDist_set(adjList, n);
	for(int i=1; i<dist2.size(); i++) {
		cout << i << " - " << dist2[i] << endl;
	}
	return 0;
}

/*
4 4
1 2 6
3 4 2
4 2 1
1 3 1
*/