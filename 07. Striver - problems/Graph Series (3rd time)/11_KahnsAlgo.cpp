#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> topoSort(int n, vector<vector<int>>& adjList) {
		vector<int> inDegree(n, 0);
		queue<int> q;
		for(int i=0; i<n; i++) {
			for(auto it: adjList[i]) {
				// i --> it
				inDegree[it]++;
			}
		}
		for(int i=0; i<n; i++) {
			if(inDegree[i] == 0) {
				q.push(i);
			}
		}
		vector<int> ans;
		while(!q.empty()) {
			int front = q.front();
			q.pop();
			ans.push_back(front);
			for(auto it: adjList[front]) {
				// front --> it
				inDegree[it]--;
				// In-degree becomes 0 means,
				// All before coming elements used before
				// So, now time of current node, for toposort
				if(inDegree[it] == 0) {
					q.push(it);
				}
			}
		}
		return ans;
	}
};

int main() {
	int n;
	cin >> n;
	vector<vector<int>> adjList(n, vector<int>());
	for(int i=0; i<n; i++) {
		int m;
		cin >> m;
		for(int j=0; j<m; j++) {
			int ele;
			cin >> ele;
			adjList[i].push_back(ele);
		}
	}
	Solution solve;
	vector<int> ans = solve.topoSort(n, adjList);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}