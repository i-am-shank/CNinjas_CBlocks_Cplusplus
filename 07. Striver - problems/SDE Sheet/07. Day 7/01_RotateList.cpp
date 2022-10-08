#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* takeInput() {
	ListNode* head = new ListNode();
	ListNode* temp = head;
	int num;
	cin >> num;
	while(num--) {
		int data;
		cin >> data;
		ListNode* node = new ListNode(data);
		temp->next = node;
		temp = temp->next;
	}
	head = head->next; // remove dummy head
	return head;
}

void printLL(ListNode* head) {
	ListNode* temp = head;
	while(temp != NULL) {
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << "\n";
	return;
}

class Solution {
	int lengthLL(ListNode* head) {
		int len = 0;
		ListNode* temp = head;
		while(temp != NULL) {
			len++;
			temp = temp->next;
		}
		return len;
	}

public:
	// Time : O(n)
    ListNode* rotateRight(ListNode* head, int k) {
    	if(head == NULL) {
    		return head;
    	}
        int l = lengthLL(head);
        int rot = (k % l); // As l-rotations bring back original LL
        // For (rot)-rotation.. add last (rot) length LL to front
        // (rot) from last  =  End of (l-rot) nodes from front 
        if(rot == 0) { // No net-rotation required
        	return head;
        }
        int count = 1;
        ListNode* temp = head;
        while(count < (l-rot)) {
        	count++;
        	temp = temp->next;
        }
        ListNode* head2 = temp->next;
        temp->next = NULL;
        ListNode* temp2 = head2;
        while(temp2->next != NULL) {
        	temp2 = temp2->next;
        }
        temp2->next = head; // Connecting old-head to new head's tail
        return head2; // New head after rotation
    }
};

int main() {
	ListNode* head = takeInput();
	int k;
	cin >> k;
	Solution solve;
	ListNode* ans = solve.rotateRight(head, k);
	printLL(ans);
	return 0;
}