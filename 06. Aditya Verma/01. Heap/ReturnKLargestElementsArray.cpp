// Time Complexity = O(NlogK)
// Space Complexity = O(K)


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int>* returnKLargestElements(int *arr, int size, int k) {
    priority_queue <int, vector<int>, greater<int>> minHeap;
    for(int i=0; i<size; i++) {
        minHeap.push(arr[i]);
        if(minHeap.size() > k) {
            minHeap.pop();
        }
    }
    vector<int>* ans = new vector<int>;
    for(int i=0; i<k; i++) {
        ans->push_back(minHeap.top());
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
    vector<int>* ans = returnKLargestElements(arr, n, k);
    for(int i=0; i<ans->size(); i++) {
        cout << ans->at(i) << " ";
    }
    cout << endl;
    delete ans;
    return 0;
}