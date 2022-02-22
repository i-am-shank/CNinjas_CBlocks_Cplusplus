#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int>* frequencySort(vector<int>* arr, int n) {
    unordered_map<int, int> map;
    for(int i=0; i<n; i++) {
        if(map.find(arr->at(i)) == map.end()) {
            map[arr->at(i)] = 1;
        }
        else {
            map[arr->at(i)] ++;
        }
    }
    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
    unordered_map<int, int> :: iterator it;
    for(it=map.begin(); it!=map.end(); it++) {
        int val = it->first;
        int freq = it->second;
        pair<int,int> ele (freq, val);
        minHeap.push(ele);
    }
    vector<int>* ans = new vector<int>;
    while(!minHeap.empty()) {
        int freq = minHeap.top().first;
        int val = minHeap.top().second;
        for(int i=0; i<freq; i++) {
            ans->push_back(val);
        }
        minHeap.pop();
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
    vector<int>* ans = frequencySort(arr, n);
    for(int i=0; i<ans->size(); i++) {
        cout << ans->at(i) << " ";
    }
    cout << endl;
    delete arr;
    delete ans;
    return 0;
}