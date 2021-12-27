#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public:
    T data;
    BinaryTreeNode <T>* left;
    BinaryTreeNode <T>* right;

    BinaryTreeNode (int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    ~BinaryTreeNode () {
        delete left;
        delete right;
    }
};

template <typename T>
class Node {
    public:
    T data;
    Node <T>* next;

    Node (int data) {
        this->data = data;
        this->next = NULL;
    }
    ~Node () {
        delete next;
    }
};

BinaryTreeNode <int>* takeInput() {
    int rootData;
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode <int>* root = new BinaryTreeNode <int> (rootData);
    queue <BinaryTreeNode <int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode <int>* front = q.front();
        q.pop();
        int leftData, rightData;
        cin >> leftData;
        if(leftData != -1) {
            BinaryTreeNode <int>* leftNode = new BinaryTreeNode <int> (leftData);
            q.push(leftNode);
            front->left = leftNode;
        }
        cin >> rightData;
        if(rightData != -1) {
            BinaryTreeNode <int>* rightNode = new BinaryTreeNode <int> (rightData);
            q.push(rightNode);
            front->right = rightNode;
        }
    }
    return root;
}

void printLL(Node <int>* head) {
    Node <int>* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return;
}

// Time Complexity = O(N^2)
// Space Complexity = O(N)

Node<int>* constructLL(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        return NULL;
    }
    Node<int>* leftLL = constructLL(root->left);
    Node<int>* rightLL = constructLL(root->right);
    Node<int>* curr = new Node<int> (root->data);
    if(leftLL != NULL) {
        Node<int>* temp = leftLL;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = curr;
        curr->next = rightLL;
        return leftLL;
    }
    curr->next = rightLL;
    return curr;
}

// Time Complexity = O(N)
// Space Complexity = O(N)

class Pair {
    public:
    Node <int>* head;
    Node <int>* tail;
};

Pair constructLLHelper(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        Pair ans;
        ans.head = NULL;
        ans.tail = NULL;
        return ans;
    }
    Pair leftLL = constructLLHelper(root->left);
    Pair rightLL = constructLLHelper(root->right);
    Node<int>* curr = new Node<int> (root->data);
    Pair ans;
    if(leftLL.tail != NULL) {
        leftLL.tail->next = curr;
    }
    curr->next = rightLL.head;
    if(leftLL.head != NULL) {
        ans.head = leftLL.head;
    }
    else {
        ans.head = curr;
    }
    if(rightLL.tail != NULL) {
        ans.tail = rightLL.tail;
    }
    else {
        ans.tail = curr;
    }
    return ans;
}

Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
    return constructLLHelper(root).head;
}

int main() {
    BinaryTreeNode <int>* root = takeInput();
    Node <int>* head = constructLinkedList(root);
    printLL(head);
    delete root;
    delete head;
    return 0;
}