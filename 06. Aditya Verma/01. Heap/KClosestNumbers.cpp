#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int>* KClosestNumbers(vector<int>* arr, int n, int k, int x) {
    priority_queue <pair<int,int>> maxHeap;
    for(int i=0; i<n; i++) {
        int absV = abs(arr->at(i) - x);
        pair<int, int> ele (absV, arr->at(i));
        maxHeap.push(ele);
        if(maxHeap.size() > k) {
            maxHeap.pop();
        }
    }
    vector<int>* ans = new vector<int>;
    while(!maxHeap.empty()) {
        ans->push_back(maxHeap.top().second);  // 2nd is element, 1st is absolute diff.
        maxHeap.pop();
    }
    return ans;
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
    int k, x;
    cin >> k >> x;
    vector<int>* ans = KClosestNumbers(arr, n, k, x);
    for(int i=0; i<ans->size(); i++) {
        cout << ans->at(i) << " ";
    }
    cout << endl;
    delete arr;
    delete ans;
    return 0;
}