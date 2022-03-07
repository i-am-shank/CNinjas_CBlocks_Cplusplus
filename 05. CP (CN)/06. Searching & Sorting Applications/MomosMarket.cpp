#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;
	int *prices = new int[n];
	ll *priceSum = new ll[n];  // Store sum of momo-prices upto ith shop
	ll sum = 0;
	for(int i=0; i<n; i++) {
		cin >> prices[i];
		sum += prices[i];
		priceSum[i] = sum;
	}
	int q;
	cin >> q;
	for(int i=0; i<q; i++) {
		ll money;
		cin >> money;
		int index = lower_bound(priceSum, priceSum+n, money) - priceSum;
		if(priceSum[index] == money) {
			cout << (index+1) << " " << 0 << endl;
		}
		else {
			cout << index << " " << (money - priceSum[index-1]) << endl;
		}
	}
	delete []prices;
	delete []priceSum;
	return 0;
}