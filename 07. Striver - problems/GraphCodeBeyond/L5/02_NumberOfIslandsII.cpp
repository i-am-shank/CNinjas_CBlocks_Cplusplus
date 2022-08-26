#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class DSU {
	vector<int> parent;
	vector<int> size;

public:
	DSU(int n) {
		// Parent of (i)th node is i.
		// Size of each component initially = 1 (only itself)
		parent.push_back(0);
		for(int i=1; i<=n; i++) {
			parent.push_back(i);
			size.push_back(1);
		}
	}

	int findParent(int n) {
		if(n == parent[n]) {
			return n;
		}
		int par = findParent(parent[n]);
		parent[n] = par; // Path-compression
		return par;
	}

	void unionBySize(int u, int v) {
		int par_u = findParent(u);
		int par_v = findParent(v);
		if(par_u == par_v) {
			return;
		}
		else if(size[par_u] < size[par_v]) {
			parent[par_u] = par_v;
			size[par_v] += size[par_u];
		}
		else {
			parent[par_v] = par_u;
			size[par_u] += size[par_v];
		}
		return;
	}
};

class Solution {
	bool isValid(int x, int y, int n, int m) {
		return (x>=0 && x<n && y>=0 && y<m);
	}

public:
    vector<int> numIslands2(int n, int m, vector<Point> &operators) {
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        int num = (n * m);
        DSU dsu(num+1);
        vector<int> countIslands;
        // 0 -> sea  ..  1 -> land
        // Each operation ..  sea  ->  island
        int k=operators.size();
        int count = 0; // Initially (all sea, no land)
        for(auto it: operators) {
        	int xi = it.x, yi = it.y;
        	// In ith operation.. if matrix[xi][yi] was 1
        	//    -> No change in count of island
        	if(matrix[xi][yi] == 1) {
        		countIslands.push_back(count);
        	}
        	else { // A sea is changed to land
        		int c1 = (xi*m) + (yi+1); // +1  -->  1-based indexing
        		int dx[4] = {0,0,1,-1};
        		int dy[4] = {1,-1,0,0};
        		int change=1; // Change in no. of island
        		for(int a=0; a<4; a++) {
        			int xnew=(xi+dx[a]), ynew=(yi+dy[a]);
        			if(isValid(xnew,ynew,n,m)) {
        				if(matrix[xnew][ynew] == 1) {
        					int c2=(xnew*m) + (ynew+1);
        					int p1 = dsu.findParent(c1);
        					int p2 = dsu.findParent(c2);
        					if(p1 != p2) {
        						// Do union  -->  connect island
        						change--;
        						dsu.unionBySize(c1, c2);
        					}
        				}
        			}
        		}
        		count += change;
        		countIslands.push_back(count);
        		matrix[xi][yi] = 1; // Change to land
        	}
        }
        return countIslands;
    }
};

int main() {
	Solution solve;
	int n, m, k;
	cin >> n >> m >> k;
	vector<Point> operators(k);
	for(int i=0; i<k; i++) {
		int xi, yi;
		cin >> xi >> yi;
		Point p(xi, yi);
		operators[i] = p;
	}
	vector<int> ans = solve.numIslands2(n, m, operators);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}