/*
arr1 : [    ]    ,   arr2 : [    ]
Q. Queries of min. & updates

Query 1 :
1 L1 R1 L2 R2   -->   min((L1,R1) , (L2,R2))
2 1 idx val    -->   update in 1st array, val at idx.
*/


#include <bits/stdc++.h>
using namespace std;

class segmentTree{
	vector<int> seg;
	int size;

	void buildST(int idx, int low, int high, vector<int>& arr) {
		if(low == high) {
			seg[idx] = arr[low];
			return;
		}
		int mid = low + ((high-low)>>1);
		buildST((2*idx)+1, low, mid, arr);
		buildST((2*idx)+2, mid+1, high, arr);
		seg[idx] = min(seg[(2*idx)+1] , seg[(2*idx)+2]);
		return;
	}

public:
	segmentTree(int n, vector<int>& arr) { // n -> size of array, for which seg is created
		seg = vector<int> (4*n, INT_MAX);
		// Initialising with INT_MAX, as min. is needed
		size = (4*n);
		buildST(0, 0, n-1, arr);
		cout << "Print seg-tree :" << endl;
		for(int i=0; i<(4*n); i++) {
			cout << seg[i] << " ";
		}
		cout << endl;
	}

	int minQuery(int idx, int low, int high, int l, int r) {
		// No overlap
		if(l>high || r<low) {
			return INT_MAX;
		}
		// Complete overlap
		else if(l>=low && r<=high) {
			return seg[idx];
		}
		else {
			int mid = low + ((high-low)>>1);
			int leftMin = minQuery((2*idx)+1, low, mid, l, r);
			int rightMin = minQuery((2*idx)+2, mid+1, high, l, r);
			return min(leftMin, rightMin);
		}
	}

	void update(int idx, int low, int high, int i, int val) {
		if(low == high) {
			seg[idx] = val;
			return;
		}
		int mid = low + ((high-low)>>1);
		if(i > mid) {
			update((2*idx)+2, mid+1, high, i, val);
		}
		else {
			update((2*idx)+1, low, mid, i, val);
		}
		seg[idx] = min(seg[(2*idx)+1], seg[(2*idx)+2]);
		return;
	}
};

int main() {
	int n1, n2;
	cin >> n1 >> n2;
	vector<int> arr1(n1), arr2(n2);
	for(int i=0; i<n1; i++) {
		cin >> arr1[i];
	}
	for(int i=0; i<n2; i++) {
		cin >> arr2[i];
	}
	segmentTree st1(n1, arr1);
	segmentTree st2(n2, arr2);
	int q;
	cin >> q; // No. of queries
	while(q--) {
		int type;
		cin >> type;
		if(type == 1) {
			int l1, r1, l2, r2;
			cin >> l1 >> r1 >> l2 >> r2;
			// Get min ((L1,R1) , (L2,R2))
			int min1 = st1.minQuery(0, 0, n1-1, l1, r1);
			int min2 = st2.minQuery(0, 0, n2-1, l2, r2);
			int ans = min(min1, min2);
			cout << "Ans = " << ans << endl;
		}
		else {
			int arrNum, idx, val;
			cin >> arrNum >> idx >> val;
			// Update val at idx, in array arrNum
			if(arrNum == 1) {
				st1.update(0, 0, n1-1, idx, val);
			}
			else {
				st2.update(0, 0, n2-1, idx, val);
			}
		}
	}
	return 0;
}