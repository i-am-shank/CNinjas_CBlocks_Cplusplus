#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode {
public:
	T data;
	vector<TreeNode <T>*> children;
	TreeNode (T data) {
		this->data = data;
	}
	~TreeNode () {
		for(int i=0; i<this->children.size(); i++) {
			delete children[i];
		}
	}
};

TreeNode <int>* takeInputLevelWise() {
	int rootData;
	cin >> rootData;
	TreeNode <int>* root = new TreeNode <int> (rootData);
	queue<TreeNode <int>*> q;
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
			front->children.push_back(child);
			q.push(child);
		}
	}
	return root;
}

template <typename T>
class secLarge {
public:
	TreeNode <T>* largest;
	TreeNode <T>* secondLargest;
	secLarge(TreeNode <T>* l, TreeNode <T>* sl) {
		largest = l;
		secondLargest = sl;
	}
};

secLarge<int>* secondLargestHelp(TreeNode<int>* root) {
	if(root == NULL) {
		secLarge<int>* ans = new secLarge<int> (NULL, NULL);
		return ans;
	}
	secLarge<int>* ans = new secLarge<int> (root, NULL);
	for(int i=0; i<root->children.size(); i++) {
		secLarge<int>* smallAns = secondLargestHelp(root->children[i]);
		if(smallAns->largest->data > ans->largest->data) {
			if(smallAns->secondLargest == NULL) {
				ans->secondLargest = ans->largest;
				ans->largest = smallAns->largest;
			}
			else {
				if(smallAns->secondLargest->data > ans->largest->data) {
					ans = smallAns;
				}
				else {
					ans->secondLargest = ans->largest;
					ans->largest = smallAns->largest;
				}
			}
		}
		else if ((smallAns->largest->data != ans->largest->data)  &&
			(ans->secondLargest == NULL  ||  smallAns->largest->data > ans->secondLargest->data)) {
				ans->secondLargest = smallAns->largest;
		}
	}
	return ans;
}

TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
	return secondLargestHelp(root)->secondLargest;
}

int main() {
	TreeNode <int>* root = takeInputLevelWise();
	TreeNode <int>* ans = getSecondLargestNode(root);
	if(ans != NULL) {
		cout << ans->data << endl;
	}
	delete root;
	return 0;
}