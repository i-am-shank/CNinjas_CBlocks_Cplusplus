#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> repeatedNumber(const vector<int> &A) {
	vector<int> ans;
	ll n = A.size(), s=0, sq=0, x, y;
	s = ((n*(n+1)) / 2);
	sq = (((n)*(n+1)*((2*n)+1)) / 6);
	for(int i=0; i<n; i++) {
		s -= A[i];
		sq -= (A[i]*A[i]);
	}
	x = (s + (sq/s)) / 2;
	y = x - s;
	ans.push_back(y);
	ans.push_back(x);
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
	vector<int> ans = repeatedNumber(A);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}