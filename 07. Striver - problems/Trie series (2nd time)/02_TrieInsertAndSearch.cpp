#include <bits/stdc++.h>
using namespace std;

#define ALPHABET_SIZE (26)

struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    // isLeaf is true if the node represents
    // end of a word
    bool isLeaf;
};

struct TrieNode *getNode(void) {
    struct TrieNode *pNode = NULL;
    pNode = (struct TrieNode *) malloc(sizeof(struct TrieNode));
    if (pNode) {
        int i;
        pNode->isLeaf = false;
        for (i = 0; i < ALPHABET_SIZE; i++) pNode->children[i] = NULL;
    }
    return pNode;
}

void insert(struct TrieNode *root, string key) {
    int n = key.size();
    TrieNode* temp = root;
    for(int i=0; i<n; i++) {
    	if(temp->children[(int)(key[i]-'a')] == NULL) {
    		// Generate a new reference node
    		// And point to it.. the iterate forward to it
    		TrieNode* newNode = getNode();
    		temp->children[(int)(key[i]-'a')] = newNode;
    		temp = temp->children[(int)(key[i]-'a')];
    	}
    	else {
    		temp = temp->children[(int)(key[i]-'a')];
    	}
    }
    temp->isLeaf = true;
    return;
}

bool search(struct TrieNode *root, string key) {
    // code here
    TrieNode* temp = root;
    int n = key.size();
    for(int i=0; i<n; i++) {
    	if(temp->children[(int)(key[i]-'a')] == NULL) {
    		return false;
    	}
    	else {
    		temp = temp->children[(int)(key[i]-'a')];
    	}
    }
    // Now whole word traversed
    return (temp->isLeaf);
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		string keys[n];
		for(int i=0; i<n; i++) {
			cin >> keys[i];
		}
		struct TrieNode *root = getNode();
		for(int i=0; i<n; i++) {
			insert(root, keys[i]);
		}
		string s;
		cin >> s;
		if(search(root, s)) {
			cout << "1\n";
		}
		else {
			cout << "0\n";
		}
	}
	return 0;
}