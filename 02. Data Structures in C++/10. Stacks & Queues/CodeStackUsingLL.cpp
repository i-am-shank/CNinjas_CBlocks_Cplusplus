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

class Stack {
    private:

    Node *head;
    int size;

    public:

    Stack() {
        head = NULL;
        size = 0;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    void push(int element) {
        Node *newNode = new Node (element);
        if(head == NULL) {
            head = newNode;
            size++;
        }
        else {
            newNode->next = head;
            head = newNode;
            size++;
        }
    }

    int top() {
        if(head == NULL) {
            return -1;  // returning -1, when stack is empty
        }
        return head->data;
    }

    int pop() {
        if(head == NULL) {
            return -1;  // returning -1, when stack is empty
        }
        size --;
        Node *temp = head;
        head = head->next;
        int ans = temp->data;
        delete temp;
        return ans;
    }
};


int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.getSize() << endl;
    cout << s.isEmpty() << endl;
    return 0;
}