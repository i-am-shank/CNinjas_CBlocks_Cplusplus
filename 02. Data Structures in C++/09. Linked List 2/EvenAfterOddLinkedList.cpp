// TIme Complexity = O(N^2)  ..  improved to O(N)
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
        if(head==NULL) {
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

Node *evenAfterOddSlow(Node *head) {        // O(N^2) time complexity
    if(head==NULL || head->next==NULL) {
        return head;
    }
    Node *smallHead = evenAfterOddSlow(head->next);
    if(head->data % 2 == 0) {
        Node *temp = smallHead;
        // Get to the last Odd element & append head there.
        while(temp->next!=NULL && temp->next->data%2 != 0) {
            temp = temp->next;
        }
        Node *save = temp->next;
        temp->next = head;
        head->next = save;
        return smallHead;
    }
    else {
        head->next = smallHead;
        return head;
    }
}

Node *evenAfterOdd(Node *head) {        // O(N) time complexity
    if(head==NULL || head->next==NULL) {
        return head;
    }
    Node *evenHead=NULL, *evenTail=NULL, *oddHead=NULL, *oddTail=NULL, *temp=head;
    while(temp != NULL) {
        if(temp->data % 2 == 0) {
            if(evenHead == NULL) {
                evenHead = temp;
                evenTail = temp;
            }
            else {
                evenTail->next = temp;
                evenTail = evenTail->next;
            }
            temp = temp->next;
        }
        else {
            if(oddHead == NULL) {
                oddHead = temp;
                oddTail = temp;
            }
            else {
                oddTail->next = temp;
                oddTail = oddTail->next;
            }
            temp = temp->next;
        }
    }
    if(oddHead == NULL) {
        evenTail->next = NULL;
        return evenHead;
    }
    if(evenHead == NULL) {
        oddTail->next = NULL;
        return oddHead;
    }
    oddTail->next = evenHead;
    evenTail->next = NULL;
    return oddHead;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        Node *head = takeInput();
        head = evenAfterOdd(head);
        print(head);
    }
    return 0;
}