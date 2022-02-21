#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public:
    T data;
    BinaryTreeNode <T>* left;
    BinaryTreeNode <T>* right;
    BinaryTreeNode (T data) {
        this->data = data;
        left = NULL;
        right = NULL;
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
    Node (T data) {
        this->data = data;
        next = NULL;
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
        BinaryTreeNode <int>* front= q.front();
        q.pop();
        int leftData, rightData;
        cin >> leftData;
        if(leftData != -1) {
            BinaryTreeNode <int>* leftNode = new BinaryTreeNode <int> (leftData);
            front->left = leftNode;
            q.push(leftNode);
        }
        cin >> rightData;
        if(rightData != -1){
            BinaryTreeNode <int>* rightNode = new BinaryTreeNode <int> (rightData);
            front->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

// Time Complexity = O(logN)
// Space Complexity = O(logN)

pair <Node<int>*, Node<int>*> constructLL(BinaryTreeNode <int>* root) {
    if(root == NULL) {
        pair<Node <int>* , Node <int>*> ans (NULL, NULL);
        return ans;
    }
    Node <int>* currNode = new Node<int> (root->data);
    pair <Node<int>*, Node<int>*> leftAns = constructLL(root->left);
    pair <Node<int>*, Node<int>*> rightAns = constructLL(root->right);
    Node <int>* head, *tail;
    if(leftAns.first != NULL) {
        leftAns.second->next = currNode;
        head = leftAns.first;
    }
    else {
        head = currNode;
    }
    if(rightAns.first != NULL) {
        currNode->next = rightAns.first;
        tail = rightAns.second;
    }
    else {
        tail = currNode;
    }
    pair <Node<int>*, Node<int>*> ans;
    ans.first = head;
    ans.second = tail;
    return ans;
}

Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
    return constructLL(root).first;
}

void printLL(Node<int>* head) {
    Node <int>* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    delete temp;
    return;
}

int main() {
    BinaryTreeNode <int>* root = takeInput();
    Node<int>* head = constructLinkedList(root);
    printLL(head);
    delete root;
    delete head;
    return 0;
}