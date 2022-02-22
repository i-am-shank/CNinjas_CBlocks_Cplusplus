// Time Complexity = O(NlogK)
// Space Complexity = O(K)


#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    int *arr = new int [n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    priority_queue <int> maxHeap;
    for(int i=0; i<n; i++) {
        maxHeap.push(arr[i]);
        if(maxHeap.size() > k) {
            maxHeap.pop();
        }
    }
    int ans = maxHeap.top();
    cout << ans << endl;
    return 0;
}