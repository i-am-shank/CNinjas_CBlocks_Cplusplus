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

    BinaryTreeNode (int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    ~BinaryTreeNode() {
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
    BinaryTreeNode <int>* root = new BinaryTreeNode<int> (rootData);
    queue<BinaryTreeNode<int>* > q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int>* front = q.front();
        q.pop();
        int leftData, rightData;
        cin >> leftData;
        if(leftData != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int> (leftData);
            q.push(leftNode);
            front->left = leftNode;
        }
        cin >> rightData;
        if(rightData != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int> (rightData);
            q.push(rightNode);
            front->right = rightNode;
        }
    }
    return root;
}

vector<int>* convertTreeToArray(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        vector<int>* ans = new vector <int>;
        return ans;
    }
    vector<int>* ans = new vector<int> ;
    ans->push_back(root->data);
    vector<int>* leftArray = convertTreeToArray(root->left);
    for(int i=0; i<leftArray->size(); i++) {
        ans->push_back(leftArray->at(i));
    }
    vector<int>* rightArray = convertTreeToArray(root->right);
    for(int i=0; i<rightArray->size(); i++) {
        ans->push_back(rightArray->at(i));
    }
    return ans;
}

void merge(vector<int>* v, int s, int m, int e) {
    vector<int>* ans = new vector <int> ;
    int i=s, j=m+1;
    while(i<=m && j<=e) {
        if(v->at(i) <= v->at(j)) {
            ans->push_back(v->at(i));
            i++;
        }
        else {
            ans->push_back(v->at(j));
            j++;
        }
    }
    while(i <= m) {
        ans->push_back(v->at(i));
        i++;
    }
    while(j <= e) {
        ans->push_back(v->at(j));
        j++;
    }
    for(int k=s; k<=e; k++) {
        v->at(k) = ans->at(k);
    }
    return;
}

void mergeSort(vector<int>* v, int start, int end) {
    if(start < end) {
        int mid = (start + end) / 2;
        mergeSort(v, start, mid);
        mergeSort(v, mid+1, end);
        merge(v, start, mid, end);
    }
}

// Time Complexity = O(NlogN)
// Space Complexity = O(N)

void pairSum(BinaryTreeNode<int> *root, int sum) {
    if(root == NULL) {
        return;
    }
    vector<int>* arr = convertTreeToArray(root);
    //mergeSort(arr, 0, arr->size()-1);
    sort(arr->begin(), arr->end());
    int i=0, j=arr->size()-1;
    while(i<j) {
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