#include <bits/stdc++.h>
using namespace std;

struct Item {
	int value;
	int weight;
};

class Solution {
	typedef pair<double, pair<double,double>> pp;

	static bool sortByQ(pp p1, pp p2) {
		return (p1.first > p2.first);
	}

public:
	double fractionalKnapsack(int w, vector<Item> arr, int n) {
		double ans = 0;
		vector<pp> weights(n);
		for(int i=0; i<n; i++) {
			pp ele;
			// cout << arr[i].value<<" "<<arr[i].weight<<"\n";
			ele.second.first = (double)arr[i].value;
			ele.second.second = (double)arr[i].weight;
			// cout<<ele.second.first<<" "<<ele.second.second<<"\n";
			double q = (double)((double)ele.second.first / (double)ele.second.second);
			ele.first = q;
			weights[i] = ele;
		}
		sort(weights.begin(), weights.end(), sortByQ);
		for(int i=0; i<n && w!=0.0; i++) {
			double fi=weights[i].first;
			double vi=weights[i].second.first, wi=weights[i].second.second;
			// cout << fi << " " << vi << " " << wi << "\n";
			double w1 = ((w>wi) ? wi : w);
			w -= w1;
			// cout << w1 << " "<< fi << "\n";
			ans += (w1 * fi);
		}
		return ans;
	}
};

int main() {
	int w, n;
	cin >> w >> n;
	Solution solve;
	vector<Item> arr(n);
	for(int i=0; i<n; i++) {
		int value, weight;
		cin >> value >> weight;
		arr[i].value = value;
		arr[i].weight = weight;
	}
	double ans = solve.fractionalKnapsack(w, arr, n);
	cout << fixed << setprecision(2) << ans << "\n";
	return 0;
}