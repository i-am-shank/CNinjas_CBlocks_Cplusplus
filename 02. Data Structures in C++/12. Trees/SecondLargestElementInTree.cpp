// Time Complexity = O(N)
// Space Complexity = O(N)


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode {
    public:
    T data;
    vector <TreeNode <int>*> children;

    TreeNode (int data) {
        this->data = data;
    }
};

template <typename T>
class secLarge {
    public:
    TreeNode <int>* largest;
    TreeNode <int>* secondLargest;

    secLarge(TreeNode <int>* largest, TreeNode <int>* secondLargest) {
        this->largest = largest;
        this->secondLargest = secondLargest;
    }
};

TreeNode <int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode <int>* root = new TreeNode <int> (rootData);
    queue <TreeNode <int>*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode <int>* front = q.front();
        q.pop();
        int numChild;
        cin >> numChild;
        for(int i=0; i<numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode <int>* child = new TreeNode <int> (childData);
            q.push(child);
            front->children.push_back(child);
        }
    }
    return root;
}

secLarge <int>* secondLargestHelper(TreeNode <int>* root) {
    if(root == NULL) {
        secLarge <int>* ans = new secLarge <int> (NULL, NULL);
        return ans;
    }
    secLarge <int>* ans = new secLarge <int> (root, NULL);
    for (int i=0; i<root->children.size(); i++) {
        secLarge <int>* childAns = secondLargestHelper(root->children[i]);
        if(childAns->largest->data > ans->largest->data) {
            if(childAns->secondLargest == NULL) {
                ans->secondLargest = ans->largest;
                ans->largest = childAns->largest;
            }
            else {
                if(childAns->secondLargest->data > ans->largest->data) {
                    ans = childAns;
                }
                else {
                    ans->secondLargest = ans->largest;
                    ans->largest = childAns->largest;
                }
            }
        }
        else if((ans->largest->data!=childAns->largest->data) && (childAns->largest!=NULL || childAns->largest->data > ans->secondLargest->data)) {
            ans->secondLargest = childAns->largest;
        }
    }
    return ans;
}

TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    return secondLargestHelper(root)->secondLargest;
}

int main() {
    TreeNode <int>* root = takeInputLevelWise();
    TreeNode <int>* ans = getSecondLargestNode(root);
    if(ans == NULL) {
        cout << endl;
    }
    else {
        cout << ans->data << endl;
    }
    return 0;
}