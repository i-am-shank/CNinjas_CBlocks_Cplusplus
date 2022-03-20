#include <iostream>
#include <string>
using namespace std;

class TrieNode {
public:
	char data;
	TrieNode **children;
	bool isTerminal;
	TrieNode(char data) {
		this->data = data;
		children = new TrieNode*[26];
		for(int i=0; i<26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
	}
};

class Trie {
	TrieNode *root;
public:
	Trie() {
		root = new TrieNode('\0');
	}
	~Trie() {
		delete root;
	}
	
	void insertWordHelper(TrieNode *root, string word) {
		if(word.size() == 0) {
			root->isTerminal = true;
			return;
		}
		int index = word[0] - 'a';
		TrieNode *child;
		if(root->children[index] != NULL) {
			child = root->children[index];
		}
		else {
			child = new TrieNode(word[0]);
			root->children[index] = child;
		}
		insertWordHelper(root, word.substr(1));
	}

	void insertWord(string word) {
		insertWordHelper(root, word);
	}

	bool searchHelper(TrieNode *root, string word) {
		if(word.size() == 0) {
			return root->isTerminal;
		}
		int index = word[0] - 'a';
		TrieNode *child;
		if(root->children[index] != NULL) {
			child = root->children[index];
		}
		else {
			return false;
		}
		return searchHelper(child, word.substr(1));
	}

	bool search(string word) {
		return searchHelper(root, word);
	}

	bool searchPrefixHelper(TrieNode *root, string word) {
		if(word.size() == 0) {
			return true;
		}
		int index = word[0] - 'a';
		TrieNode *child;
		if(root->children[index] != NULL) {
			child = root->children[index];
		}
		else {
			return false;
		}
		return searchPrefixHelper(child, word.substr(1));
	}

	bool searchPrefix(string word) {
		return searchPrefixHelper(root, word);
	}
};

int main() {
	Trie *root = new Trie();
	root->insertWord("apple");
	root->insertWord("apple");
	root->insertWord("apps");
	root->insertWord("apps");
	cout << "Is apple present : " << (root->search("apple") == true ? "Yes" : "No") << endl;
	cout << "Is answer present : " << (root->search("answer") == true ? "Yes" : "No") << endl;
	cout << "Is app prefix : " << (root->searchPrefix("app") == true ? "Yes" : "No") << endl;
	cout << "Is ans prefix : " << (root->searchPrefix("ans") == true ? "Yes" : "No") << endl;
	return 0;
}