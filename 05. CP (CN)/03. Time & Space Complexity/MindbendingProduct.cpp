#include <iostream>
#include <vector>
using namespace std;

vector<long long> getProductArray(int arr[], int n) {
	if(n == 1) {
		vector<long long> ans;
		ans.push_back(0);
		return ans;
	}
	vector<long long> ans;
	for(int i=0; i<n; i++) {
		ans.push_back(1);
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<i; j++) {
			ans.at(j) *= arr[i];
		}
		for(int j=i+1; j<n; j++) {
			ans.at(j) *= arr[i];
		}
	}
	return ans;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int *arr = new int[n];
		for(int i=0; i<n; i++) {
			cin >> arr[i];
		}
		vector<long long> ans = getProductArray(arr, n);
		for(int i=0; i<ans.size(); i++) {
			cout << ans.at(i) << " ";
		}
		cout << endl;
		delete []arr;
	}
	return 0;
}