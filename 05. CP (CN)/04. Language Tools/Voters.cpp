#include <bits/stdc++.h>
#include <map>
using namespace std;

int main() {
	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;
	map<int, int> m;
	int total = n1+n2+n3;
	int *arr = new int[total];
	for(int i=0; i<total; i++) {
		cin >> arr[i];
		if(m.find(arr[i]) != m.end()) {
			m[arr[i]]++;
		}
		else {
			m[arr[i]] = 1;
		}
	}
	map<int, int> :: iterator it;
	int count = 0;
	for(it=m.begin(); it!=m.end(); it++) {
		if(it->second >= 2) {
			count ++;
		}
	}
	cout << count << endl;
	for(it=m.begin(); it!=m.end(); it++) {
		if(it->second >= 2) {
			cout << it->first << endl;
		}
	}
	return 0;
}