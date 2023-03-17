#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> d(n);
		for(int i=0; i<n; i++) {
			cin >> d[i];
		}
		int ele = d[0];
		bool isTwo=false;
		vector<int> a(n);
		a[0] = d[0];
		for(int i=1; i<n; i++) {
			int n1=(ele+d[i]), n2=(ele-d[i]);
			// cout<<ele<<" "<<n1<<" "<<n2<<"\n";
			if(n1>=0 && n2>=0 && n1!=n2) {
				// More than 1 possible arrays
				isTwo = true;
				break;
			}
			a[i] = max(n1, n2);
			ele = max(n1, n2);
		}
		if(isTwo == true) {
			cout << -1 << "\n";
		}
		else {
			for(int i=0; i<n; i++) {
				cout << a[i] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}