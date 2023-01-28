#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* next;
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

class Stack {
	// Define the data members
	Node* head;
	Node* tail;
	int size;

   public:
    Stack() {
        // Implement the Constructor
        head = NULL;
        size = 0;
    }

	/*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function
        return size;
    }

    bool isEmpty() {
        // Implement the isEmpty() function
        return (size == 0);
    }

    void push(int element) {
        // Implement the push() function
        Node* curr = new Node(element);
        if(isEmpty()) {
        	head = curr;
        }
        else {
	        curr->next = head;
	        head = curr;
        }
        size++;
        return;
    }

    int pop() {
        // Implement the pop() function
        if(isEmpty()) {
        	return -1;
        }
        int ans = head->data;
        head = head->next;
        size--;
        return ans;
    }

    int top() {
        // Implement the top() function
        if(isEmpty()) {
        	return -1;
        }
        int ans = head->data;
        return ans;
    }
};

int main() {
	Stack stk;
	int q;
	cin >> q;
	while(q--) {
		int choice, input;
		cin >> choice;
		/*
			1 -> push
			2 -> pop
			3 -> top
			4 -> size
			5 -> isEmpty
		*/
		int ans1;
		bool ans2;
		switch(choice) {
			case 1:
				cin >> input;
				stk.push(input);
				break;
			case 2:
				ans1 = stk.pop();
				cout << ans1 << "\n";
				break;
			case 3:
				ans1 = stk.top();
				cout << ans1 << "\n";
				break;
			case 4:
				ans1 = stk.getSize();
				cout << ans1 << "\n";
				break;
			default:
				ans2 = stk.isEmpty();
				cout << (ans2==true?"true":"false")<<"\n";
				break;
		}
	}
	return 0;
}