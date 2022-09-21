#include <bits/stdc++.h>
using namespace std;

class segTree{
	vector<int> seg, lazy;

	void buildTree(vector<int>& arr, int low, int high, int idx) {
		if(low == high) {
			seg[idx] = arr[low];
			return;
		}
		int mid = low + ((high-low)>>1);
		buildTree(arr, low, mid, (2*idx)+1);
		buildTree(arr, mid+1, high, (2*idx)+2);
		seg[idx] = (seg[(2*idx)+1] + seg[(2*idx)+2]);
		return;
	}

public:
	segTree(int n, vector<int>& arr) {
		seg.resize(4*n);
		lazy.resize(4*n);
		buildTree(arr, 0, n-1, 0);
		for(int i=0; i<(4*n); i++) {
			cout << seg[i] << " ";
		}
		cout << "\n";
	}

	void update(int low, int high, int l, int r, int idx, int val) {
		// First process updates .. & lazy propagation
		if(lazy[idx] != 0) {
			seg[idx] += ((high-low+1)*(lazy[idx]));
			if(low != high) {
				// Lazy propagate
				lazy[(2*idx)+1] += lazy[idx];
				lazy[(2*idx)+2] += lazy[idx];
			}
			lazy[idx] = 0; // Lazy propagation done.. dispose this
		}
		if(l>high || r<low) {
			return; // No overlap
		}
		else if(l<=low && high<=r) {
			// Complete overlap
			seg[idx] += (high-low+1)*val;
			if(low != high) {
				lazy[(2*idx)+1] += val;
				lazy[(2*idx)+2] += val;
			}
			return;
		}
		else {
			// Partial overlap
			int mid = low + ((high-low)>>1);
			update(low, mid, l, r, (2*idx)+1, val);
			update(mid+1, high, l, r, (2*idx)+2, val);
			seg[idx] = (seg[(2*idx)+1] + seg[(2*idx)+2]);
			return;
		}
	}

	int query(int low, int high, int l, int r, int idx) {
		// First process previous updates.. from lazy
		if(lazy[idx] != 0) {
			seg[idx] += ((high-low+1)*lazy[idx]);
			if(low != high) {
				lazy[(2*idx)+1] += lazy[idx];
				lazy[(2*idx)+2] += lazy[idx];
			}
			lazy[idx] = 0; // Dispose this value
		}
		if(l>high || r<low) {
			// No overlap
			return 0;
		}
		else if(l<=low && high<=r) {
			return seg[idx];
		}
		else {
			// Partial overlap
			int mid = low + ((high-low)>>1);
			int leftAns = query(low, mid, l, r, (2*idx)+1);
			int rightAns = query(mid+1, high, l, r, (2*idx)+2);
			return (leftAns+rightAns);
		}
	}
};

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	segTree seg(n, arr);
	int q;
	cin >> q;
	while(q--) {
		int type, l, r;
		cin >> type >> l >> r;
		if(type == 1) {
			int ans = seg.query(0, 4, l, r, 0);
			cout << ans << "\n";
		}
		else {
			int val;
			cin >> val;
			seg.update(0, 4, l, r, 0, val);
		}
	}
	return 0;
}