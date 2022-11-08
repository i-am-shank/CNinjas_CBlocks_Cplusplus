#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string findOrder(vector<string>& dict, int n, int k) {
        vector<vector<int>> adj(k+1, vector<int>());
        for(int i=0; i<n-1; i++) {
        	string word1=dict[i], word2=dict[i+1];
        	int j=0, k=0, n1=word1.size(), n2=word2.size();
        	while(j<n1 && k<n2) {
        		if(word1[j] != word2[k]) {
        			char c1=word1[j], c2=word2[k];
        			// c1 --> c2  (directed edge)
        			// c1 comes before c2 in alien dictionary
        			adj[(int)(c1-'a')].push_back((int)(c2-'a'));
                    break;
        		}
        		else {
        			j++;
        			k++;
        		}
        	}
        }
        vector<int> inDegree(k, 0);
        for(int i=0; i<k; i++) {
        	for(auto it: adj[i]) {
        		// i --> it
        		inDegree[it]++;
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
        	ans += (char)('a'+front);
        	for(auto it: adj[front]) {
        		inDegree[it]--; // remove edge front --> it
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
	vector<string> dict(n, "");
	for(int i=0; i<n; i++) {
		cin >> dict[i];
	}
	Solution solve;
	string ans = solve.findOrder(dict, n, k);
	cout << ans << "\n";
	return 0;
}