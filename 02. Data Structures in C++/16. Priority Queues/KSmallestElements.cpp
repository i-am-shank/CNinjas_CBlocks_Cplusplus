#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

// Time Complexity = O(NlogK)
// Space Complexity = O(K)

vector<int> kSmallest(int arr[], int n, int k) {
    priority_queue<int> maxHeap;
    for(int i=0; i<n; i++) {
        maxHeap.push(arr[i]);
        if(maxHeap.size() > k) {
            maxHeap.pop();
        }
    }
    vector<int> ans;
    stack<int> temp;
    while(!maxHeap.empty()) {  // Max element stored at top.. Elements popped out in decreasing order.
        temp.push(maxHeap.top());
        maxHeap.pop();
    }
    while(!temp.empty()) {  // Used stack just to reverse the order ..return elements in increasing order
        ans.push_back(temp.top());
        temp.pop();
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    vector<int> ans = kSmallest(arr, n, k);
    for(int i=0; i<ans.size(); i++) {
        cout << ans.at(i) << " ";
    }
    cout << endl;
    delete arr;
    return 0;
}