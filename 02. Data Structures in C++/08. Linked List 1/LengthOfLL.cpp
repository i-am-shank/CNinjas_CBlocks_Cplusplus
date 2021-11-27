// Time Complexity = O(N)
// Space Complexity = O(1)


#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node(int data) {
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

int length(Node *head) {
    int l=0;
    Node *temp = head;
    while(temp != NULL) {
        temp = temp->next;
        l++;
    }
    return l;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        Node *head = takeInput();
        int ans = length(head);
        cout << ans << endl;
    }
    return 0;
}