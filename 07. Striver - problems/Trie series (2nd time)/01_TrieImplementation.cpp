#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	Node* links[26];
	bool flag = false;

	void put(char ch, Node* node) {
		links[(int)(ch-'a')] = node;
	}

	Node* get(char ch) {
		return links[(int)(ch-'a')];
	}

	bool isEnd() {
		return flag; // if true, returns true
	}

	bool containsKey(char ch) {
		return (links[(int)(ch-'a')] != NULL);
	}

	void setEnd() {
		flag = true;
	}
};


class Trie {
	Node* root;

public:
	Trie() {
		root = new Node();
		root->flag = false;
	}

	void insert(string word) {
		Node* temp = root;
		for(int i=0; i<word.size(); i++) {
			if(!temp->containsKey(word[i])) {
				Node* newNode = new Node();
				temp->put(word[i], newNode);
				temp = newNode;
			}
			else {
				temp = temp->get(word[i]);
			}
		}
		temp->setEnd();
		return;
	}

	bool search(string word) {
		Node* temp = root;
		for(int i=0; i<word.size(); i++) {
			if(!temp->containsKey(word[i])) {
				return false;
			}
			temp = temp->get(word[i]);
		}
		return temp->isEnd();
	}

	bool startsWith(string prefix) {
		Node* temp = root;
		for(int i=0; i<prefix.size(); i++) {
			if(!temp->containsKey(prefix[i])) {
				return false;
			}
			temp = temp->get(prefix[i]);
		}
		// if whole word traversed.. this prefix should've existed
		return true;
	}
};

int main() {
	Trie* myTrie = new Trie();
	string word1, word2, word3;
	cin >> word1 >> word2 >> word3;
	myTrie->insert(word1);
	myTrie->insert(word2);
	myTrie->insert(word3);
	string word4, word5;
	cin >> word4 >> word5;
	bool ans1 = myTrie->search(word4);
	bool ans2 = myTrie->startsWith(word5);
	cout << ans1 << " " << ans2 << "\n";
	return 0;
}