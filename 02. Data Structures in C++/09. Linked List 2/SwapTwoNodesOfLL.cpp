// Time Complexity = O(N^2)
// Space Complexity = O(N)


#include <iostream>
#include <algorithm>
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

int lengthLL(Node *head) {
    if(head == NULL) {
        return 0;
    }
    int smallAns = lengthLL(head->next);
    return smallAns+1;
}

Node *swapNodes(Node *head, int i, int j) {
    int l = lengthLL(head);
    if(i>=l || j>=l) {
        return head;
    }
    if(head==NULL || head->next==NULL || i==j) {
        return head;
    }
    Node *temp = head;
    if(i == 0 || j==0) {
        int a = 0, x;
        if(i==0) {
            x = j;
        }
        else {
            x = i;
        }
        while(a<x-1 && temp!=NULL) {
            temp = temp->next;
            a++;
        }
        Node *save1 = temp->next;
        temp->next = head;
        Node *save2 = head->next;
        head->next = save1->next;
        save1->next = save2;
        return save1;
    } 
    head->next = swapNodes(head->next, i-1, j-1);
    return head;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        Node *head = takeInput();
        int i, j;
        cin >> i >> j;
        head = swapNodes(head, i, j);
        print(head);
    }
    return 0;
}