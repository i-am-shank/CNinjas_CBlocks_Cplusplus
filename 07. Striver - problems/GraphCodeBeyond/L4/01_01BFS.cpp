#include <bits/stdc++.h>
using namespace std;

vector<int> shortestDist(vector<vector<pair<int,int>>>& adjList, int n) {
	vector<int> dist(n+1, INT_MAX);
	dist[1] = 0; // 1 -> treating as source (0 distance)
	// Queue can also work, but use Deque for optimization
	deque<pair<int,int>> dq;
	dq.push_front(make_pair(1,0));
	while(!dq.empty()) {
		pair<int,int> front = dq.front();
		dq.pop_front();
		for(auto it: adjList[front.first]) {
			int w = front.second;
			int node=it.first , w2=it.second;
			if(dist[node] > (w+w2)) {
				dist[node] = (w+w2);
				if(w2 == 1) { // Pushing 1-weight edge at last
					dq.push_back(it);
				}
				else { // As to get shortest path first (for less operations)
					dq.push_front(it);
				}
			}
			// Else no need to update deque
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
	// Following vector has shortest distance to all nodes (from node 1)
	vector<int> dist = shortestDist(adjList, n);
	for(int i=1; i<dist.size(); i++) {
		cout << i << " - " << dist[i] << endl;
	}
	return 0;
}