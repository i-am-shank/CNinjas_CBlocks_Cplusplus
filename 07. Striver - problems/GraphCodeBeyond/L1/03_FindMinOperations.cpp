#include <bits/stdc++.h>
using namespace std;

// using Breadth-First Search algorithm
// Time : O((end-start+1) * n) .. at max. visiting each mid-no.
// Space : O(end-start+1)
int minOperations(int start, int end, vector<int> arr, int n) {
	int num = start;
	queue<int> q;
	q.push(num);
	// Here visited will act as complexity improviser
	// ..Something similar to memoization
	unordered_map<int,bool> visited;
	visited[num] = true;
	int count = 0;
	bool found = false;
	while(!q.empty() && found==false) {
		count++;
		int s = q.size();
		// Traversing whole level in 1-step
		for(int i=0; i<s; i++) {
			int front = q.front();
			q.pop();
			if(front == end) {
				found = true;
				break;
			}
			for(int i=0; i<n; i++) {
				int prod = (front * arr[i]);
				if((prod <= end)  &&  (visited.find(prod)==visited.end())) {
					q.push(prod);
					visited[prod] = true;
				}
			}
			// All children are pushed
		}
	}
	count--; // As at start only.. count was 1
	return count;
}

int main() {
	int start, end;
	cin >> start >> end;
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	int ans = minOperations(start, end, arr, n);
	cout << ans << endl;
	return 0;
}