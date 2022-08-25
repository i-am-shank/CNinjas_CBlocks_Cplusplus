#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pp;
typedef long long ll;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9 + 7;
        vector<vector<pp>> adjList(n, vector<pp>());
        int m=roads.size();
        for(int i=0; i<m; i++) {
        	int u=roads[i][0], v=roads[i][1], time=roads[i][2];
        	adjList[u].push_back(make_pair(time,v));
        	adjList[v].push_back(make_pair(time,u));
        }
        set<pp> s;
        s.insert(make_pair(0,0)); // 0 dist. from 0
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        bool flag = false;
        vector<ll> countMinPaths(n, 0);
        countMinPaths[0] = 1;
        while(!s.empty()) {
        	auto front = s.begin();
        	int time=front->first, node=front->second;
        	flag = (node == (n-1));
            s.erase(front);
        	for(auto it: adjList[node]) {
        		int time2=it.first, node2=it.second;
        		if(dist[node2] > (time+time2)) {
        			dist[node2] = (time+time2);
        			countMinPaths[node2] = 1;
        			s.insert(make_pair((time+time2), node2));
        		}
        		else if(dist[node2] == (time+time2)) {
        			countMinPaths[node2] += countMinPaths[node]; // 1-more path found
        		}
        	}
        }
        if(flag == true) {
        	// There is a path existing
        	int ans = (countMinPaths[n-1] % mod);
        	return ans;
        }
        else {
        	return 0; // No path
        }
    }
};

int main() {
	Solution solve;
	int n, e;
	cin >> n >> e;
	vector<vector<int>> roads;
	for(int i=0; i<e; i++) {
		int u, v, time;
		cin >> u >> v >> time;
		vector<int> road;
		road.push_back(u);
		road.push_back(v);
		road.push_back(time);
		roads.push_back(road);
	}
	int ans = solve.countPaths(n, roads);
	cout << ans << endl;
	return 0;
}