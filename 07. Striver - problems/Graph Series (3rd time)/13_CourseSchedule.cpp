#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        int e = prerequisites.size();
        vector<int> inDegree(numCourses, 0);
        for(int i=0; i<e; i++) {
        	int f=prerequisites[i][0], s=prerequisites[i][1];
        	// s --> f
        	adj[s].push_back(f);
        	inDegree[f]++;
        }
        queue<int> q;
        int cnt = 0; // Count of toposort-elements
        for(int i=0; i<numCourses; i++) {
        	if(inDegree[i] == 0) {
        		q.push(i);
        	}
        }
        while(!q.empty()) {
        	int front = q.front();
        	q.pop();
        	cnt++;
        	for(auto it: adj[front]) {
        		// front --> it
        		inDegree[it]--;
        		if(inDegree[it] == 0) {
        			q.push(it);
        		}
        	}
        }
        // If no-cycle, can finish
        return (cnt == numCourses); // whole toposort done
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
	bool ans = solve.canFinish(numCourses, prerequisites);
	cout << (ans==true ? "true":"false") << "\n";
	return 0;
}