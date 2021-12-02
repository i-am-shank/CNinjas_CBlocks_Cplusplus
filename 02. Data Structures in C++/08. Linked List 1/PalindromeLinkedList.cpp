// Time Complexity = O(N^2)
// Space Complexity = O(N)


#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node (int data) {
        this->data = data;
        this->next = NULL;
    }
};

Node *takeInput() {
    int data;
    cin >> data;
    Node *head=NULL, *tail=NULL;
    while(data != -1) {
        Node *newNode = new Node(data);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}

bool isPalindromeHelper(Node *head, Node *tail) {
    if(head == NULL || head->next == NULL) {
        return true;
    }
    if(head->data == tail->data) {
        Node *newHead = head->next;
        tail->next = NULL;
        Node *newTail = head;
        while(newTail->next != NULL && newTail->next->next != NULL) {
            newTail = newTail->next;
        }
        return isPalindromeHelper(newHead, newTail);
    }
    return false;
}

bool isPalindrome(Node *head) {
    if(head == NULL) {
        return true;
    }
    Node *tail = head;
    while(tail->next != NULL) {
        tail = tail->next;
    }
    return isPalindromeHelper(head, tail);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Node *head = takeInput();
        bool ans = isPalindrome(head);
        if(ans == 1) {
            cout << "true" << endl;
        }
        else {
            cout << "false" << endl;
        }
    }
    return 0;
}