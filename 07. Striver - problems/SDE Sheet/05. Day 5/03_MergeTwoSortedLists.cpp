#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* takeInput() {
	int num;
	cin >> num;
	ListNode* head = new ListNode();
	ListNode* temp = head;
	while(num--) {
		int data;
		cin >> data;
		ListNode* node = new ListNode(data);
		temp->next = node;
		temp = temp->next;
	}
	head = head->next; // removing dummy head
	return head;
}

void printLL(ListNode* head) {
	if(head == NULL) {
		return;
	}
	ListNode* temp = head;
	while(temp != NULL) {
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << "\n";
	return;
}

class Solution {
public:
	// Time : O(n1+n2)
	// Space : O(1) .. No extra space used.. already alloted nodes adjusted
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* temp = head;
        ListNode* temp1 = list1, *temp2 = list2;
        while(temp1!=NULL && temp2!=NULL) {
        	if(temp1->val <= temp2->val) {
        		ListNode* small = temp1;
        		temp1 = temp1->next;
        		small->next = NULL; // Break connection with temp1-nodes
        		temp->next = small;
        		temp = temp->next;
        	}
        	else {
        		ListNode* small = temp2;
        		temp2 = temp2->next;
        		small->next = NULL; // Break connection with temp2-nodes
        		temp->next = small;
        		temp = temp->next;
        	}
        }
        if(temp1 != NULL) {
        	temp->next = temp1; // Further.. temp1 is already sorted
        }
        if(temp2 != NULL) {
        	temp->next = temp2; // Further.. temp2 is already sorted
        }
        head = head->next;
        return head;
    }
};

int main() {
	ListNode* list1 = takeInput();
	ListNode* list2 = takeInput();
	Solution solve;
	ListNode* ans = solve.mergeTwoLists(list1, list2);
	printLL(ans);
	return 0;
}