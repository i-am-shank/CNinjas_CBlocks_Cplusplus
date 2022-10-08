#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pp;

class Solution {
	static bool sortByStart(pp t1, pp t2) {
		if(t1.first == t2.first) {
			return (t1.second < t2.second);
		}
		return (t1.first < t2.first);
	}

public:
	// Time : O(nlogn)
	// Space : O(n) .. worst case
	int findPlatform(vector<int>& arr, vector<int>& dep, int n) {
		vector<pp> trains(n);
		for(int i=0; i<n; i++) {
			trains[i] = make_pair(arr[i], dep[i]);
		}
		sort(trains.begin(), trains.end(), sortByStart);
		// Send those trains first.. whose arrival time is before
		// If same arrival time.. sending the one with early-departure time
		priority_queue<int, vector<int>, greater<int>> minHeap;
		int platforms = 0;
		for(int i=0; i<n; i++) {
			int ai = trains[i].first, di = trains[i].second;
			while((!minHeap.empty()) && (minHeap.top()<ai)) {
				// Those trains.. whose departure time is before current's arrival
				// They can leave.. without occupying any additional platforms
				minHeap.pop();
			}
			minHeap.push(di);
			int currSize = minHeap.size();
			platforms = max(platforms, currSize);
		}
		return platforms;
	}
};

int main() {
	int n;
	cin >> n;
	vector<int> arr(n), dep(n);
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	for(int i=0; i<n; i++) {
		cin >> dep[i];
	}
	Solution solve;
	int ans = solve.findPlatform(arr, dep, n);
	cout << ans << "\n";
	return 0;
}