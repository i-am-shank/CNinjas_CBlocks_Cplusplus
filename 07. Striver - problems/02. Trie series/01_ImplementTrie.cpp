#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	Node* links[26];  // Array of Node* (pointers)
	bool flag;
	bool containsKey(char c) {  // Check if current character exists in trie at this position
		return (links[c - 'a'] != NULL);
	}
	void put(char c, Node* referenceNode) {  // Point character to its reference node.
		links[c - 'a'] = referenceNode;
	}
	Node* get(char c) {  // Get reference node, corresponding to this character
		return (links[c - 'a']);
	}
};

class Trie {
	Node* root;  // Private member

public:
    Trie() {
        root = new Node();  // Root node
        root->flag = false;  // Set its flag false  .. will be true where a word ends
    }
    
    void insert(string word) {   // Time : O(n)   ->   n = Length of word
        Node* temp = root;  // Reference node corresponding to this word
        for(int i=0; i<word.size(); i++) {
        	if(temp->containsKey(word[i]) == false) {  // A word until this character doesn't exist till now
        		Node* newNode = new Node();  // Reference Trie-node corresponding to character word[i]
        		temp->put(word[i], newNode);
        		temp = newNode;  // Traverse to next node  (It's like linked list)
        	}
        	else {
        		Node* referenceNode = temp->get(word[i]);
        		temp = referenceNode;  // Traverse to next node
        	}
        }
        temp->flag = true;  // Current word has ended  ->  mark flag in last node (current node)  ->  true
    }
    
    bool search(string word) {   // Time : O(n)   ->    n = Length of word
        Node* temp = root;  // Node for iterating through word
        for(int i=0; i<word.size(); i++) {
        	if(temp->containsKey(word[i]) == false) {  // No corresponding substring till now exists
        		return false;
        	}
        	temp = temp->get(word[i]);  // Keep traversing through the reference nodes
        }
        return (temp->flag);  // Flag of reference node, corresponding to last character of word
    }
    
    bool startsWith(string prefix) {   // Time : O(n)   ->   n = Length of word
    	Node* temp = root;
    	for(int i=0; i<prefix.size(); i++) {
    		if(temp->containsKey(prefix[i]) == false) {
    			return false;
    		}
    		temp = temp->get(prefix[i]);
    	}
    	return true;  // If traversed till here.. there should exist a prefix like this
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
	// Just running the 1st leetcode example for this question
	Trie* obj = new Trie();
	obj->insert("apple");
	bool ans1 = obj->search("apple");
	bool ans2 = obj->search("app");
	bool ans3 = obj->startsWith("app");
	obj->insert("app");
	bool ans4 = obj->search("app");
	cout << ans1 << endl;
	cout << ans2 << endl;
	cout << ans3 << endl;
	cout << ans4 << endl;
	return 0;
}