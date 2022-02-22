//  1 2 3 4 5
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int minimiseCost(vector<int>* arr, int n) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int i=0; i<n; i++) {
        minHeap.push(arr->at(i));
    }
    int cost = 0;
    while(minHeap.size() > 1) {  // As rope-sizes are summed-up repeatedly, so to minimise cost
        int a = minHeap.top();  // First sum minimum sizes, so they get repeated, not max. ones
        minHeap.pop();
        int b = minHeap.top();
        minHeap.pop();
        cost += (a+b);
        minHeap.push(a+b);  // As summing 2 ropes become another rope. Push it also to Heap.
    }
    return cost;
}

int main() {
    int n;
    cin >> n;
    vector<int>* arr = new vector<int>;
    for(int i=0; i<n; i++) {
        int ele;
        cin >> ele;
        arr->push_back(ele);
    }
    int cost = minimiseCost(arr, n);
    cout << cost << endl;
    delete arr;
    return 0;
}