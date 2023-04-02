#include <bits/stdc++.h>
using namespace std;

class TrieNode {
	TrieNode *links[26];
	bool flag = false;

public:
	bool hasKey(char ch) {
		return (links[ch-'a'] != NULL);
	}

	void setEnd() {
		flag = true;
	}

	bool isEnd() {
		return flag;
	}

	TrieNode *get(char ch) {
		return links[ch-'a'];
	}

	void add(char ch, TrieNode *node) {
		links[ch-'a'] = node;
	}
};

class MagicDictionary {
	TrieNode *root;

public:
    MagicDictionary() {
        root = new TrieNode();
    }
    
    void buildDict(vector<string> dictionary) {
        int x = dictionary.size();
        for(int i=0; i<x; i++) {
        	string str = dictionary[i];
        	int n = str.size();
        	TrieNode *temp = root;
        	for(int j=0; j<n; j++) {
        		char ch = str[i];
        		if(temp->hasKey(ch)) {
        			temp = temp->get(ch);
        		}
        		else {
        			TrieNode *newNode = new TrieNode();
        			temp->add(ch, newNode);
        			temp = newNode;
        		}
        	}
        	temp->setEnd();
        }
        return;
    }

    bool find(string str, int n, int idx, TrieNode *root, int cnt) {
    	if(root==NULL) {
    		return false;
    	}
    	if(idx >= n) {
    		cout<<str<<" "<<cnt<<"\n";
    		if(cnt == 1) {
    			return root->isEnd();
    		}
    		return false;
    	}
    	char ch = str[idx];
    	bool ans = false;
    	if(root->hasKey(ch)) {
    		cout<<str<<" "<<ch<<" "<<idx<<" "<<cnt<<"==== \n";
    		ans = find(str, n, idx+1, root->get(ch), cnt);
    		return ans;
    	}
    	else {
    		// Here only if not got true
	    	for(char c='a'; c<='z'; c++) {
	    		// Already checked for ch, no need to check again
	    		if(c!=ch && root->hasKey(c)) {
	    			TrieNode *newNode = root->get(c);
	    			cnt++;
	    			ans = find(str, n, idx+1, newNode, cnt);
	    			cout<<ch<<" "<<str<<" "<<idx<<" "<<cnt<<"\n";
	    			cnt--;
	    			if(ans == true) {
	    				return true;
	    			}
	    		}
	    	}
	    	return false;
    	}
    }
    
    bool search(string searchWord) {
    	int n = searchWord.size();
        return find(searchWord, n, 0, root, 0);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */

int main() {
	MagicDictionary* obj = new MagicDictionary();
	vector<string> curr(2);
	curr[0]="hello", curr[1]="leetcode";
	obj->buildDict(curr);
	bool ans1 = obj->search("hello");
	bool ans2 = obj->search("hhllo");
	bool ans3 = obj->search("hell");
	bool ans4 = obj->search("leetcoded");
	cout<<ans1<<" "<<ans2<<" "<<ans3<<" "<<ans4<<"\n";
	return 0;
}