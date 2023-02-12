#include <bits/stdc++.h>
using namespace std;

#define pp pair<int,int>
#define fi first
#define se second
#define mp make_pair

class Solution {
    bool isValid(int x, int y, int n, int m) {
        return (x>=0 && x<n && y>=0 && y<m);
    }

public:
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n=image.size(), m=image[0].size();
        int c=image[sr][sc];
        queue<pp> q;
        q.push(mp(sr,sc));
        vector<vector<bool>> visited(n, vector<bool>(m,false));
        image[sr][sc] = newColor;
        visited[sr][sc] = true;
        while(!q.empty()) {
            pp front = q.front();
            q.pop();
            int x1=front.fi, y1=front.se;
            int dx[4] = {1,-1,0,0};
            int dy[4] = {0,0,1,-1};
            for(int k=0; k<4; k++) {
                int x2=x1+dx[k], y2=y1+dy[k];
                if(isValid(x2,y2,n,m) && image[x2][y2]==c && !visited[x2][y2]) {
                    image[x2][y2] = newColor;
                    q.push(mp(x2,y2));
                    visited[x2][y2] = true;
                }
            }
        }
        return image;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> image(n, vector<int>(m,0));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> image[i][j];
        }
    }
    int sr, sc, newColor;
    cin >> sr >> sc >> newColor;
    Solution solve;
    vector<vector<int>> ans = solve.floodFill(image, sr, sc, newColor);
    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}