#include <bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
	unordered_map<Node*, Node*> check;

public:
    Node* copyRandomList(Node* head) {
    	if(head == NULL) {
    		return NULL;
    	}
        Node* head2 = new Node(head->val);
        check[head] = head2;
        Node* temp2 = head2;
        // Recursion will bring further nodes-copy
        if(check.find(head->next) == check.end()) {
        	Node* next2 = copyRandomList(head->next);
        	check[head->next] = next2;
        	head2->next = next2;
        }
        else{
        	head2->next = check[head->next];
        }
        if(check.find(head->random) == check.end()) {
        	Node* random2 = copyRandomList(head->random);
        	check[head->random] = random2;
        	head2->random = random2;
        }
        else{
        	head2->random = check[head->random];
        }
        return head2;
    }
};

int main() {
	Node* head = takeInput();
	Solution solve;
	Node* ans = solve.copyRandomList(head);
	printLL(ans);
	return 0;
}