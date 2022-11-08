#include <bits/stdc++.h>
using namespace std;

class Solution {
	bool strDiff1(string& s1, string& s2) {
		int n1=s1.size(), n2=s2.size();
		if(n1 != n2) {
			return false;
		}
		int diff = 0;
		for(int i=0; i<n1; i++) {
			diff += (s1[i] != s2[i]);
		}
		return (diff == 1);
	}

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        vector<bool> visited(n, false);
        int time = 1; // beginWord.. always there
        queue<string> q;
        for(int i=0; i<n; i++) {
        	if(strDiff1(beginWord, wordList[i])) {
        		visited[i] = true;
        		q.push(wordList[i]);
        	}
        }
        while(!q.empty()) {
        	int s = q.size();
        	time++;
        	for(int i=0; i<s; i++) {
        		string front = q.front();
        		q.pop();
        		if(front == endWord) {
        			return time;
        		}
        		for(int j=0; j<n; j++) {
        			if(!visited[j] && strDiff1(front,wordList[j])) {
        				q.push(wordList[j]);
        				visited[j] = true;
        			}
        		}
        	}
        }
        return 0; // Not gone to endWord any how.
    }
};

int main() {
	Solution solve;
	string beginWord, endWord;
	cin >> beginWord >> endWord;
	int n;
	cin >> n;
	vector<string> wordList(n, "");
	for(int i=0; i<n; i++) {
		cin >> wordList[i];
	}
	int ans = solve.ladderLength(beginWord, endWord, wordList);
	cout << ans << "\n";
	return 0;
}