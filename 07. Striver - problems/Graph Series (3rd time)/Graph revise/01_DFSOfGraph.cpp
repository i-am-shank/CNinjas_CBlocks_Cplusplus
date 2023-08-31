#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(vector<vector<int>>& adj, int node, vector<bool>& visited, vector<int>& ans) {
        ans.push_back(node);
        for(auto it: adj[node]) {
            if(!visited[it]) {
                visited[it] = true;
                dfs(adj, it, visited, ans);
            }
        }
        return;
    }

  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int v, vector<vector<int>> adj) {
        vector<bool> visited(v, false);
        vector<int> ans;
        for(int i=0; i<v; i++) {
            if(!visited[i]) {
                visited[i] = true;
                dfs(adj, i, visited, ans);
            }
        }
        return ans;
    }
};

int main() {
    int v;
    cin >> v;
    vector<vector<int>> adj(v, vector<int>());
    for(int i=0; i<v; i++) {
        int m;
        cin >> m;
        for(int j=0; j<m; j++) {
            int ele;
            cin >> ele;
            adj[i].push_back(ele);
        }
    }
    Solution solve;
    vector<int> ans = solve.dfsOfGraph(v, adj);
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}