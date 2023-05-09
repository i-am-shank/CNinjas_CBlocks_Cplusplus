#include <bits/stdc++.h>
using namespace std;

#define pp pair<int,int>
#define ppp pair<pp,int>    // for q
// To store .. coordinate , maxDiff.
#define pppp pair<int,pp>   // for pq
// To store .. maxDiff. , coordinate
#define fi first
#define se second
#define mp make_pair

class Solution {
	bool isValid(int x, int y, int m, int n) {
		return (x>=0 && y>=0 && x<m && y<n);
	}

public:
	// Using queue
    int minimumEffortPath_queue(vector<vector<int>>& heights) {
        int m=heights.size(), n=heights[0].size();
        int ans=INT_MAX;
        queue<ppp> q;
        q.push(mp(mp(0,0), 0));
        vector<vector<int>> dist(m, vector<int>(n,INT_MAX));
        dist[0][0] = 0; // As same value is max. & min.
        while(!q.empty()) {
        	ppp front = q.front();
        	int x1=front.fi.fi, y1=front.fi.se;
        	int maxDiff1=front.se;
        	int dx[4] = {0,0,1,-1};
        	int dy[4] = {1,-1,0,0};
        	q.pop();
        	for(int k=0; k<4; k++) {
        		int x2=x1+dx[k], y2=y1+dy[k];
        		if(isValid(x2,y2,m,n)) {
        			int maxDiff2 = max(maxDiff1, abs(heights[x2][y2]-heights[x1][y1]));
        			if(maxDiff2 < dist[x2][y2]) {
        				// Then only insert in queue
        				// And, also update the value
        				dist[x2][y2] = maxDiff2;
        				q.push(mp(mp(x2,y2), maxDiff2));
        			}
        		}
        	}
        }
        // This cell will have the min. effort required
        return dist[m-1][n-1];
    }

    // Using priority_queue
    // Better time-complexity than queue because..
    //   Optimal metrics will be found before,
    //      (which will remove more unnecessary pq-addition)
    int minimumEffortPath(vector<vector<int>>& heights) {
    	int m=heights.size(), n=heights[0].size();
    	vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    	dist[0][0] = 0;
    	priority_queue<pppp, vector<pppp>, greater<pppp>> minHeap;
    	minHeap.push(mp(0, mp(0,0)));
    	while(!minHeap.empty()) {
    		pppp front = minHeap.top();
    		minHeap.pop();
    		int maxDiff1=front.fi;
    		int x1=front.se.fi, y1=front.se.se;
    		int dx[4]={0,0,1,-1};
    		int dy[4]={1,-1,0,0};
    		for(int k=0; k<4; k++) {
    			int x2=x1+dx[k], y2=y1+dy[k];
    			if(isValid(x2,y2,m,n)) {
    				int maxDiff2 = max(maxDiff1, abs(heights[x2][y2]-heights[x1][y1]));
    				if(maxDiff2 < dist[x2][y2]) {
    					dist[x2][y2] = maxDiff2;
    					minHeap.push(mp(maxDiff2, mp(x2,y2)));
    				}
    			}
    		}
    	}
    	return dist[m-1][n-1];
    }
};

int main() {
	int m, n;
	cin >> m >> n;
	vector<vector<int>> heights(m, vector<int>(n));
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cin >> heights[i][j];
		}
	}
	Solution solve;
	int ans = solve.minimumEffortPath(heights);
	cout << ans << "\n";
	return 0;
}