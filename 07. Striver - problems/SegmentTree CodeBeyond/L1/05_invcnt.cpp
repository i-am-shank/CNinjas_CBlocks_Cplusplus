#include <bits/stdc++.h>
using namespace std;

class segmentTree{
	vector<int> seg;

	void buildST(int idx, int low, int high, vector<int>& arr) {
		if(low == high) {
			seg[idx] = arr[low];
			return;
		}
		int mid = low + ((high-low)>>1);
		buildST((2*idx)+1, low, mid, arr);
		buildST((2*idx)+2, mid+1, high, arr);
		seg[idx] = (seg[(2*idx)+1] + seg[(2*idx)+2]);
		return;
	}

public:
	segmentTree(int n, vector<int>& arr) { // n -> size of array, for which seg is created
		seg = vector<int> ((4*n)+1, 0);
		// Initialising with INT_MAX, as min. is needed
		buildST(0, 0, n-1, arr);
		cout << "Print seg-tree :" << endl;
		for(int i=0; i<(4*n); i++) {
			cout << seg[i] << " ";
		}
		cout << endl;
	}

	int query(int idx, int low, int high, int l, int r) {
		// No overlap
		if(l>high || r<low) { // No overlap
			return 0;
		}
		// Complete overlap
		else if(l<=low && r>=high) {
			return seg[idx];
		}
		else {
			int mid = low + ((high-low)>>1);
			int leftMin = query((2*idx)+1, low, mid, l, r);
			int rightMin = query((2*idx)+2, mid+1, high, l, r);
			return (leftMin + rightMin);
		}
	}

	void update(int idx, int low, int high, int i, int val) {
		if(low == high) {
			seg[idx] += val;
			return;
		}
		int mid = low + ((high-low)>>1);
		if(i > mid) {
			update((2*idx)+2, mid+1, high, i, val);
		}
		else {
			update((2*idx)+1, low, mid, i, val);
		}
		seg[idx] = (seg[(2*idx)+1] + seg[(2*idx)+2]);
		return;
	}
};

int countInversion(vector<int>& freq, vector<int>& arr) {
	int n = freq.size();
	segmentTree seg(n, freq);
	int count = 0;
	for(int i=0; i<n; i++) {
		freq[arr[i]]--;
		seg.update(0, 0, n-1, arr[i], -1);
		count += seg.query(0, 0, n-1, 1, arr[i]-1);
	}
	cout << count << endl;
	return count;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int maxEle = INT_MIN;
		vector<int> arr(n);
		for(int i=0; i<n; i++) {
			cin >> arr[i];
			maxEle = max(maxEle, arr[i]);
		}
		vector<int> freq(maxEle+1, 0);
		for(int i=0; i<n; i++) {
			freq[arr[i]]++;
		}
		int count = countInversion(freq, arr);
		cout << count << "\n";
	}
	return 0;
}