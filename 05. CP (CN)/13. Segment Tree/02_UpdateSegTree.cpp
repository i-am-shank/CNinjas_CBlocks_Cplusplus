#include <bits/stdc++.h>
using namespace std;

// Segment Tree Problem :
// --> Just analyse, what to store at each node
// --> All problems done. (just by above step)

void buildTree(int* arr, int* tree, int s, int e, int idx) {
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
void updateTree(int *arr, int *tree, int s, int e, int idx, int i, int val) {
	// Base case
	if(s == e) {
		arr[i] = val; // update in array
		// .. Not needed for queries
		tree[idx] = val;
		return;
	}
	int mid = s + ((e-s)>>1);
	if(i > mid) {
		// Go to right-segment
		updateTree(arr, tree, mid+1, e, (2*idx)+1, i, val);
	}
	else {
		// Go to left-segment
		updateTree(arr, tree, s, mid, (2*idx), i, val);
	}
	tree[idx] = (tree[(2*idx)] + tree[(2*idx)+1]);
	return;
}

int main() {
	int arr[5] = {1, 2, 3, 4, 5};
	// As nodes required = (2n-1)
	int* tree = new int[10];
	buildTree(arr, tree, 0, 4, 1);
	// Update 10 at index 2 of arr
	updateTree(arr, tree, 0, 4, 1, 2, 10);
	for(int i=1; i<10; i++) {
		cout << tree[i] << " ";
	}
	cout << "\n";
	return 0;
}