#include <bits/stdc++.h>
using namespace std;

#define pp pair<int,int>
#define fi first
#define se second
#define mp make_pair

int getMinCores(vector<int> start, vector<int> end) {
	int n = start.size();
	vector<pp> times(n);
	for(int i=0; i<n; i++) {
		times[i] = mp(start[i], end[i]);
	}
	sort(times.begin(), times.end()); // Sorted according to start-times
	int time = 0, maxTime = times[n-1].fi;
	int idx=0, maxCore=0;
	priority_queue<int, vector<int>, greater<int>> pq;
	while(time <= maxTime) {
		time++;
		while(!pq.empty() && pq.top()<time) {
			// cout << time << " " << pq.top() << " - ";
			pq.pop();
		}
		// cout << "\n";
		while(idx<n && times[idx].fi<=time) {
			pq.push(times[idx].se);
			idx++;
		}
		int curr = pq.size();
		// cout << time << " " << curr << "\n";
		maxCore = max(maxCore, curr);
	}
	return maxCore;
}

int main() {
	int n;
	cin >> n;
	vector<int> start(n), end(n);
	for(int i=0; i<n; i++) {
		cin >> start[i];
	}
	for(int i=0; i<n; i++) {
		cin >> end[i];
	}
	int ans = getMinCores(start, end);
	cout << ans << "\n";
	return 0;
}