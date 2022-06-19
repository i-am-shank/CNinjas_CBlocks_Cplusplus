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
		return;
	}
	Node* get(char c) {
		return links[c-'a'];
	}
	void setEnd() {
		flag = true;
	}
	bool isEnd() {
		return flag;
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

	bool hasWord(string prefix) {
		Node* temp = root;
		for(int i=0; i<prefix.size(); i++) {
			if(temp->containsKey(prefix[i]) == false) {
				return false;
			}
			temp = temp->get(prefix[i]);
		}
		return temp->isEnd();  // Whole substring traversed.. is this whole word ?
	}
};


string completeString(int n, vector<string> &a){
    // Write your code here.
	Trie* myTrie = new Trie();
	for(int i=0; i<n; i++) {
		myTrie->insert(a[i]);
	}
	string ans = "";
	int ansSize = -1;
	for(int i=0; i<n; i++) {
		int aSize = a[i].size();
		bool allPrefixExist = true;
		for(int j=1; j<=aSize; j++) {
			if(myTrie->hasWord(a[i].substr(0, j)) == false) {
				allPrefixExist = false;
				break;
			}
		}
		if(allPrefixExist == true) {
			if(aSize > ansSize) {
				ans = a[i];
				ansSize = aSize;
			}
			else if((aSize == ansSize)  &&  (a[i] < ans)) {
				ans = a[i];
				ansSize = aSize;
			}
		}
	}
	if(ans == "") {
		return "None";
	}
	return ans;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<string> a;
		for(int i=0; i<n; i++) {
			string s;
			cin >> s;
			a.push_back(s);
		}
		string ans = completeString(n, a);
		cout << ans << endl;
	}
	return 0;
}