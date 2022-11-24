#include <bits/stdc++.h>
using namespace std;

#define pp pair<string,int>
#define ppp pair<int, vector<string>>
#define fi first
#define se second
#define mp make_pair

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
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    	vector<vector<string>> ans;
        unordered_map<int, vector<string>> levelWords;
        int n = wordList.size();
        queue<pp> q;
        q.push(mp(beginWord,1));
        unordered_set<string> words(wordList.begin(), wordList.end());
        words.erase(beginWord);
        int minLevel = INT_MAX;
        bool found = false;
        while(!q.empty() && found==false) {
        	int s = q.size();
        	for(int i=0; i<s; i++) {
        		pp front = q.front();
	        	q.pop();
	        	string word=front.fi;
	        	int level=front.se;
	        	levelWords[level].push_back(word);
	        	if(word == endWord) {
	        		minLevel = min(minLevel,level);
	        		found = true;
	        		break;
	        	}
	        	for(int i=0; i<word.size(); i++) {
	        		char ch = word[i];
	        		for(char c='a'; c<='z'; c++) {
	        			word[i] = c;
	        			if(words.find(word) != words.end()) {
	        				words.erase(word);
	        				q.push(mp(word,level+1));
	        			}
	        		}
	        		word[i] = ch; // Backtrack
	        		// to maintain only 1 char. change
	        	}
        	}
        }
        if(found == true) {
        	// Then only backtrack .. along map
        	int level = minLevel;
        	queue<ppp> q2;
        	vector<string> sequence;
        	sequence.push_back(endWord);
        	q2.push(mp(level,sequence));
        	while(!q2.empty()) {
        		ppp front = q2.front();
        		q2.pop();
        		int curr=front.fi;
        		vector<string> v=front.se;
        		if(curr == 1) {
        			// Reached beginWord
        			reverse(v.begin(), v.end());
        			ans.push_back(v);
        			continue; // Don't process further of v
        		}
        		int s = v.size();
        		string w = v[s-1];
        		for(auto it: levelWords[curr-1]) {
        			if(nextWord(w,it)) {
        				v.push_back(it);
        				q2.push(mp(curr-1,v));
        				v.pop_back();
        			}
        		}
        	}
        	return ans;
        }
        else {
        	return ans;
        }
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
	vector<vector<string>> ans = solve.findLadders(beginWord, endWord, wordList);
	for(int i=0; i<ans.size(); i++) {
		for(int j=0; j<ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}