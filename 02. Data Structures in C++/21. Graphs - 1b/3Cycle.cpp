#include <bits/stdc++.h>
using namespace std;

int cycles(int** edges, int v) {
	int ans = 0;
	for(int i=0; i<v-2; i++) {
		for(int j=i+1; j<v-1; j++) {
			for(int k=j+1; k<v; k++) {
				if(edges[i][j]==1 && edges[j][k]==1 && edges[k][i]==1) {
					ans++;
				}
			}
		}
	}
	return ans;
}

int main() {
	int v, e;
	cin >> v >> e;
	int **edges = new int*[v];
	for(int i=0; i<v; i++) {
		edges[i] = new int[v];
		for(int j=0; j<v; j++) {
			edges[i][j] = 0;
		}
	}
	for(int i=0; i<e; i++) {
		int f, s;
		cin >> f >> s;
		edges[f][s] = 1;
		edges[s][f] = 1;
	}
	int ans = cycles(edges, v);
	cout << ans << endl;
	return 0;
}