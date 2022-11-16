#include <bits/stdc++.h>
using namespace std;

int lastStoneWeight(vector<int> weights) {
	priority_queue<int> pq;
	int n = weights.size();
	for(int i=0; i<n; i++) {
		pq.push(weights[i]);
	}
	while(!pq.empty() || pq.size()>1) {
		int max = pq.top();
		pq.pop();
		int secMax = pq.top();
		pq.pop();
		if(max == secMax) {
			continue;
		}
		else {
			int diff = max-secMax;
			pq.push(diff);
		}
	}
	if(pq.size() == 1) {
		return pq.top();
	}
	else {
		return 0;
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> weights(n);
	for(int i=0; i<n; i++) {
		cin >> weights[i];
	}
	int ans = lastStoneWeight(weights);
	cout << ans << "\n";
	return 0;
}