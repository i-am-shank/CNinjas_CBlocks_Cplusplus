#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int,int>
#define fi first
#define se second
#define mp make_pair

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	unordered_map<int,int> freq;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	vector<int> ans;
	for(int i=0; i<n; i++) {
		if(arr[i] % 3 == 0) {
			int x1=(arr[i] / 3);
			if(freq.find(x1)!=freq.end() && freq[x1]>0) {
				freq[x1]--;
				ans.push_back(x1);
			}
		}
		freq[arr[i]]++;
	}
	int x = ans.size();
	if(x*2 == n) { // valid transformation
		for(int i=0; i<x; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
	else {
		cout << -1 << "\n";
	}
	return 0;
}