#include <bits/stdc++.h>
using namespace std;

int count(int s, int mid, int e, vector<int> &A) {
	if(s >= e) {
		return 0;
	}
	int ans = 0;
	int temp[e-s+1];
	int i=s, j=mid+1, k=0;
	while(i<=mid && j<=e) {
		if(A[i] <= A[j]) {
			temp[k++] = A[i++];
		}
		else {
			temp[k++] = A[j++];
			ans += (mid-i+1);
		}
	}
	while(i<=mid) {
		temp[k++] = A[i++];
	}
	while(j <= e) {
		temp[k++] = A[j++];
	}
	for(int i=0; i<k; i++) {
		A[s+i] = temp[i];
	}
	return ans;
}

int countHelp(int s, int e, vector<int> &A) {
	if(s >= e) {
		return 0;
	}
	int mid = ((e+s)/2);
	int smallAns1 = countHelp(s, mid, A);
	int smallAns2 = countHelp(mid+1, e, A);
	int smallAns3 = count(s, mid, e, A);
	return (smallAns1 + smallAns2 + smallAns3);
}

int countInversions(vector<int> &A) {
	int n = A.size();
	int ans = countHelp(0, n-1, A);
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<int> A;
	for(int i=0; i<n; i++) {
		int ele;
		cin >> ele;
		A.push_back(ele);
	}
	int ans = countInversions(A);
	cout << ans << endl;
	return 0;
}