#include <bits/stdc++.h>
using namespace std;

#define pp pair<int,int>
#define fi first
#define se second
#define mp make_pair

pp getFloorAndCeil(vector<int> &arr, int n, int x) {
	// Write your code here.
	int i1 = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
	int i2 = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
	// cout<<i1<<" "<<i2<<"\n";
	int floorIdx = -1, ceilIdx=-1;
	
	if(i1 == n) {
		floorIdx = (i1-1);
	}
	else {
		if(arr[i1] == x) {
			floorIdx = i1;
		}
		else {
			if(i1 == 0) {
				floorIdx = -1; // not found
			}
			else {
				floorIdx = (i1-1);
			}			
		}
	}

	if(i2 == n) {
		i2--;
		if(arr[i2] == x) {
			ceilIdx = i2;
		}
		else {
			// nothing >= x exists
			ceilIdx = -1;
		}
	}
	else {
		if(i2 == 0) {
			ceilIdx = i2;
		}
		else {
			if(arr[i2-1] == x) {
				ceilIdx = (i2-1);
			}
			else {
				ceilIdx = i2;
			}
		}
	}

	int floorEle, ceilEle;
	if(floorIdx != -1) {
		floorEle = arr[floorIdx];
	}
	else {
		floorEle = -1;
	}
	if(ceilIdx != -1) {
		ceilEle = arr[ceilIdx];
	}
	else {
		ceilEle = -1;
	}
	pp ans = mp(floorEle, ceilEle);
	return ans;
}

int main() {
	int n, x;
	cin >> n >> x;
	vector<int> arr(n);
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	pp ans = getFloorAndCeil(arr, n, x);
	cout<<ans.fi<<" "<<ans.se<<"\n";
	return 0;
}