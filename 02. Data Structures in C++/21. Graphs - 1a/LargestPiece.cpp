#include <bits/stdc++.h>
using namespace std;

bool isValid(int x, int y, int n) {
	if((x>=0 && x<n)  &&  (y>=0 && y<n)) {
		return true;
	}
	return false;
}

void DFS(vector<vector<int>> &cake, int n, int x, int y, int xprev, int yprev, int& smallAns, bool** visited) {
	if(isValid(x, y, n) == false) {
		return;
	}
	if(visited[x][y] == true) {
		return;
	}
	visited[x][y] = true;
	if(cake[x][y] == 0) {
		return;
	}
	smallAns++;
	int x_dir[4] = {0, 0, 1, -1};
	int y_dir[4] = {1, -1, 0, 0};
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			int xnew = x + x_dir[i];
			int ynew = y + y_dir[i];
			if(xnew == xprev  &&  ynew == yprev) {
				continue;
			}
			DFS(cake, n, xnew, ynew, x, y, smallAns, visited);
		}
	}
}

int getBiggestPieceSize(vector<vector<int>> &cake, int n) {
    // Write your code here
    int ans = 0;
    bool** visited = new bool*[n];
    for(int i=0; i<n; i++) {
    	visited[i] = new bool[n];
    	for(int j=0; j<n; j++) {
    		visited[i][j] = false;
    	}
    }
    for(int i=0; i<n; i++) {
    	for(int j=0; j<n; j++) {
    		if(visited[i][j] == false) {
    			int smallAns = 0;
    			DFS(cake, n, i, j, -1, -1, smallAns, visited);
    			ans = max(ans, smallAns);
    		}
    	}
    }
    return ans;
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> cake;
	for(int i=0; i<n; i++) {
		vector<int> temp;
		for(int i=0; i<n; i++){
			int ele;
			cin >> ele;
			temp.push_back(ele);
		}
		cake.push_back(temp);
	}
	int ans = getBiggestPieceSize(cake, n);
	cout << ans << endl;
	return 0;
}