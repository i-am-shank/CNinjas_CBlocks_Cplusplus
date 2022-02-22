#include <iostream>
#include <queue>
using namespace std;

void sortKSortedArray(int *arr, int n, int k) {
    priority_queue <int, vector<int>, greater<int>> minHeap;
    int sortI = 0;  // Array sorted till (sortI-1) index.
    for(int i=0; i<n; i++) {
        minHeap.push(arr[i]);
        if(minHeap.size() > k) {
            arr[sortI] = minHeap.top();
            minHeap.pop();
            sortI++;
        }
    }
    while(!minHeap.empty()) {
        arr[sortI] = minHeap.top();
        minHeap.pop();
        sortI++;
    }
    return;
}

int main() {
    int n;
    cin >> n;
    //  7    6 5 3 2 8 10 9    3
    int *arr = new int[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    sortKSortedArray(arr, n, k);
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete arr;
    return 0;
}