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

Node* takeInput() {
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
    return;
}

Node* insertNode(Node *head, int i, int data) {
    if(head == NULL) {
        return head;
    }
    if(i==0) {
        Node *newNode = new Node(data);
        newNode->next = head;
        return newNode;
    }
    head->next = insertNode(head->next, i-1, data);
    return head;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        Node *head = takeInput();
        int i, data;
        cin >> i >> data;
        head = insertNode(head, i, data);
        print(head);
    }
    return 0;
}