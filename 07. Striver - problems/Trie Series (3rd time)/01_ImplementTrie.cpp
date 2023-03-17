#include <bits/stdc++.h>
using namespace std;

/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

class TrieNode {
	TrieNode* arr[26];
	bool flag = false;

public:
	TrieNode() { // constructor
		
	}

	bool hasKey(char ch) {
		return (arr[(int)(ch-'a')] != NULL);
	}

	TrieNode* get(char ch) {
		return arr[(int)(ch-'a')];
	}

	void put(char ch, TrieNode* node) {
		arr[(int)(ch-'a')] = node;
		return;
	}

	void setEnd() {
		flag = true;
	}

	bool isEnd() { // if end, flag is end.
		return flag;
	}
};

class Trie {
	TrieNode *root;

public:
    /** Initialize your data structure here. */
    Trie() {
    	root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
    	int n = word.size();
    	TrieNode *temp = root;
    	for(int i=0; i<n; i++) {
    		char ch = word[i];
    		if(temp->hasKey(ch)) {
    			temp = temp->get(ch);
    		}
    		else {
    			TrieNode *nextNode = new TrieNode();
    			temp->put(ch, nextNode);
    			temp = nextNode;
    		}
    	}
    	temp->setEnd();
    	return;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
    	int n = word.size();
    	TrieNode *temp = root;
    	for(int i=0; i<n; i++) {
    		char ch = word[i];
    		if(temp->hasKey(ch)) {
    			temp = temp->get(ch);
    		}
    		else { // current char doesn't exists
    			return false;
    		}
    	}
    	// If whole word traversed
    	// Check if a word ends here ?
    	return temp->isEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
    	int n = prefix.size();
    	TrieNode *temp = root;
    	for(int i=0; i<n; i++) {
    		char ch = prefix[i];
    		if(temp->hasKey(ch)) {
    			temp = temp->get(ch);
    		}
    		else { // current char doesn't exists
    			return false;
    		}
    	}
    	// If whole word traversed,
    	// ==> This prefix exists
    	return true;
    }
};

int main() {
	Trie* obj = new Trie();
	int t;
	cin >> t;
	while(t--) {
		int n;
		string str;
		cin >> n >> str;
		if(n == 1) {
			// Insert
			obj->insert(str);
		}
		else if(n == 2) {
			// Check word
			bool ans = obj->search(str);
			cout << (ans==true ? "true":"false") << "\n";
		}
		else if(n == 3) {
			// Check prefix
			bool ans = obj->startsWith(str);
			cout << (ans==true ? "true":"false") << "\n";
		}
		else {
			cout << -1 << "\n";
		}
	}
	return 0;
}