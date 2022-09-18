#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
	// As cost is sum of 2 lengths
	// For min. cost, first take 2 most min. elements
    ll minCost(ll arr[], ll n) {
        priority_queue<ll,vector<ll>,greater<ll>> minHeap;
        for(int i=0; i<n; i++) {
        	minHeap.push(arr[i]);
        }
        ll cost = 0;
        // In each step, popping 2 & pushing 1 element
        while(minHeap.size() > 1) {
        	ll min1=minHeap.top();
        	minHeap.pop();
        	ll min2=minHeap.top();
        	minHeap.pop();
        	ll sum = (min1+min2);
        	cost += sum;
        	minHeap.push(sum);
        }
        return cost;
    }
};

int main() {
	ll n;
	cin >> n;
	ll arr[100000];
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	Solution solve;
	ll ans = solve.minCost(arr, n);
	cout << ans << endl;
	return 0;
}