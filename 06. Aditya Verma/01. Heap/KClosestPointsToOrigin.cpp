// (1,3) , (-2,2) , (5,8) , (0,1)
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

vector<pair<int,int>>* KClosestPointsToOrigin(vector<pair<int,int>>* arr, int n, int k) {
    priority_queue<pair<int,pair<int,int>>> maxHeap;
    for(int i=0; i<n; i++) {
        int dist = pow((arr->at(i).first) , 2) + pow((arr->at(i).second) , 2); // distance from origin
        pair<int,pair<int,int>> element (dist, arr->at(i));
        maxHeap.push(element);
        if(maxHeap.size() > k) {
            maxHeap.pop();
        }
    }
    vector<pair<int,int>>* ans = new vector<pair<int,int>>;
    while(!maxHeap.empty()) {
        ans->push_back(maxHeap.top().second);
        maxHeap.pop();
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> *arr = new vector<pair<int,int>> ;
    for(int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        pair<int,int> point (x, y);
        arr->push_back(point);
    }
    int k;
    cin >> k;
    vector<pair<int,int>> *ans = KClosestPointsToOrigin(arr, n, k);
    for(int i=0; i<ans->size(); i++) {
        cout << ans->at(i).first << " " << ans->at(i).second << endl;
    }
    delete arr;
    delete ans;
    return 0;
}