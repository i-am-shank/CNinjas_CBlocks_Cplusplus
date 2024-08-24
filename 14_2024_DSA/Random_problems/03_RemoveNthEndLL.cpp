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
	int n;
	cin >> n;
	ListNode* head = new ListNode();
	ListNode* temp = head;
	for(int i=0; i<n; i++) {
		int ele;
		cin >> ele;
		ListNode* curr = new ListNode(ele);
		temp->next = curr;
		temp = temp->next;
	}
	return head->next;
}

void printLL(ListNode* head) {
	if(head == NULL) {
		cout << "\n";
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
	ListNode* remove(ListNode* head, int& n) {
		if(head == NULL) {
			return head;
		}
		// cout<<head->val<<" "<<n<<"\n";
		if(head->next==NULL) {
			if(n == 1) {
				n--;
				return NULL;
			}
			n--;
			return head;
		}
		ListNode* ans = remove(head->next, n);
		head->next = ans;
		// cout<<ans->val<<" --> "<<n<<"\n";
		if(n == 0) { // head!=NULL && head->next!=NULL
			head->next = head->next->next;
			n--;
			// cout<<head->val << " , " << head->next->val << "\n";
			return head;
		}
		n--;
		head->next = ans;
		return head;
	}

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *ans = remove(head, n);
        return ans;
    }
};

int main() {
	ListNode* head = takeInput();
	int n;
	cin >> n;
	Solution solve;
	ListNode* ans = solve.removeNthFromEnd(head, n);
	printLL(ans);
	return 0;
}