#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pp;
// Sum , max-ele

class segTree{
	vector<pp> seg;

	void buildTree(vector<int>& arr, int low, int high, int idx) {
		if(low == high) {
			seg[idx] = make_pair(arr[low], arr[low]);
			return;
		}
		int mid = low + ((high-low)>>1);
		buildTree(arr, low, mid, (2*idx)+1);
		buildTree(arr, mid+1, high, (2*idx)+2);
		pp ans;
		pp leftAns = seg[(2*idx)+1];
		pp rightAns = seg[(2*idx)+2];
		int maxEle = max(leftAns.second, rightAns.second);
		int maxSum = max(leftAns.second+rightAns.second , max(leftAns.first, rightAns.first));
		ans.first = maxSum, ans.second=maxEle;
		seg[idx] = ans;
		return;
	}

public:
	segTree(int n, vector<int>& arr) {
		seg = vector<pp>((4*n)+1);
		buildTree(arr, 0, n-1, 0);
	}

	void update(vector<int>& arr, int low, int high, int i, int val, int idx) {
		if(low == high) {
			arr[i] = val;
			seg[idx] = make_pair(val, val);
			return;
		}
		int mid = low + ((high-low)>>1);
		if(i > mid) {
			// Right
			update(arr, mid+1, high, i, val, (2*idx)+2);
		}
		else {
			update(arr, low, mid, i, val, (2*idx)+1);
		}
		pp ans;
		pp leftAns = seg[(2*idx)+1];
		pp rightAns = seg[(2*idx)+2];
		int maxEle = max(leftAns.second, rightAns.second);
		int maxSum = max(leftAns.second+rightAns.second , max(leftAns.first, rightAns.first));
		ans.first = maxSum, ans.second=maxEle;
		seg[idx] = ans;
		return;
	}

	pp query(int low, int high, int l, int r, int idx) {
		if(l>high || r<low) {
			// No overlap
			pp ans;
			ans.first=INT_MIN, ans.second=INT_MIN;
			return ans;
		}
		else if(l<=low && high<=r) {
			return seg[idx];
		}
		else {
			int mid = low + ((high-low)>>1);
			pp leftAns = query(low, mid, l, r, (2*idx)+1);
			pp rightAns = query(mid+1, high, l, r, (2*idx)+2);
			pp ans;
			int maxEle = max(leftAns.second, rightAns.second);
			int maxSum = max(leftAns.second+rightAns.second , max(leftAns.first, rightAns.first));
			ans.first = maxSum, ans.second=maxEle;
			return ans;
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
		char c;
		int a, b;
		cin >> c >> a >> b;
		if(c == 'Q') { // query
			a--;
			b--;
			int ans = seg.query(0, n-1, a, b, 0).first;
			cout << ans << "\n";
		}
		else { // update
			a--; // 0-indexing
			seg.update(arr, 0, n-1, a, b, 0);
		}
	}
	return 0;
}