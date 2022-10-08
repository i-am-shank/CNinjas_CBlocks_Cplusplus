#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pp;

class Solution {
	static bool sortByStart(pp p1, pp p2) {
		if(p1.first == p2.first) {
			// The one ending first
			return (p1.second < p2.second);
		}
		return (p1.first < p2.first);
	}

public:
	// Time : O(nlogn)
	int maxMeetings(vector<int>& start, vector<int>& end, int n) {
		vector<pp> meetings(n);
		for(int i=0; i<n; i++) {
			meetings[i] = make_pair(start[i], end[i]);
		}
		sort(meetings.begin(), meetings.end(), sortByStart);
		int count = 0;
		int time = 0, prevEnd=-1, prevStart=-1;
		for(int i=0; i<n; i++) {
			int si=meetings[i].first, ei=meetings[i].second;
			if(si > prevEnd) {
				count++; // 1-extra meeting accomodable in schedule
				prevEnd = ei; // New meeting
			}
			else if(ei < prevEnd) {
				prevEnd = ei; // meeting ending first.. priority
			}
			else {
				continue; // Ignore such meetings
				// which have starting >= curr & ending also late.
			}
		}
		return count;
	}
};

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
	Solution solve;
	int ans = solve.maxMeetings(start, end, n);
	cout << ans << "\n";
	return 0;
}