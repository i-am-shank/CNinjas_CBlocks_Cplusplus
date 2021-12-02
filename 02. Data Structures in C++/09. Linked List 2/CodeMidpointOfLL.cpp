// Time Complexity = O(N)
// Space Complexity = O(1)


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
        Node *newNode = new Node (data);
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

Node *midPoint(Node *head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    Node *slow = head, *fast = head;
    while(fast->next!=NULL && fast->next->next!=NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        Node *head = takeInput();
        Node *mid = midPoint(head);
        if(mid != NULL) {
            cout << mid->data;
        }
        cout << endl;
    }
    return 0;
}