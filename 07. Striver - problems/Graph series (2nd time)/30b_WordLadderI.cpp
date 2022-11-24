#include <bits/stdc++.h>
using namespace std;

class Solution {
	#define pp pair<string,int>
	#define fi first
	#define se second
	#define mp make_pair
	
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
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        int n = wordList.size();
        unordered_set<string> words(wordList.begin(),wordList.end());
        queue<pp> q;
        q.push(mp(startWord,1));
        words.erase(startWord);
        while(!q.empty()) {
        	pp front = q.front();
        	q.pop();
        	string w1=front.fi;
        	int n1=front.se;
        	if(w1 == targetWord) {
        		return n1; // Word found after n1 steps
        	}
        	for(int i=0; i<w1.size(); i++) {
        		char c = w1[i];
        		// Changing only ith char (1 char. change)
        		for(char ch='a'; ch<='z'; ch++) {
        			w1[i] = ch;
        			if(words.find(w1) != words.end()) {
	        			// Exists
	        			q.push(mp(w1,n1+1));
	        			words.erase(w1);
	        		}
        		}
        		w1[i] = c; // Backtrack to original word
        	}
        }
        return 0; // If no word reaches target
    }
};

int main() {
	int n;
	cin >> n;
	vector<string> wordList(n);
	for(int i=0; i<n; i++) {
		cin >> wordList[i];
	}
	string startWord, targetWord;
	cin >> startWord >> targetWord;
	Solution solve;
	int ans = solve.wordLadderLength(startWord, targetWord, wordList);
	cout << ans << "\n";
	return 0;
}