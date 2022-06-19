#include <bits/stdc++.h>
using namespace std;


class Node {
public:
	Node* links[26];
	bool flag = false;
	bool containsKey(char c) {
		return (links[c-'a'] != NULL);
	}
	void put(char c, Node* referenceNode) {
		links[c-'a'] = referenceNode;
	}
	Node* get(char c) {
		return (links[c-'a']);
	}
	void setEnd() {
		flag = true;
	}
	bool getEnd() {
		return (flag == true);
	}
};


class Trie {
	Node* root;

public:
	Trie() {
		root = new Node();
	}

	void insert(string word) {
		Node* temp = root;
		for(int i=0; i<word.size(); i++) {
			if(temp->containsKey(word[i]) == false) {
				temp->put(word[i], new Node());
			}
			temp = temp->get(word[i]);
		}
		temp->setEnd();
		return;
	}

	bool hasWord(string word) {
		Node* temp = root;
		for(int i=0; i<word.size(); i++) {
			if(temp->containsKey(word[i]) == false) {
				return false;
			}
			temp = temp->get(word[i]);
		}
		return temp->getEnd();
	}
};

// Using set, this can also be done   ..   but Space complexity !!  (will be O(n^3) in that case)
// Trie does reusablility of space  ->  less Space complexity

int countDistinctSubstrings(string &s){  // Time : O(n^2)
    //    Write your code here.
	int count = 0, n = s.size();
	Trie* myTrie = new Trie();
	for(int i=0; i<n; i++) {
		for(int j=i+1; j<=n; j++) {
			if(myTrie->hasWord(s.substr(i, j-i)) == false) {
				myTrie->insert(s.substr(i, j-i));
				count++;
			}
		}
	}
	return (count+1);  // +1 for including empty subset
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		int ans = countDistinctSubstrings(s);
		cout << ans << endl;
	}
	return 0;
}