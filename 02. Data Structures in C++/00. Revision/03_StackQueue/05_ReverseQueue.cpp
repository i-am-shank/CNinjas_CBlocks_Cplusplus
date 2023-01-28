#include <bits/stdc++.h>
using namespace std;

void reverseQueue(queue<int> &input) {
	if(input.empty()) {
		// No need to reverse
		return;
	}
	int save = input.front();
	input.pop();
	reverseQueue(input);
	input.push(save);
	return;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		queue<int> input;
		int n;
		cin >> n;
		for(int i=0; i<n; i++) {
			int ele;
			cin >> ele;
			input.push(ele);
		}
		reverseQueue(input);
		while(!input.empty()) {
			cout << input.front() << " ";
			input.pop();
		}
		cout << "\n";
	}
	return 0;
}