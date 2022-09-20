#include <bits/stdc++.h>
using namespace std;

// Time : O(n) .. As iterate on each node
// No. of nodes = (2n-1)
//     Leaf nodes = (n)
//     Non-leaf nodes = (n-1)
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

int main() {
	int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int* tree = new int[18];
	buildTree(arr, tree, 0, 8, 1);
	for(int i=1; i<18; i++) {
		cout << tree[i] << " ";
	}
	cout << "\n";
	return 0;
}