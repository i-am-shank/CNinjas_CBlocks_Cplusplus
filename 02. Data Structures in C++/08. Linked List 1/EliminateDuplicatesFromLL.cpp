// Time Complexity = O(N)
// Space Complexity = O(1)


#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

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

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return;
}

Node *removeDuplicates(Node *head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    if(head->data == head->next->data) {
        head = removeDuplicates(head->next);
    }
    else {
        head->next = removeDuplicates(head->next);
    }
    return head;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        Node *head = takeInput();
        head = removeDuplicates(head);
        print(head);
    }
    return 0;
}