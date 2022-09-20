#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<pair<ll,ll>, pair<ll,ll>> pp;
// sum , prefSum, suffSum

class segTree{
	vector<pp> seg;

	void buildTree(vector<ll>& arr, ll low, ll high, ll idx) {
		if(low == high) {
			pp ans;
			ans.first.first = arr[low], ans.first.second = arr[low];
			ans.second.first = arr[low], ans.second.second=arr[low];
			seg[idx] = ans;
			return;
		}
		ll mid = low + ((high-low)>>1);
		buildTree(arr, low, mid, (2*idx)+1);
		buildTree(arr, mid+1, high, (2*idx)+2);
		pp leftAns = seg[(2*idx)+1], rightAns = seg[(2*idx)+2];
		pp ans;
		ll leftMaxSum=leftAns.first.first, leftSum=leftAns.first.second, leftPreSum=leftAns.second.first, leftSufSum=leftAns.second.second;
		ll rightMaxSum=rightAns.first.first, rightSum=rightAns.first.second, rightPreSum=rightAns.second.first, rightSufSum=rightAns.second.second;
		ll maxSum = max((leftSufSum+rightPreSum), max(leftMaxSum, rightMaxSum));
		maxSum = max(maxSum, max(leftPreSum, rightPreSum));
		ll sum = leftSum+rightSum;
		ll preSum = max(leftPreSum, (leftSum+rightPreSum)); 
		ll sufSum = max(rightSufSum, (rightSum+leftSufSum));
		ans.first.first=maxSum, ans.first.second=sum;
		ans.second.first=preSum, ans.second.second=sufSum;
		seg[idx] = ans;
		return;
	}

public:
	segTree(ll n, vector<ll>& arr) {
		seg = vector<pp>((4*n)+1);
		buildTree(arr, 0, n-1, 0);
		/*for(ll i=0; i<(4*n); i++) {
			cout<<seg[i].first.first<<" "<<seg[i].first.second<<" ";
			cout<<seg[i].second.first<<" "<<seg[i].second.second;
			cout << "\n";
		}
		cout << "\n";*/
	}

	pp query(ll low, ll high, ll l, ll r, ll idx) {
		if(l>high || r<low) {
			// No overlap
			pp ans;
			ans.first.first=LONG_LONG_MIN, ans.first.second=LONG_LONG_MIN;
			ans.second.first=LONG_LONG_MIN, ans.second.second=LONG_LONG_MIN;
			return ans;
		}
		else if(l<=low && high<=r) {
			return seg[idx];
		}
		ll mid = low + ((high-low)>>1);
        if(l > mid) {
            return query(mid+1, high, l, r, (2*idx)+2);
        }
        else if(r <= mid) {
            return query(low, mid, l, r, (2*idx)+1);
        }
		pp leftAns = query(low, mid, l, r, (2*idx)+1);
		pp rightAns = query(mid+1, high, l, r, (2*idx)+2);
		pp ans;
		ll leftMaxSum=leftAns.first.first, leftSum=leftAns.first.second, leftPreSum=leftAns.second.first, leftSufSum=leftAns.second.second;
		ll rightMaxSum=rightAns.first.first, rightSum=rightAns.first.second, rightPreSum=rightAns.second.first, rightSufSum=rightAns.second.second;
		ll maxSum = max((leftSufSum+rightPreSum), max(leftMaxSum, rightMaxSum));
		maxSum = max(maxSum, max(leftPreSum, rightPreSum));
		ll sum = leftSum+rightSum;
		ll preSum = max(leftPreSum, (leftSum+rightPreSum)); 
		ll sufSum = max(rightSufSum, (rightSum+leftSufSum));
		ans.first.first=maxSum, ans.first.second=sum;
		ans.second.first=preSum, ans.second.second=sufSum;
		return ans;
	}
};

int main() {
	ll n;
	cin >> n;
	vector<ll> arr(n);
	for(ll i=0; i<n; i++) {
		cin >> arr[i];
	}
	segTree seg(n, arr);
	ll m;
	cin >> m;
	while(m--) {
		ll xi, yi;
		cin >> xi >> yi;
		xi--;
		yi--;
		ll ans = seg.query(0, n-1, xi, yi, 0).first.first;
		cout << ans << "\n";
	}
	return 0;
}