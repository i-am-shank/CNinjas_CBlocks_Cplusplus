#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Time Complexity = O(NlogK)
// Space Complexity = O(K)

vector<int> kLargest(int input[], int n, int k) {
    priority_queue <int, vector<int>, greater<int>> minHeap;
    for(int i=0; i<n; i++) {
        minHeap.push(input[i]);
        if(minHeap.size() > k) {
            minHeap.pop();
        }
    }
    vector<int> ans;
    while(!minHeap.empty()) {
        ans.push_back(minHeap.top());
        minHeap.pop();
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    vector<int> ans = kLargest(arr, n, k);
    for(int i=0; i<ans.size(); i++) {
        cout << ans.at(i) << endl;
    }
    delete arr;
    return 0;
}