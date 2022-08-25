#include <bits/stdc++.h>
using namespace std;

class Solution{
    string topoSort(vector<vector<int>>& adjList, int k) {
        vector<int> inDegree(k, 0);
        for(int i=0; i<k; i++) {
            for(auto it: adjList[i]) {
                inDegree[it]++; // Edge is   i --> it
            }
        }
        queue<int> q;
        vector<int> ans;
        for(int i=0; i<k; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }
        int count = 0;
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            count++;
            ans.push_back(front);
            for(auto it: adjList[front]) {
                inDegree[it]--;
                if(inDegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        string ansStr = "";
        if(count != k) { // TopoSort not possible
            return ansStr;
        }
        for(int i=0; i<ans.size(); i++) {
            ansStr += (ans[i]+'a');
        }
        return ansStr;
    }
    
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<vector<int>> adjList(K, vector<int>());
        for(int i=0; i<N-1; i++) {
            string s1 = dict[i], s2 = dict[i+1];
            int x=0, y=0;
            while(x<s1.size() && y<s2.size()) {
                if(s1[x] != s2[y]) {
                    // s1[x] < s2[y]  ..  s1[x] --> s2[y]
                    int n1 = (s1[x]-'a'), n2=(s2[y]-'a');
                    adjList[n1].push_back(n2);
                    break;
                }
                x++;
                y++;
            }
        }
        string ans = topoSort(adjList, K);
        return ans;
    }
};

int main() {
    int N, K;
    cin >> N >> K;
    string dict[N];
    for (int i = 0; i < N; i++) {
        cin >> dict[i];
    }
    Solution solve;
    string ans = solve.findOrder(dict, N, K);
    cout << ans << endl;
    return 0;
}