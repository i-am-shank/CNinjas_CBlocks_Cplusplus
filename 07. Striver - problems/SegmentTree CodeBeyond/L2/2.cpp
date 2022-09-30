// sorted array .. target no.
// Find 2 elements of array, whose sum == target no.

#include <bits/stdc++.h>
using namespace std;

pair<int,int> findNums(vector<int>& arr, int n, int targetNum) {
	// sorted
	int start=0, end=n-1;
	pair<int,int> ans = make_pair(-1, -1); // Not found
	while(start < end) {
		int sum = arr[start]+arr[end];
		if(sum == targetNum) {
			ans.first=arr[start];
			ans.second = arr[end];
			return ans;
		}
		else if(sum > targetNum) {
			// Decrease the sum.. to get closer to target
			end--; // A smaller no. is added in next iteration
		}
		else {
			// Increase the sum
			start++;
		}
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	int targetNum;
	cin >> targetNum;
	pair<int,int> nums = findNums(arr, n, targetNum);
	cout << nums.first << " " << nums.second << "\n";
	return 0;
}