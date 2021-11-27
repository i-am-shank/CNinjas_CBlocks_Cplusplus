// Time Complexity = O(N)
// Space Complexity = O(1)


#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

Node* takeInput() {
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

int length(Node *head) {
    int c=0;
    Node *temp = head;
    while(temp != NULL) {
        c++;
        temp = temp->next;
    }
    return c;
}

Node *deleteNode(Node *head, int pos) {
    int i=0;
    if(head == NULL || pos >= length(head)) {
        return head;
    }
    if(pos == 0) {
        Node *ans = head->next;
        delete head;
        return ans;
    }
    Node *temp = head;
    while(temp->next->next != NULL && i+1 < pos) {
        temp = temp->next;
        i++;
    }
    Node *save = temp->next;
    temp->next = temp->next->next;
    delete save;
    return head;
}

void print(Node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
    return;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        Node *head = takeInput();
        int pos;
        cin >> pos;
        head = deleteNode(head, pos);
        print(head);
    }
    return 0;
}