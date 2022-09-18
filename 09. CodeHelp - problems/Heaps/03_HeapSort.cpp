#include <bits/stdc++.h>
using namespace std;

class minHeap{
	vector<int> arr;
	int size;

	void upHeapify(int index) {
		if(index <= 1) {
			return; // Already at top
		}
		int parentIndex = (index/2);
		if(arr[parentIndex] > arr[index]) {
			swap(arr[parentIndex], arr[index]);
			upHeapify(parentIndex);
		}
		return;
	}

	void downHeapify(int index) {
		if(index >= size) {
			return; // Already at end
		}
		int childIdx1=(2*index), childIdx2=(2*index)+1;
		if(childIdx1<=size && arr[childIdx1] < arr[index]) {
			swap(arr[index], arr[childIdx1]);
			downHeapify(childIdx1);
		}
		else if(childIdx2<=size && arr[childIdx2] < arr[index]) {
			swap(arr[index], arr[childIdx2]);
			downHeapify(childIdx2);
		}
		else {
			return;
			// either at bottom or both child greater
		}
	}

public:
	minHeap() {
		arr.push_back(0);
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
		// Smallest element at end
		arr.pop_back(); // remove end
		size--;
		downHeapify(1); // place swapped element at correct size]
		return;
	}

	int top() {
		if(size == 0) {
			return -1; // Empty heap
		}
		return arr[1];
	}

	int getSize() {
		return size;
	}
};

vector<int> heapSort(vector<int>& arr) {
	minHeap h;
	int n = arr.size();
	vector<int> ans;
	for(int i=0; i<n; i++) {
		h.insert(arr[i]);
	}
	while(h.getSize() > 0) {
		ans.push_back(h.top());
		h.remove();
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	vector<int> ans = heapSort(arr);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}