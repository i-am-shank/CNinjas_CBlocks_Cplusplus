#include <iostream>
#include <vector>
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
        BinaryTreeNode <int>* front = q.front();
        q.pop();
        int leftData, rightData;
        cin >> leftData;
        if(leftData != -1) {
            BinaryTreeNode <int>* leftNode = new BinaryTreeNode <int> (leftData);
            front->left = leftNode;
            q.push(leftNode);
        }
        cin >> rightData;
        if(rightData != -1) {
            BinaryTreeNode <int>* rightNode = new BinaryTreeNode <int> (rightData);
            front->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

// Time Complexity = O(N)
// Space Complexity = O(2 ^ logN)

vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    if(root == NULL) {
        vector<Node<int>*> v;
        return v;
    }
    vector<Node<int>*> ans;
    Node<int>* head = NULL, *tail = NULL;
    queue<BinaryTreeNode <int>*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        BinaryTreeNode <int>* front = q.front();
        q.pop();
        if(front == NULL) {
            ans.push_back(head);
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
        Node<int>* currNode = new Node <int> (front->data);
        // Update linked list
        if(head == NULL) {
            head = currNode;
            tail = currNode;
        }
        else {
            tail->next = currNode;
            tail = tail->next;
        }
        // Update queue
        if(front->left != NULL) {
            q.push(front->left);
        }
        if(front->right != NULL) {
            q.push(front->right);
        }
    }
    return ans;
}

int main() {
    BinaryTreeNode <int>* root = takeInput();
    vector<Node<int>*> ans = constructLinkedListForEachLevel(root);
    for(int i=0; i<ans.size(); i++) {
        Node <int>* head = ans[i];
        Node <int>* temp = head;
        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    delete root;
    for(int i=0; i<ans.size(); i++) {
        delete ans[i];
    }
    return 0;
}