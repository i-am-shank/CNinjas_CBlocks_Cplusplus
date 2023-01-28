#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node *next;
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

class Queue {
	// Define the data members
	Node* head;
	int size;

   public:
    Queue() {
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

    void enqueue(int data) {
		// Implement the enqueue() function
		Node* curr = new Node(data);
		curr->next = head;
		head = curr;
		size++;
		return;
	}

    int dequeue() {
        // Implement the dequeue() function
        if(isEmpty()) {
        	return -1;
        }
        int ans;
        if(head->next == NULL) {
        	size--;
        	ans = head->data;
        	head = NULL;
        }
        else {
        	Node *temp = head;
	        while(temp->next->next != NULL) {
	        	temp = temp->next;
	        }
	        ans = temp->next->data;
	        temp->next = NULL; // removed
	        size--;
        }
        return ans;
    }

    int front() {
        // Implement the front() function
        if(isEmpty()) {
        	return -1;
        }
        Node *temp = head;
        while(temp->next != NULL) {
        	temp = temp->next;
        }
        int ans = temp->data;
        return ans;
    }
};

int main() {
	Queue q;
	int t;
	cin >> t;
	while(t--) {
		int choice, num;
		cin >> choice;
		int ans1;
		bool ans2;
		/*
		1 -> enqueue
		2 -> dequeue
		3 -> front
		4 -> getSize
		5 -> isEmpty
		*/
		switch(choice) {
			case 1:
				cin >> num;
				q.enqueue(num);
				break;
			case 2:
				ans1 = q.dequeue();
				cout << ans1 << "\n";
				break;
			case 3:
				ans1 = q.front();
				cout << ans1 << "\n";
				break;
			case 4:
				ans1 = q.getSize();
				cout << ans1 << "\n";
				break;
			default:
				ans2 = q.isEmpty();
				cout << (ans2==true?"true":"false")<<"\n";
				break;
		}
	}
	return 0;
}