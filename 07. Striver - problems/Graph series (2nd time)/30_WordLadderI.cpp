#include <bits/stdc++.h>
using namespace std;

class Solution {
	bool strDiff(string& s1, string& s2) {
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
	int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        int n = wordList.size();
        int time = 1;
        queue<string> q;
        vector<bool> visited(n, false);
        for(int i=0; i<n; i++) {
        	if(strDiff(startWord, wordList[i])) {
        		visited[i] = true;
        		q.push(wordList[i]);
        		// cout << wordList[i] << " ";
        	}
        }
        // cout << "\n";
        while(!q.empty()) {
        	int s = q.size();
        	time++;
        	for(int i=0; i<s; i++) {
        		string front = q.front();
        		// cout << front << " ";
        		q.pop();
        		if(front == targetWord) {
        			// cout << front << " " << targetWord << "\n";
        			return time;
        		}
        		for(int j=0; j<n; j++) {
        			if(!visited[j] && strDiff(front,wordList[j])) {
    					visited[j] = true;
    					q.push(wordList[j]);
        			}
        		}
        	}
        }
        return 0;
    }
};

int main() {
	Solution solve;
	string startWord, targetWord;
	cin >> startWord >> targetWord;
	int n;
	cin >> n;
	vector<string> wordList(n);
	for(int i=0; i<n; i++) {
		cin >> wordList[i];
	}
	int ans = solve.wordLadderLength(startWord, targetWord, wordList);
	cout << ans << "\n";
	return 0;
}