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
	// Numbers to be added are already given in reverse form
	// Also.. we have to return reverse-form of sum
	// So, no need to reverse LL anywhere.. simple addition (in manual way)

	// Time : O(max(n1.length() , n2.length()))

    ListNode* addLL(ListNode* n1, ListNode* n2) {
    	ListNode* head = new ListNode();
    	ListNode* temp = head;
    	int carry = 0;
    	ListNode* temp1 = n1, *temp2 = n2;
    	while(temp1!=NULL || temp2!=NULL || carry!=0) {
    		int sum = 0;
    		sum += carry;
    		if(temp1 != NULL) {
    			sum += (temp1->val);
    			temp1 = temp1->next;
    		}
    		if(temp2 != NULL) {
    			sum += (temp2->val);
    			temp2 = temp2->next;
    		}
    		int rem = (sum % 10);
			carry = (sum / 10); // Updated value
			ListNode* newNode = new ListNode(rem);
			temp->next = newNode;
			temp = temp->next;
    	}
    	head = head->next; // Remove dummy head-node;
    	return head;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sum = addLL(l1, l2);
        return sum;
    }
};

int main() {
	ListNode* l1 = takeInput();
	ListNode* l2 = takeInput();
	Solution solve;
	ListNode* ans = solve.addTwoNumbers(l1, l2);
	printLL(ans);
	return 0;
}