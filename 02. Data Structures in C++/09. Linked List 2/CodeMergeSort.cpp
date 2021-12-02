// Time Complexity = O(NlogN)  ..  O(logN) for Divide  *  O(N) for Conquer
// Space Complexity = O(logN)

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

Node *midLL(Node *head) {
    if(head==NULL || head->next==NULL) {
        return head;
    }
    Node *fast=head, *slow=head;
    while(fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node *merge(Node *head1, Node* head2) {
    if(head1 == NULL) {
        return head2;
    }
    if(head2 == NULL) {
        return head1;
    }
    if(head1->data <= head2->data) {
        head1->next = merge(head1->next, head2);
        return head1;
    }
    else {
        head2->next = merge(head1, head2->next);
        return head2;
    }
}

Node *mergeSort(Node *head) {
    if(head==NULL || head->next==NULL) {
        return head;
    }
    Node *mid = midLL(head);
    Node *head2 = mid->next;
    mid->next = NULL;
    Node *head1 = mergeSort(head);
    head2 = mergeSort(head2);
    head1 = merge(head1, head2);
    return head1;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        Node *head = takeInput();
        head = mergeSort(head);
        print(head);
    }
    return 0;
}