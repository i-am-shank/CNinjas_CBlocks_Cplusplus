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

TreeNode <int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode <int>* root = new TreeNode <int>(rootData);
    queue <TreeNode <int>*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode <int>* front = q.front();
        q.pop();
        int numChild;
        cin >> numChild;
        for (int i=0; i<numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode <int>* child = new TreeNode <int> (childData);
            q.push(child);
            front->children.push_back(child);
        }
    }
    return root;
}

bool areIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    if(root1==NULL && root2==NULL) {
        return true;
    }
    if(root1==NULL || root2==NULL) {
        return false;
    }
    if(root1->data == root2->data) {
        if(root1->children.size() == root2->children.size()) {
            bool flag = true;
            for (int i=0; i<root1->children.size(); i++) {
                bool smallAns = areIdentical(root1->children[i], root2->children[i]);
                if(smallAns == false) {
                    flag = false;
                    break;
                }
            }
            return flag;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

int main() {
    TreeNode <int>* root1 = takeInputLevelWise();
    TreeNode <int>* root2 = takeInputLevelWise();
    bool ans = areIdentical(root1, root2);
    if(ans == true) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    return 0;
}