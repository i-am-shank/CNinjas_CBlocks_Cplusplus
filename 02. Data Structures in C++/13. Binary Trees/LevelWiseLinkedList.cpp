// Time Complexity = O(N)
// Space Complexity = O(N)


#include <iostream>
#include <queue>
#include <vector>
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

vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    vector<Node <int>*> arr;
    if(root == NULL) {
        return arr;
    }
    Node<int>* head = NULL;
    Node<int>* tail = NULL;
    queue <BinaryTreeNode <int>*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        BinaryTreeNode <int>* front = q.front();
        q.pop();
        if(front != NULL) {
            Node <int>* newNode = new Node <int> (front->data);
            if(head == NULL) {
                head = newNode;
                tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = tail->next;
            }
        }
        else {    // front == NULL
            arr.push_back(head);
            head = NULL;
            tail = NULL;
            if(q.empty()) {
                break;
            }
            else {
                q.push(NULL);
                continue;
            }
        }
        if(front->left != NULL) {
            q.push(front->left);
        }
        if(front->right != NULL) {
            q.push(front->right);
        }
    }
    return arr;
}

void printLinkedList(vector<Node<int>*> arr) {
    for (int i=0; i<arr.size(); i++) {
        Node <int>* head = arr[i];
        Node <int>* temp = head;
        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    return;
}

int main() {
    BinaryTreeNode <int>* root = takeInput();
    vector<Node<int>*> arr = constructLinkedListForEachLevel(root);
    printLinkedList(arr);
    delete root;
    for (int i=0; i<arr.size(); i++) {
        delete arr[i];
    }
    return 0;
}