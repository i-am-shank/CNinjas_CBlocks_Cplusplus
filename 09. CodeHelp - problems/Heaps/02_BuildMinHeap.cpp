#include <bits/stdc++.h>
using namespace std;

// Minimum element at top
// root's value is lesser than it's both children
class minHeap {
	vector<int> arr;
	int size;

	void upHeapify(int index) {
		if(index <= 1) {
			return; // Already reached top position
		}
		if(index % 2 != 0) {
			// 1-more sibling present at same level
			int ele1=arr[index], ele2=arr[index-1];
		}
		int parentIndex = (index/2);
		if(arr[parentIndex] > arr[index]) {
			swap(arr[parentIndex], arr[index]);
			upHeapify(parentIndex);
		}
		else {
			return; // Reached correct position
		}
	}

	void downHeapify(int index) {
		if(index >= size) {
			return;
		}
		int childIdx1=(index*2), childIdx2=(index*2)+1;
		if(childIdx1<size && arr[index]>arr[childIdx1]) {
			swap(arr[index], arr[childIdx1]);
			downHeapify(childIdx1);
		}
		else if(childIdx2<size && arr[index]>arr[childIdx2]) {
			swap(arr[index], arr[childIdx2]);
			downHeapify(childIdx2);
		}
		else {
			// Reached at correct position.. <= both children
			// Or reached bottom level.. having no child
			return;
		}
	}

public:
	minHeap() {
		arr.push_back(-1); // for 1-indexing
		size = 0;
	}

	vector<int> getArr() {
		vector<int> ans;
		for(int i=1; i<=size; i++) {
			ans.push_back(arr[i]);
		}
		return ans;
	}

	void insert(int ele) {
		arr.push_back(ele);
		size++;
		upHeapify(size);
		return;
	}

	int top() {
		if(size == 0) {
			return -1; // Empty heap
		}
		int ans = arr[1];
		return ans;
	}

	void remove() {
		if(size == 0) {
			return; // Empty heap
		}
		swap(arr[1], arr[size]);
		arr.pop_back();
		size--; // Decrease size by 1.
		downHeapify(1); // Place element at index 0 at correct place
		return;
	}

	int getSize() {
		return size;
	}
};

vector<int> buildMinHeap(vector<int> &arr) {
    int n = arr.size();
    minHeap myHeap;
    for(int i=0; i<n; i++) {
    	myHeap.insert(arr[i]);
    }
    vector<int> ans = myHeap.getArr();
    return ans;
}

bool isMinHeap(vector<int>& arr) {
	int n = arr.size();
	for(int i=0; i<n; i++) {
		int idx = (i+1);
		int childIdx1=(2*idx), childIdx2=(2*idx)+1;
		bool check1=true, check2=true;
		if(childIdx1 <= n) {
			check1 = (arr[idx-1] <= arr[childIdx1-1]);
		}
		if(childIdx2 <= n) {
			check2 = (arr[idx-1] <= arr[childIdx2-1]);
		}
		if(check1==false || check2==false) {
			return false;
		}
	}
	return true;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> arr(n);
		for(int i=0; i<n; i++) {
			cin >> arr[i];
		}
		vector<int> ans = buildMinHeap(arr);
		for(int i=0; i<ans.size(); i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
		bool check = isMinHeap(ans);
		cout << check << endl;
	}
	return 0;
}