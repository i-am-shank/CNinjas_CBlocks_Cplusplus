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

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return;
}

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2) {
    if(head1 == NULL) {
        return head2;
    }
    if(head2 == NULL) {
        return head1;
    }
    if(head1->data <= head2->data) {
        head1->next = mergeTwoSortedLinkedLists(head1->next, head2);
        return head1;
    }
    else{
        head2->next = mergeTwoSortedLinkedLists(head1, head2->next);
        return head2;
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        Node *head1 = takeInput();
        Node *head2 = takeInput();
        head1 = mergeTwoSortedLinkedLists(head1, head2);
        print(head1);
    }
    return 0;
}