#include <bits/stdc++.h>
using namespace std;

#define pp pair<double,int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

class Solution {
public:
    // Dijkstra algo.
    // Using priority_queue
    // Time : O(E * log(V))
    //     .. E --> no. of edges
    //     .. V --> no. of vertices
    double maxProbability_pq(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        int e = succProb.size();
        vector<vector<pp>> adj(n, vector<pp>());
        for(int i=0; i<e; i++) {
            int n1=edges[i][0], n2=edges[i][1];
            double p=succProb[i];
            // n1 --p-- n2
            adj[n1].pb(mp(p,n2));
            adj[n2].pb(mp(p,n1));
        }
        vector<double> dist(n,0);
        // Have to find max. probability..
        //    (so initialized with 0, can't be smaller)
        // set<pp> st;
        dist[start] = 1.0; // starting point
        // st.insert(mp(1,start));
        priority_queue<pp> maxHeap;
        maxHeap.push(mp(1.0,start));
        while(!maxHeap.empty()) {
            // pp front = *(st.begin());
            pp front = maxHeap.top();
            // st.erase(st.begin());
            maxHeap.pop();
            double p1=front.fi;
            int n1=front.se;
                    if(n1 == end) {
                        return p1;
                    }
            for(auto it: adj[n1]) {
                double p2=(it.fi * p1);
                int n2=it.se;
                if(p2 > dist[n2]) {
                    // if(dist[n2] != 0) {
                    //  // There is a pair in set with prob. > 0
                    //  // Erase that
                    //  auto it = st.find(mp(dist[n2],n2));
                    //  st.erase(it);
                    // }
                    // keep maximizing
                    dist[n2] = p2;
                    // st.insert(mp(p2,n2));
                    maxHeap.push(mp(p2,n2));
                }
            }
        }
        return dist[end];
    }

    // Using set
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        int e = succProb.size();
        vector<vector<pp>> adj(n, vector<pp>());
        for(int i=0; i<e; i++) {
            int n1=edges[i][0], n2=edges[i][1];
            double p=succProb[i];
            // n1 --p-- n2
            adj[n1].pb(mp(p,n2));
            adj[n2].pb(mp(p,n1));
        }
        vector<double> dist(n,0);
        // Have to find max. probability..
        //    (so initialized with 0, can't be smaller)
        set<pp> st;
        // stores members in descending order
        dist[start] = 1.0; // starting point
        st.insert(mp(1,start));
        while(!st.empty()) {
            pp front = *(st.rbegin());
            st.erase(front);
            double p1=front.fi;
            int n1=front.se;
            if(n1 == end) {
                return p1;
            }
            for(auto it: adj[n1]) {
                double p2=(it.fi * p1);
                int n2=it.se;
                if(p2 > dist[n2]) {
                    if(dist[n2] != 0) {
                        // There is a pair in set with prob. > 0
                        // Erase that
                        st.erase(mp(dist[n2],n2));
                    }
                    // keep maximizing
                    dist[n2] = p2;
                    st.insert(mp(p2,n2));
                }
            }
        }
        return dist[end];
    }
};

int main() {
	int n, e, start, end;
	cin >> n >> e >> start >> end;
	vector<vector<int>> edges(e, vector<int>(2));
	for(int i=0; i<e; i++) {
		for(int j=0; j<2; j++) {
			cin >> edges[i][j];
		}
	}
	vector<double> succProb(e);
	for(int i=0; i<e; i++) {
		cin >> succProb[i];
	}
	Solution solve;
	double ans = solve.maxProbability(n, edges, succProb, start, end);
	cout << fixed << setprecision(5) << ans << "\n";
	return 0;
}