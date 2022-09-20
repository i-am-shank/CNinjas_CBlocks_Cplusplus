#include <bits/stdc++.h>
using namespace std;

class segTree {
	vector<int> seg;

	void buildTree(vector<int>& arr, int low, int high, int idx) {
		if(low == high) {
			seg[idx] = arr[low];
			return;
		}
		int mid = low + ((high-low)>>1);
		buildTree(arr, low, mid, (2*idx)+1);
		buildTree(arr, mid+1, high, (2*idx)+2);
		seg[idx] = min(seg[(2*idx)+1], seg[(2*idx)+2]);
		return;
	}

public:
	segTree(int n, vector<int>& arr) {
		seg = vector<int>((4*n)+1);
		buildTree(arr, 0, n-1, 0);
	}

	void update(vector<int>& arr, int low, int high, int i, int val, int idx) {
		if(low == high) {
			arr[i] = val;
			seg[idx] = val;
			return;
		}
		int mid = low + ((high-low)>>1);
		if(i <= mid) {
			// Left segment
			update(arr, low, mid, i, val, (2*idx)+1);
		}
		else {
			update(arr, mid+1, high, i, val, (2*idx)+2);
		}
		seg[idx] = min(seg[(2*idx)+1], seg[(2*idx)+2]);
		return;
	}

	int query(int low, int high, int l, int r, int idx) {
		if(l>high || r<low) {
			// No overlap
			return INT_MAX; // as min. required
		}
		else if(l<=low && high<=r) {
			// Complete overlap
			return seg[idx];
		}
		else {
			int mid = low + ((high-low)>>1);
			int leftAns = query(low, mid, l, r, (2*idx)+1);
			int rightAns = query(mid+1, high, l, r, (2*idx)+2);
			return min(leftAns, rightAns);
		}
	}
};

int main() {
	int n, q;
	cin >> n >> q;
	vector<int> arr(n);
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	segTree seg(n, arr);
	while(q--) {
		char c;
		int a, b;
		cin >> c >> a >> b;
		if(c == 'q') {
			// query
			a--;
			b--; // converted to 0-indexing
			int ans = seg.query(0, n-1, a, b, 0);
			cout << ans << "\n";
		}
		else {
			// update
			a--; // 0-indexing
			seg.update(arr, 0, n-1, a, b, 0);
		}
	}
	return 0;
}