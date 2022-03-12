class Pair {
    public:
    TreeNode<int>* largest;
    TreeNode<int>* secondLargest;
};

Pair getSecondLargestNodeHelper(TreeNode<int>* root) {
    Pair ans;
    ans.largest=root;
    ans.secondLargest=NULL;
    for(int i=0;i<root->children.size();i++) {
        Pair curr=getSecondLargestNodeHelper(root->children[i]);
        if((ans.largest->data)<(curr.largest->data)) {
            if(curr.secondLargest==NULL) {
                ans.secondLargest=ans.largest;
                ans.largest=curr.largest;
            }
            else if((curr.secondLargest->data)>(ans.largest->data)) {
                ans.secondLargest=curr.secondLargest;
                ans.largest=curr.largest;
            }
            else if((curr.secondLargest->data)<(ans.largest->data)) {
                ans.secondLargest=ans.largest;
                ans.largest=curr.largest;
            }
        }
        else if((ans.largest->data)>=(curr.largest->data)) {
            if(curr.largest->data==ans.largest->data) {
                if(ans.secondLarget == NULL) {
                    ans.secondLargest = curr.secondLargest;
                }
                if(curr.secondLargest==NULL) {
                    return ans;
                }
                else if(curr.secondLargest->data>ans.secondLargest->data) {
                    ans.secondLargest=curr.secondLargest;
                }
            }
            else {
                if(ans.secondLarget == NULL) {
                    ans.secondLargest = curr.secondLargest;
                }
                else if(curr.largest->data>ans.secondLargest->data) {
                    ans.secondLargest=curr.largest;
                }
                else {
                    return ans;
                }
            }
        }
    }
    return ans;
}

TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    // Write your code here
    if(root==NULL) {
        return root;
    }
    return getSecondLargestNodeHelper(root).secondLargest;
}