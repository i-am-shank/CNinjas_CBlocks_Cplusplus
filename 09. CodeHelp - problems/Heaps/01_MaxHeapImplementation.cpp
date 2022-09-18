#include <bits/stdc++.h>
using namespace std;

class maxHeap {
	vector<int> arr;
	int size;

public:
	maxHeap() { // Constructor
		arr.push_back(0);
		size = 0; // It points to last index too
	}

	void upHeapify(int index) {
		while(index > 1) {
			int parent = index/2;
			if(arr[parent] < arr[index]) {
				swap(arr[parent], arr[index]);
				index = parent;
			}
			else {
				return;
			}
		}
	}

	void downHeapify(int index) {
		while(index < size) {
			int leftIdx = (2*index);
			int rightIdx = (2*index)+1;
			if(leftIdx<size && arr[index]<arr[leftIdx]) {
				swap(arr[index], arr[leftIdx]);
				index = leftIdx;
			}
			else if(rightIdx<size && arr[index]<arr[rightIdx]) {
				swap(arr[index], arr[rightIdx]);
				index = rightIdx;
			}
			else {
				// Either both indexes are out of bounds .. index in last row
				// Or node is geater than it's both children
				return;
			}
		}
		return;
	}

	// Time : O(logn) .. in up-heapify
	void insert(int val) {
		size++;
		int index = size;
		arr.push_back(val); // Insert at last
		upHeapify(index); 
		// Will restore Heap order property of heap
		return;
	}

	// Time : O(logn) .. in down-heapify
	void remove() {
		if(size == 0) {
			return; // Empty heap
		}
		swap(arr[1], arr[size]); // Swapping root-node with last-node
		arr.pop_back(); // Remove last node
		size--; // Decrease size
		downHeapify(1); // Place root node to correct position
		// ..to maintain heap-order property
		return;
	}

	// Time : O(1)
	int top() {
		if(size == 0) {
			return -1;
		}
		return arr[1]; // Top element of CBT
	}

	// Time : O(n)
	void print() {
		for(int i=1; i<=size; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
		return;
	}
};

int main() {
	maxHeap h;
	h.insert(50);
	h.insert(55);
	h.insert(53);
	h.insert(52);
	h.insert(54);
	h.print();
	h.remove();
	h.print();
	cout << h.top() << endl;
	return 0;
}