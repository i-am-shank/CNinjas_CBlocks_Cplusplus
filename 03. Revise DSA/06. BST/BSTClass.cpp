#include <iostream>
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

class BST {
    // Define the data members
    BinaryTreeNode <int>* root;

   public:
    BST() { 
        // Implement the Constructor
        this->root = NULL;
    }
    ~BST() {
        delete root;
    }

	/*----------------- Public Functions of BST -----------------*/

    private:
    BinaryTreeNode<int>* removeHelper(int data, BinaryTreeNode <int>* root) {
        if(root == NULL) {
            return root;
        }
        if(root->data == data) {
            if(root->left==NULL && root->right==NULL) {
                delete root;
                return NULL;
            }
            else if(root->left == NULL && root->right!=NULL) {
                BinaryTreeNode <int>* temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right == NULL && root->left!=NULL) {
                BinaryTreeNode <int>* temp = root->left;
                delete root;
                return temp;
            }
            else {  // both left & right are not-NULL.
                // Swap root->data & rightMin->data.
                // Recursion call ..delete root->data from root->right
                BinaryTreeNode <int>* rightMin = root->right;
                while(rightMin->left != NULL) {
                    rightMin = rightMin->left;
                }
                int rightMinData = rightMin->data;
                root->data = rightMinData;
                root->right = removeHelper(rightMinData, root->right);
                return root;
            }
        }
        else if(root->data > data) {
            return removeHelper(data, root->left);
        }
        else {
            return removeHelper(data, root->right);
        }
    }

    public:
    void remove(int data) { 
        // Implement the remove() function
        root = removeHelper(data, root);
        return;
    }

    private:
    void printHelper(BinaryTreeNode <int>* root) {
        if(root == NULL) {
            return;
        }
        cout << root->data << ":";
        if(root->left != NULL) {
            cout << "L:" << root->left->data << ",";
        }
        if(root->right != NULL) {
            cout << "R:" << root->right->data;
        }
        cout << endl;
        // Recursion call
        printHelper(root->left);
        printHelper(root->right);
    }

    public:
    void print() { 
        // Implement the print() function
        printHelper(root);
    }

    private:
    BinaryTreeNode <int>* insertHelper(int data, BinaryTreeNode <int>* root) {
        if(root == NULL) {
            BinaryTreeNode <int>* currNode = new BinaryTreeNode <int> (data);
            return currNode;
        }
        if(root->data >= data) {
            root->left = insertHelper(data, root->left);
        }
        else {
            root->right = insertHelper(data, root->right);
        }
        return root;
    }

    public:
    void insert(int data) { 
        // Implement the insert() function 
        this->root = insertHelper(data, root);
        return;
    }

    private:
    bool searchHelper(int data, BinaryTreeNode<int>* root) {
        if(root == NULL) {
            return false;
        }
        if(root->data == data) {
            return true;
        }
        else if(root->data > data) {
            return searchHelper(data, root->left);
        }
        else {
            return searchHelper(data, root->right);
        }
    }

    public:
    bool search(int data) {
		// Implement the search() function 
        return searchHelper(data, root);
    }
};

int main() {
    BST *tree = new BST();
    int t, input, choice;
    cin >> t;
    // 1 3 1 7 1 9 1 1 1 8 1 2 1 5 2 7 2 2 3 3 3 4 4
    while(t--) {
        cin >> choice;
        switch(choice) {
            case 1:
                //insert
                cin >> input;
                tree->insert(input);
                break;
            case 2:
                //remove
                cin >> input;
                tree->remove(input);
                break;
            case 3:
                //search
                cin >> input;
                cout << (tree->search(input) == true ? "true" : "false") << endl;
                break;
            default:
                //print
                tree->print();
                break;
        }
    }
    return 0;
}