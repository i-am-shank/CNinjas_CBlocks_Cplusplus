#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int e = prerequisites.size();
        vector<int> ans;
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> adj(numCourses, vector<int>());
        queue<int> q;
        for(int i=0; i<e; i++) {
        	int f=prerequisites[i][0], s=prerequisites[i][1];
        	adj[s].push_back(f);
        	// s --> f
        	inDegree[f]++;
        }
        for(int i=0; i<numCourses; i++) {
        	if(inDegree[i] == 0) {
        		q.push(i);
        	}
        }
        int cnt = 0;
        while(!q.empty()) {
        	int front = q.front();
        	q.pop();
        	cnt++;
        	ans.push_back(front);
        	for(auto it: adj[front]) {
        		// front --> it
        		inDegree[it]--;
        		if(inDegree[it] == 0) {
        			q.push(it);
        		}
        	}
        }
        if(cnt == numCourses) {
        	// toposort possible
        	return ans;
        }
        else { // impossible
        	vector<int> arr; // empty-array
        	return arr;
        }
    }
};

int main() {
	int numCourses, e;
	cin >> numCourses >> e;
	vector<vector<int>> prerequisites(e, vector<int>(2));
	for(int i=0; i<e; i++) {
		for(int j=0; j<2; j++) {
			cin >> prerequisites[i][j];
		}
	}
	Solution solve;
	vector<int> ans = solve.findOrder(numCourses, prerequisites);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}