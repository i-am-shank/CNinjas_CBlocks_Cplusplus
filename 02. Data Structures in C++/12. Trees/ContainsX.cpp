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
    TreeNode <int>* root = new TreeNode <int> (rootData);
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

bool isPresent(TreeNode<int>* root, int x) {
    if(root == NULL) {
        return false;
    }
    bool flag = false;
    if(root->data == x) {
        return true;
    }
    else {
        for (int i=0; i<root->children.size(); i++) {
            bool smallAns = isPresent(root->children[i] , x);
            if(smallAns == true) {
                flag = true;
                break;
            }
        }
    }
    return flag;
}

int main() {
    TreeNode <int>* root = takeInputLevelWise();
    int x;
    cin >> x;
    bool ans = isPresent(root, x);
    if(ans == true) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    return 0;
}