#include <bits/stdc++.h>
using namespace std;


class Node {
public:
	Node* links[26];
	int endWith = 0;
	int countPrefix = 0;
	bool containsKey(char c) {
		return (links[c - 'a'] != NULL);
	}
	void put(char c, Node* referenceNode) {
		links[c-'a'] = referenceNode;
		return;
	}
	Node* get(char c) {
		return links[c-'a'];
	}
	void increasePrefix() {
		countPrefix++;
	}
	void deleteEnd() {
		endWith--;
	}
	void reducePrefix() {
		countPrefix--;
	}
	void setEnd() {
		endWith++;
	}
	int getEnd() {
		return endWith;
	}
	int getPrefix() {
		return countPrefix;
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
				Node* referenceNode = new Node();  // corresponding to new char
				temp->put(word[i], referenceNode);
				temp = temp->get(word[i]);  // Traversing
				temp->increasePrefix();
			}
			else {
				temp = temp->get(word[i]);
				temp->increasePrefix();
			}
		}
		temp->setEnd();
	}

	int countWordsEqualTo(string word) {
		Node* temp = root;
		for(int i=0; i<word.size(); i++) {
			if(temp->containsKey(word[i])) {
				temp = temp->get(word[i]);
			}
			else {
				return 0;
			}
		}
		return temp->getEnd();
	}

	int countWordsStartingWith(string word) {
		Node* temp = root;
		for(int i=0; i<word.size(); i++) {
			if(temp->containsKey(word[i])) {
				temp = temp->get(word[i]);
			}
			else {
				return 0;
			}
		}
		return temp->getPrefix();
	}

	void erase(string word) {
		Node* temp = root;
		for(int i=0; i<word.size(); i++) {
			if(temp->containsKey(word[i])) {
				temp = temp->get(word[i]);
				temp->reducePrefix();
			}
			else {
				return;
			}
		}
		temp->deleteEnd();
	}
};


int main() {
	Trie* obj = new Trie();
	obj->insert("apple");
	obj->insert("apple");
	obj->insert("appl");
	obj->insert("bat");
	cout << obj->countWordsEqualTo("apple") << endl;
	cout << obj->countWordsStartingWith("app") << endl;
	obj->erase("apple");
	cout << obj->countWordsEqualTo("apple") << endl;
	cout << obj->countWordsStartingWith("app") << endl;
	return 0;
}