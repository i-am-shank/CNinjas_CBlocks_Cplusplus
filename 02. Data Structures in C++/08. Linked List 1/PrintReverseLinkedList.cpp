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

void printReverse(Node *head) {
    if(head == NULL) {
        return;
    }
    printReverse(head->next);
    cout << head->data << " ";
    return;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        Node *head = takeInput();
        printReverse(head);
        cout << endl;
    }
    return 0;
}