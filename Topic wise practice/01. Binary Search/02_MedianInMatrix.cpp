#include <bits/stdc++.h>
using namespace std;

int findMedian(vector<vector<int>> &arr, int n, int m){
	// arr is row-wise sorted
	// median  ->  mid-element in a sorted array
	//      (here there is only 1-median .. no. count is odd)
	int s=-1e8 , e=1e8;
	int medianPlace = ((n*m) / 2); // this much elements are smaller
	while(s <= e) { // Just keep trimming search-space
		int mid = s + ((e-s)/2);
		int count = 0;
		for(int i=0; i<n; i++) {
			// As rows are sorted  ->  Binary search possible
			int c = upper_bound(arr[i].begin(), arr[i].end(), mid) - arr[i].begin();
			// c is count of <= elements  w.r.t mid
			count += c;
		}
		if(count > medianPlace) {
			e = mid-1;
		}
		else {
			s = mid+1;
		}
	}
	// Even If mid got to actual median-value.. 
	// count >= mid  ..  will get atleast (medianPlace + 1)
	// e = mid-1 happen  ..  s will now reach to median (to terminate loop)
	// As now .. everytime count >= mid  ..  will be  < medianPlace

	// So, when loop terminates .. in all cases 

	// s will automatically contain median.. when search space becomes -1
	return s;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> arr;
		for(int i=0; i<n; i++) {
			vector<int> row;
			for(int j=0; j<m; j++) {
				int ele;
				cin >> ele;
				row.push_back(ele);
			}
			arr.push_back(row);
		}
		int ans = findMedian(arr, n, m);
		cout << ans << endl;
	}
	return 0;
}