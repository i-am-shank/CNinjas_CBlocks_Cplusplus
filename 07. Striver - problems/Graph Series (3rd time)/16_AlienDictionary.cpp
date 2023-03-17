#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string findOrder(vector<string>& dict, int n, int k) {
        vector<vector<int>> adj(k, vector<int>());
        vector<int> inDegree(k+1, 0);
        for(int i=1; i<n; i++) {
        	string s1=dict[i-1], s2=dict[i];
        	int n1=s1.size(), n2=s2.size();
        	for(int j=0; j<min(n1,n2); j++) {
        		if(s1[j] != s2[j]) {
        			// s1[j] --> s2[j]
        			// This comes before that
        			adj[(int)(s1[j]-'a')].push_back((int)(s2[j]-'a'));
        			inDegree[(int)(s2[j]-'a')]++;
        			break;
        		}
        	}
        }
        queue<int> q;
        for(int i=0; i<k; i++) {
        	if(inDegree[i] == 0) {
        		q.push(i);
        	}
        }
        string ans = "";
        while(!q.empty()) {
        	int front = q.front();
        	q.pop();
        	// cout << front << " ";
        	ans.push_back((char)('a'+front));
        	for(auto it: adj[front]) {
        		// front --> it
        		inDegree[it]--;
        		if(inDegree[it] == 0) {
        			q.push(it);
        		}
        	}
        }
        return ans;
    }
};

int main() {
	int n, k;
	cin >> n >> k;
	vector<string> dict(n);
	for(int i=0; i<n; i++) {
		cin >> dict[i];
	}
	Solution solve;
	string ans = solve.findOrder(dict, n, k);
	cout << ans << "\n";
	return 0;
}