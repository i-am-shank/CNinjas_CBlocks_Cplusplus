#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximumProduct(vector<int> &arr, int n) {
	int max_end = 1, min_end = 1, maxV = 0, flag = 0;
	for(int i=0; i<n; i++) {
		if(arr.at(i) > 0) {
			max_end = max_end * arr.at(i);
			min_end = min(1, min_end * arr.at(i));
			flag = 1;
		}
        else if(arr.at(i) == 0) {
            max_end = 1;
			min_end = 1;
		}
		else {
            int temp = max_end;
			max_end = max(1, min_end * arr.at(i));
			min_end = temp * arr.at(i);
		}
		if(maxV < max_end) {
			maxV = max_end;
		}
	}
	if(flag == 0 && maxV == 0) {  // All elements are negative.
		return 0;
	}
	if(maxV == 1) {
		maxV = arr[0];
		for(int i=0 ;i<n ; i++) {
			maxV = max(maxV, arr[i]);
		}
	}
	return maxV;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> input;
		for(int i=0; i<n; i++) {
			int ele;
			cin >> ele;
			input.push_back(ele);
		}
		int ans = maximumProduct(input, n);
		cout << ans << endl;
	}
	return 0;
}