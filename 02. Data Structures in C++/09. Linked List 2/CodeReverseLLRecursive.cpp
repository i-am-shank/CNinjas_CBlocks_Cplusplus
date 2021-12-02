// Time Complexity = O(N)
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

Node *reverseLinkedListRec(Node *head) {
    if(head==NULL || head->next==NULL) {
        return head;
    }
    Node *temp = reverseLinkedListRec(head->next);
    head->next->next = head;
    head->next = NULL;
    return temp;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        Node *head = takeInput();
        head = reverseLinkedListRec(head);
        print(head);
    }
    return 0;
}