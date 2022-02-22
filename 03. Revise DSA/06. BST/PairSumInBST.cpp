#include <iostream>
#include <vector>
#include <queue>
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

BinaryTreeNode <int>* takeInput() {
    int rootData;
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode <int>* root = new BinaryTreeNode <int> (rootData);
    queue <BinaryTreeNode <int>* > q;
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
//     .. Conversion to arr is O(logN) , but checking sum equality is O(N).
// Space Complexity = O(N)

vector<int>* treeToArray(BinaryTreeNode <int>* root) {
    if(root == NULL) {
        vector<int>* v = new vector<int>;
        return v;
    }
    vector<int>* ans = new vector<int>;
    vector<int>* leftAns = treeToArray(root->left);
    vector<int>* rightAns = treeToArray(root->right);
    for(int i=0; i<leftAns->size(); i++) {
        ans->push_back(leftAns->at(i));
    }
    ans->push_back(root->data);
    for(int i=0; i<rightAns->size(); i++) {
        ans->push_back(rightAns->at(i));
    }
    delete leftAns;
    delete rightAns;
    return ans;
}

void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    vector<int>* arr = treeToArray(root);
    sort(arr->begin(), arr->end());
    int i=0, j=arr->size()-1;
    while(i<j) {
        if(arr->at(i) + arr->at(j) == s) {
            cout << arr->at(i) << " " << arr->at(j) << endl;
            i++;
            j--;
        }
        else if(arr->at(i) + arr->at(j) < s) {
            i++;
        }
        else {
            j--;
        }
    }
    delete arr;
    return;
}

int main() {
    BinaryTreeNode <int>* root = takeInput();
    int s;
    cin >> s;
    printNodesSumToS(root, s);
    delete root;
    return 0;
}