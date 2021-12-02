// TIme Complexity = O(N)
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

Node *skipMdeleteN(Node *head, int M, int N) {
    if(head == NULL) {
        return head;
    }
    if(M == 0) {
        return NULL;
    }
    if(N == 0) {
        return head;
    }
    Node *temp = head;
    while(temp != NULL) {
        int i=1;
        while(i<M && temp!=NULL){
            temp = temp->next;
            i++;
        }
        Node *save = temp;
        int j=0;
        while(j<=N && temp!=NULL) {
            temp = temp->next;
            j++;
        }
        if(save != NULL) {
            save->next = temp;
        }
    }
    return head;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        Node *head = takeInput();
        int M, N;
        cin >> M >> N;
        head = skipMdeleteN(head, M, N);
        print(head);
    }
    return 0;
}