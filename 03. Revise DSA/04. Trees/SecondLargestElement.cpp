// Time Complexity = O(N)
// Space Complexity = O(N)
//     .. O(1) space waiting at each recursion call.


#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

template <typename T>
class TreeNode {
    public:
    T data;
    vector <TreeNode <int>*> children;
    TreeNode (T data) {
        this->data = data;
    }
    ~TreeNode () {
        for(int i=0; i<children.size(); i++) {
            delete children[i];
        }
    }
};

TreeNode <int>* takeInput() {
    int rootData;
    cin >> rootData;
    TreeNode <int>* root = new TreeNode <int> (rootData);
    queue <TreeNode <int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()) {
        TreeNode <int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for(int i=0; i<numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode <int>* child = new TreeNode <int> (childData);
            pendingNodes.push(child);
            front->children.push_back(child);
        }
    }
    return root;
}

template <typename T>
class secLarge {
    public:
    TreeNode <T>* largest;
    TreeNode <T>* secondLargest;
    secLarge(TreeNode <T>* largest, TreeNode <T>* secondLargest) {
        this->largest = largest;
        this->secondLargest = secondLargest;
    }
};

secLarge <int>* secondLargestHelp(TreeNode <int>* root) {
    if(root == NULL) {
        secLarge <int>* ans = new secLarge<int> (NULL, NULL);
        return ans;
    }
    secLarge <int>* ans = new secLarge <int> (root, NULL);
    for(int i=0; i<root->children.size(); i++) {
        secLarge <int>* temp = secondLargestHelp(root->children[i]);
        if(temp->largest->data > ans->largest->data) {
            if(temp->secondLargest == NULL) {
                ans->secondLargest = ans->largest;
                ans->largest = temp->largest;
            }
            else {
                if(temp->secondLargest->data > ans->largest->data) {
                    ans = temp;
                }
                else {
                    ans->secondLargest = ans->largest;
                    ans->largest = temp->largest;
                }
            }
        }
        else {
            if(  (temp->largest->data != ans->largest->data)  &&
                   ((ans->secondLargest == NULL)  ||  
                   (temp->largest->data > ans->secondLargest->data))  )   {
                ans->secondLargest = temp->largest;
            }
        }
    }
    return ans;
}

TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    return secondLargestHelp(root)->secondLargest;
}

int main() {
    TreeNode <int>* root = takeInput();
    TreeNode <int>* ans = getSecondLargestNode(root);
    if(ans != NULL) {
        cout << ans->data << endl;
    }
    delete root;
    return 0;
}