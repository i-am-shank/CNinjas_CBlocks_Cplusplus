#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

string solve(string s) {
	string ans;
	queue<char> q;
	int *arr = new int[26];
	for(int i=0 ;i<26; i++) {
		arr[i] = 0;
	}
	for(int i=0; i<s.size(); i++) {
		q.push(s[i]);
		arr[s[i]-'a'] ++;
		while(!q.empty()) {
			char front = q.front();
			if(arr[front - 'a'] > 1) {
				q.pop();
			}
			else {
				ans.push_back(front);
				break;
			}
		}
		if(q.empty()) {
			ans.push_back('#');
		}
	}
	return ans;
}

int main() {
	string s;
	cin >> s;
	string ans = solve(s);
	cout << ans << endl;
	return 0;
}