#include <bits/stdc++.h>
using namespace std;

#define pp pair<int,int>
#define fi first
#define se second
#define mp make_pair

int* stockSpan(int *price, int size)  {
	int *ans = new int[size];
	stack<pp> stk;
	for(int i=0; i<size; i++) {
		int curr = price[i];
		int count = 0;
		while(!stk.empty() && stk.top().fi<curr) {
			count += stk.top().se;
			stk.pop();
		}
		ans[i] = count+1;
		stk.push(mp(curr,count+1));
	}
	return ans;
}

int main() {
	int size;
	cin >> size;
	int *price = new int[size];
	for(int i=0; i<size; i++) {
		cin >> price[i];
	}
	int *ans = stockSpan(price, size);
	for(int i=0; i<size; i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}