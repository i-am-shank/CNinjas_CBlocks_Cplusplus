#include <iostream>
#include <queue>
using namespace std;

int kthSmallest(int *arr, int n, int k) {
    priority_queue<int> maxHeap;
    for(int i=0; i<n; i++) {
        maxHeap.push(arr[i]);
        if(maxHeap.size() > k) {
            maxHeap.pop();
        }
    }
    int ans = maxHeap.top();
    return ans;
}

int sumBetweenk1k2SmallestNo(int *arr, int n, int k1, int k2) {  // k1 <= k2
    int k1Smallest = kthSmallest(arr, n, k1);
    int k2Smallest = kthSmallest(arr, n, k2);
    int sum = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] > k1Smallest  &&  arr[i] < k2Smallest) {
            sum += arr[i];
        }
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int k1, k2;
    cin >> k1 >> k2;
    int minV = min(k1, k2);
    int maxV = max(k1, k2);
    int sum = sumBetweenk1k2SmallestNo(arr, n, minV, maxV);
    cout << sum << endl;
    delete arr;
    return 0;
}