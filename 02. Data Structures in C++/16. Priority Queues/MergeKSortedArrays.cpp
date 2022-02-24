#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Time Complexity = O(NlogN)
// Space Complexity = O(N)

vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
    priority_queue <int, vector<int>, greater<int>> minHeap;
    // ..
    for(int i=0; i<input.size(); i++) {
        for(int j=0; j<input.at(i)->size(); j++) {
            minHeap.push(input.at(i)->at(j));
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
    int k;
    cin >> k;
    vector<vector<int>*> input;
    for(int i=0; i<k; i++) {  // Input k sorted arrays.
        vector<int>* arr = new vector<int>;
        int n;
        cin >> n;
        for(int i=0; i<n; i++) {
            int ele;
            cin >> ele;
            arr->push_back(ele);
        }
        input.push_back(arr);
    }
    vector<int> ans = mergeKSortedArrays(input);
    for(int i=0; i<ans.size(); i++) {
        cout << ans.at(i) << " ";
    }
    cout << endl;
    for(int i=0; i<k; i++) {  // Delete dynamically allocated k-vectors
        delete input.at(i);
    }
    return 0;
}