#include <bits/stdc++.h>
using namespace std;

void reverseStack(stack<int> &input, stack<int> &extra) {
	if(input.empty()) {
		// No need to reverse
		return;
	}
    int save = input.top();
    input.pop();
    reverseStack(input, extra);
    // input is reversed.. by recursion
    while(!input.empty()) {
    	extra.push(input.top());
    	input.pop();
    }
    input.push(save);
    while(!extra.empty()) {
    	input.push(extra.top());
    	extra.pop();
    }
    return;
}

int main() {
	stack<int> input, extra;
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		int ele;
		cin >> ele;
		input.push(ele);
	}
	reverseStack(input, extra);
	while(!input.empty()) {
		cout << input.top() << " ";
		input.pop();
	}
	cout << "\n";
	return 0;
}