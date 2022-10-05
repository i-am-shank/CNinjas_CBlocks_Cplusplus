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
	// Time : O(n)
	int lengthLL(ListNode* head) {
		int ans = 0;
		ListNode* temp = head;
		while(temp != NULL) {
			ans++;
			temp = temp->next;
		}
		return ans;
	}

	// Time : O(n)
	ListNode* removeNth(ListNode* head, int n) {
		if(n == 1) { // Have to delete head.
			return head->next;
		}
		ListNode* temp = head;
		int idx = 1;
		while(idx < (n-1)) {
			idx++;
			temp = temp->next;
		}
		ListNode* del = temp->next;
		temp->next = temp->next->next;
		del->next = NULL; // Deleting connections with del node.
		return head;
	}

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l = lengthLL(head);
        // nth node from end  =  ((l-n)+1)th node from start
        int x = (l-n)+1;
        ListNode* ans = removeNth(head, x);
        return ans;
    }
};

int main() {
	Solution solve;
	ListNode* head = takeInput();
	int n;
	cin >> n;
	ListNode* ans = solve.removeNthFromEnd(head, n);
	printLL(ans);
	return 0;
}