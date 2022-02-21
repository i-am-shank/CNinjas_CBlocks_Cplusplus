#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
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

// Time Complexity = O(N logN)
// Space Complexity = O(N)

vector<int>* treeToArray(BinaryTreeNode <int>* root) {
    vector<int>* ans = new vector<int>;
    if(root == NULL) {
        return ans;
    }
    vector<int>* leftAns = treeToArray(root->left);
    leftAns->push_back(root->data);
    vector<int>* rightAns = treeToArray(root->right);
    for(int i=0; i<rightAns->size(); i++) {
        leftAns->push_back(rightAns->at(i));
    }
    return leftAns;
}

void pairSum(BinaryTreeNode<int> *root, int sum) {
    if(root == NULL) {
        return;
    }
    vector<int> *arr = treeToArray(root);
    sort(arr->begin(), arr->end());
    int i=0; 
    int j=(arr->size())-1;
    while(i < j) {
        if(arr->at(i) + arr->at(j) == sum) {
            cout << arr->at(i) << " " << arr->at(j) << endl;
            i++;
            j--;
        }
        else if(arr->at(i) + arr->at(j) < sum) {
            i++;
        }
        else {
            j--;
        }
    }
    return;
}

int main() {
    BinaryTreeNode <int>* root = takeInput();
    int sum;
    cin >> sum;
    pairSum(root, sum);
    delete root;
    return 0;
}