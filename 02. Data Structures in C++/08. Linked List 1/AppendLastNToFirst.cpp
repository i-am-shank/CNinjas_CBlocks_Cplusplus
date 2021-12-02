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
    return 0;
}

int length(Node *head) {
    int c = 0;
    Node* temp = head;
    while(temp != NULL) {
        c++;
        temp = temp->next;
    }
    return c;
}

Node *appendLastNToFirst(Node *head, int n) {
    int l = length(head);
    if(n >= l) {
        return head;
    }
    int i = l-n;
    Node *temp=head, *tail=head;
    while(tail->next != NULL) {
        tail = tail->next;
    }
    for(int j=1; j<i; j++) {
        temp = temp->next;
    }
    tail->next = head;
    Node *save = temp->next;
    temp->next = NULL;
    return save;
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

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        Node *head = takeInput();
        cin >> n;
        head = appendLastNToFirst(head, n);
        print(head);
    }
    return 0;
}