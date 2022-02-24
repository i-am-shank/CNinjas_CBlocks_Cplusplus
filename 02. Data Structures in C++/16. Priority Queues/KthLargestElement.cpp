#include <iostream>
#include <queue>
using namespace std;

// Time Complexity = O(NlogK)
// Space Complexity = O(K)

int kthLargest(int* arr, int n, int k) {
    priority_queue <int, vector<int>, greater<int>> minHeap;
    for(int i=0; i<n; i++) {
        minHeap.push(arr[i]);
        if(minHeap.size() > k) {
            minHeap.pop();
        }
    }
    int ans = minHeap.top();
    return ans;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int [n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    int ans = kthLargest(arr, n, k);
    cout << ans << endl;
    delete arr;
    return 0;
}