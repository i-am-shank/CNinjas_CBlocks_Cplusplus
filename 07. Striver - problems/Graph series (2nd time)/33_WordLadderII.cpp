#include <bits/stdc++.h>
using namespace std;

class Solution {
	bool nextWord(string& s1, string& s2) {
		int diff = 0, n=s1.size();
		for(int i=0; i<n; i++) {
			if(s1[i] != s2[i]) {
				diff++;
			}
		}
		if(diff == 1) {
			return true;
		}
		return false;
	}

public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        vector<vector<string>> ans;
        queue<vector<string>> q;
        vector<string> curr;
        curr.push_back(beginWord);
        q.push(curr);
        set<string> words(wordList.begin(), wordList.end());
        words.erase(beginWord);
        int minLength = INT_MAX;
        while(!q.empty()) {
        	int level = q.size();
        	vector<string> visited; // visited at current-level
        	for(int k=0; k<level; k++) {
        		vector<string> front = q.front();
	        	q.pop();
	        	int s = front.size();
	        	string word = front[s-1]; // last word
	        	if(word == endWord) {
	        		int length = s;
	        		if(minLength == length) {
	        			ans.push_back(front); // of minimum length
	        		}
	        		else if(minLength < length) {
	        			continue; // no need to process further sequences
	        		}
	        		else {
	        			// Once a minimum length is found
	        			// ..then after only >= length will be found
	        			minLength = min(minLength, length);
	        			ans.push_back(front);
	        		}
	        	}
	        	for(int i=0; i<word.size(); i++) {
	        		char ch = word[i];
	        		for(char c='a'; c<='z'; c++) {
	        			word[i] = c;
	        			if(words.find(word) != words.end()) {
	        				// Exists
	        				visited.push_back(word);
	        				front.push_back(word);
	        				q.push(front);
	        				front.pop_back(); // Backtrack .. back to front
	        			}
	        		}
	        		word[i] = ch; // Backtrack
	        	}
        	}
        	// After traversing all possibility at current-level
        	// Delete the words from set, visited at current-level
        	for(int i=0; i<visited.size(); i++) {
        		words.erase(visited[i]);
        	}
        }
        return ans;
    }
};

int main() {
	int n;
	cin >> n;
	vector<string> wordList(n);
	for(int i=0; i<n; i++) {
		cin >> wordList[i];
	}
	string beginWord, endWord;
	cin >> beginWord >> endWord;
	Solution solve;
	vector<vector<string>> ans = solve.findSequences(beginWord, endWord, wordList);
	for(int i=0; i<ans.size(); i++) {
		for(int j=0; j<ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}