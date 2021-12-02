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

int lengthLL(Node *head) {
    if(head == NULL) {
        return 0;
    }
    int smallAns = lengthLL(head->next);
    return 1+smallAns;
}

Node* reverseLL(Node *head) {
    if(head==NULL || head->next==NULL) {
        return head;
    }
    Node *smallHead = reverseLL(head->next);
    head->next->next = head;
    head->next = NULL;
    return smallHead;
}

Node *kReverse(Node *head, int k) {
    if(head==NULL || head->next==NULL) {
        return head;
    }
    int l = lengthLL(head), i=0;
    if(k >= l) {
        return reverseLL(head);
    }
    Node *temp = head;
    while(i < k-1) {
        temp = temp->next;
        i++;
    }
    Node *save = temp->next;
    temp->next = NULL;
    head = reverseLL(head);
    temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = kReverse(save, k);
    return head;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        Node *head = takeInput();
        int k;
        cin >> k;
        head = kReverse(head, k);
        print(head);
    }
    return 0;
}