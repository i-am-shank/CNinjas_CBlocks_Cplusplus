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

int findNodeRec(Node *head, int n) {
    if(head == NULL) {
        return -1;
    }
    if(head->data == n) {
        return 0;
    }
    int smallAns = findNodeRec(head->next, n);
    if(smallAns == -1) {
        return smallAns;
    }
    return smallAns + 1;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        Node *head = takeInput();
        int n;
        cin >> n;
        int index = findNodeRec(head, n);
        cout << index << endl;
    }
    return 0;
}