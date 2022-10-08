#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* takeInput() {
	ListNode* head = new ListNode(0);
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

class Solution {
	int lengthLL(ListNode* head) {
		int count = 0;
		ListNode* temp = head;
		while(temp != NULL) {
			count++;
			temp = temp->next;
		}
		return count;
	}

public:
	// Time : O(nA + nB)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int na = lengthLL(headA);
        int nb = lengthLL(headB);
        ListNode* tempA = headA, *tempB = headB;
        if(na > nb) {
        	int diff = (na - nb);
        	while(diff--) {
        		tempA = tempA->next;
        	}
        }
        else if(nb > na) {
        	int diff = (nb - na);
        	while(diff--) {
        		tempB = tempB->next;
        	}
        }
        while(tempA!=NULL && tempB!=NULL) {
        	if(tempA == tempB) {
        		return tempA;
        	}
        	tempA = tempA->next;
        	tempB = tempB->next;
        }
        return NULL; // No intersection found
    }
};

int main() {
	ListNode* headA = takeInput();
	ListNode* headB = takeInput();
	Solution solve;
	ListNode* head = solve.getIntersectionNode(headA, headB);
	printLL(head);
	return 0;
}