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

	int lenLadder(string beginWord, string endWord, vector<string>& wordList) {
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

	bool dfs(string beginWord, string endWord, vector<string>& wordList, int n, int len, vector<string>& words, vector<vector<string>>& ladders, vector<bool>& visited) {
		if(words.size() > len) {
			return false;
		}
		if(beginWord==endWord) {
			if(words.size() == len) {
				ladders.push_back(words);
				return true;
			}
			return false;
		}
		for(int i=0; i<n; i++) {
			if(!visited[i] && strDiff1(beginWord, wordList[i])) {
				visited[i] = true;
				words.push_back(wordList[i]);
				bool ans = dfs(wordList[i], endWord, wordList, n, len, words, ladders, visited);
				visited[i] = false;
				words.pop_back();
			}
		}
		return false;
	}

	void find(unordered_map<string,vector<string>>& parent, string& word, vector<string>& ladder, vector<vector<string>>& ladders) {
		if(parent[word].size() == 0) {
			reverse(ladder.begin(), ladder.end());
			// As beginWord pushed at last (reverse it)
			ladders.push_back(ladder);
			return; // reached startWord
		}
		for(int i=0; i<parent[word].size(); i++) {
			string curr = parent[word][i];
			ladder.push_back(curr);
			find(parent, curr, ladder, ladders);
		}
		return;
	}

public:
	vector<vector<string>> findLadders2(string beginWord, string endWord, vector<string>& wordList) {
		int n = wordList.size();
        vector<bool> visited(n, false);
        unordered_map<string, vector<string>> parent;
        int time = 1; // beginWord.. always there
        queue<string> q;
        for(int i=0; i<n; i++) {
        	if(strDiff1(beginWord, wordList[i])) {
        		visited[i] = true;
        		parent[wordList[i]].push_back(beginWord);
        		q.push(wordList[i]);
        	}
        }
        bool found = false;
        while(!q.empty() && !found) {
        	int s = q.size();
        	time++;
        	for(int i=0; i<s; i++) {
        		string front = q.front();
        		q.pop();
        		if(front == endWord) {
        			found = true; // last layer which ran
        			parent[endWord].push_back(front);
        			continue;
        		}
        		for(int j=0; j<n; j++) {
        			if(!visited[j] && strDiff1(front,wordList[j])) {
        				q.push(wordList[j]);
        				parent[wordList[j]].push_back(front);
        				visited[j] = true;
        			}
        		}
        	}
        }
        vector<vector<string>> ladders;
        for(int i=0; i<parent[endWord].size(); i++) {
        	vector<string> ladder;
        	ladder.push_back(endWord);
        	ladder.push_back(parent[endWord][i]);
        	find(parent, parent[endWord][i], ladder, ladders);
        }
        return ladders; // Not gone to endWord any how.
	}

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        vector<bool> visited(n, false);
        int len = lenLadder(beginWord, endWord, wordList);
        vector<vector<string>> ladders;
        for(int i=0; i<n; i++) {
        	if(strDiff1(beginWord, wordList[i])) {
        		vector<string> words;
        		words.push_back(beginWord);
        		visited[i] = true;
        		words.push_back(wordList[i]);
        		bool ans = dfs(wordList[i], endWord, wordList, n, len, words, ladders, visited);
        		if(ans == true) {
        			ladders.push_back(words);
        		}
        		visited[i] = false; // backtrack to explore other possibilities
        		words.pop_back(); // backtrack
        	}
        }
        set<vector<string>> check;
        for(int i=0; i<ladders.size(); i++) {
        	check.insert(ladders[i]);
        }
        vector<vector<string>> v;
        ladders = v;
        for(auto it: check) {
        	ladders.push_back(it);
        }
        return ladders;
    }
};

int main() {
	Solution solve;
	string beginWord, endWord;
	cin >> beginWord >> endWord;
	int n;
	cin >> n;
	vector<string> wordList(n);
	for(int i=0; i<n; i++) {
		cin >> wordList[i];
	}
	vector<vector<string>> ans = solve.findLadders2(beginWord, endWord, wordList);
	for(int i=0; i<ans.size(); i++) {
		for(int j=0; j<ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}