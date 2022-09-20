#include <bits/stdc++.h>
using namespace std;

// Time : O(N)
void buildTree(int* arr, int *tree, int s, int e, int idx) {
	if(s == e) {
		tree[idx] = arr[s];
		return;
	}
	int mid = s + ((e-s)>>1);
	buildTree(arr, tree, s, mid, (2*idx));
	buildTree(arr, tree, mid+1, e, (2*idx)+1);
	tree[idx] = (tree[(2*idx)] + tree[(2*idx)+1]);
	return;
}

// Time : O(logN)
int query(int* tree, int s, int e, int l, int r, int idx) {
	if(l>e || r<s) {
		// No overlap
		return 0; // As sum is required
	}
	else if(l<=s && r>=e) {
		return tree[idx];
	}
	else {
		int mid = s + ((e-s)>>1);
		int leftAns = query(tree, s, mid, l, r, (2*idx));
		int rightAns = query(tree, mid+1, e, l, r, (2*idx)+1);
		return (leftAns + rightAns);
	}
}

// Time : O(logN)
void updateTree(int *arr, int* tree, int s, int e, int idx, int i, int val) {
	if(s == e) {
		tree[idx] = val;
		arr[i] = val;
		return;
	}
	int mid = s + ((e-s)>>1);
	if(i > mid) {
		// Right call
		updateTree(arr, tree, mid+1, e, (2*idx)+1, i, val);
	}
	else {
		// Left call
		updateTree(arr, tree, s, mid, (2*idx), i, val);	
	}
	tree[idx] = (tree[(2*idx)] + tree[(2*idx)+1]);
	return;
}

int main() {
	int arr[5] = {1, 2, 3, 4, 5};
	int *tree = new int[10];
	buildTree(arr, tree, 0, 4, 1);
	updateTree(arr, tree, 0, 4, 1, 2, 10);
	for(int i=1; i<10; i++) {
		cout << tree[i] << " ";
	}
	cout << "\n";
	// Query & Update(if required)
	int ans = query(tree, 0, 4, 2, 4, 1);
	cout << ans << "\n";
	delete []tree;
	return 0;
}