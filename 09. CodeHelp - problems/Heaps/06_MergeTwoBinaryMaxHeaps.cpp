#include <bits/stdc++.h>
using namespace std;

class maxHeap{
	vector<int> arr;
	int size;

	void upHeapify(int index) {
		if(index <= 1) {
			return; // already reached top
		}
		int parentIndex = (index/2);
		if(arr[parentIndex] < arr[index]) {
			swap(arr[parentIndex], arr[index]);
			upHeapify(parentIndex);
		}
		else {
			return; // Reached at correct position
		}
	}

	void downHeapify(int index) {
		if(index >= size) {
			return; // already at bottom
		}
		int childIdx1=(2*index), childIdx2=(2*index)+1;
		if(childIdx1<=size && arr[childIdx1]>arr[index]) {
			swap(arr[index], arr[childIdx1]);
			downHeapify(childIdx1);
		}
		else if(childIdx2<=size && arr[childIdx2]>arr[index]) {
			swap(arr[index], arr[childIdx2]);
			downHeapify(childIdx2);
		}
		else {
			return; // reached correct position
		}
	}

public:
	maxHeap() {
		arr.push_back(0); // for 1-indexing
		size = 0;
	}

	void insert(int ele) {
		arr.push_back(ele);
		size++;
		upHeapify(size);
		return;
	}

	void remove() {
		if(size == 0) {
			return; // Empty heap
		}
		swap(arr[1], arr[size]);
		arr.pop_back();
		size--;
		downHeapify(arr[1]);
		return;
	}

	int top() {
		if(size == 0) {
			return -1; // Empty heap
		}
		int ans = arr[1];
		return ans;
	}

	int getSize() {
		return size;
	}

	vector<int> getArr() {
		vector<int> ans;
		for(int i=1; i<=size; i++) {
			ans.push_back(arr[i]);
		}
		return ans;
	}
};

class Solution{
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
    	maxHeap h;
    	for(int i=0; i<n; i++) {
    		h.insert(a[i]);
    	}
    	for(int i=0; i<m; i++) {
    		h.insert(b[i]);
    	}
    	vector<int> ans = h.getArr();
    	return ans;
    }
};

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	for(int i=0; i<m; i++) {
		cin >> b[i];
	}
	Solution solve;
	vector<int> ans = solve.mergeHeaps(a, b, n, m);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}