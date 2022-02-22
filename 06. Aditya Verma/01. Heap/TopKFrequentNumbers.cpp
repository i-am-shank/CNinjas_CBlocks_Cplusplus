#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int>* topKFrequentNumbers(vector<int>* arr, int n, int k) {
    unordered_map<int, int> map;
    for(int i=0; i<n; i++) {  //  Storing frequency of each value ..in a map
        if(map.find(arr->at(i)) == map.end()) {  // arr->at(i) not present in map
            map[arr->at(i)] = 1;
        }
        else {
            map[arr->at(i)] ++;
        }
    }
    unordered_map<int, int> :: iterator it;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
    for(it = map.begin(); it!=map.end(); it++) {
        int val = it->first;
        int freq = it->second;
        pair<int, int> ele (freq, val);  // sort based on freq.. so put it in pair.first
        minHeap.push(ele);
        if(minHeap.size() > k) {  // Minimum popped out, storing higher frequent no.
            minHeap.pop();
        }
    }
    vector<int>* ans = new vector<int>;
    while(!minHeap.empty()) {
        ans->push_back(minHeap.top().second);  // second is element.. Return them as ans
        minHeap.pop();
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int>* arr = new vector<int> ;
    for(int i=0; i<n; i++) {
        int ele;
        cin >> ele;
        arr->push_back(ele);
    }
    int k;
    cin >> k;
    vector<int>* ans = topKFrequentNumbers(arr, n, k);
    for(int i=0; i<ans->size(); i++) {
        cout << ans->at(i) << " ";
    }
    cout << endl;
    delete ans;
    delete arr;
    return 0;
}