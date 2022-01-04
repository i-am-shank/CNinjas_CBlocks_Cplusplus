// Time Complexity = O(N)
// Space Complexity = O(N)


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    if(n == 0) {    // Edge case
        vector<int> v;
        v.push_back(0);
        return v;
    }
    unordered_map <int, bool> ourmap;
    unordered_map <int, int> elementIndexMap;
    for(int i=0; i<n; i++) {    // hashmap formed
        if(ourmap.find(arr[i]) != ourmap.end()) {
            continue;
        }
        else {
            ourmap[arr[i]] = true;
            elementIndexMap[arr[i]] = i;
        }
    }
    unordered_map <int, bool> :: iterator it = ourmap.begin();
    int start = it->first, end = it->first, max = 1;
    while(it != ourmap.end()) {
        if(it->second == false) {
            it++;
        }
        else {
            int s = it->first , e = it->first+1, m=0;
            while(ourmap.find(s) != ourmap.end()) {
                ourmap[s] = false;
                m++;
                s--;
            }
            while(ourmap.find(e) != ourmap.end()) {
                ourmap[e] = false;
                m++;
                e++;
            }
            s = s+1;
            e = e-1;
            if(m > max) {
                start = s;
                end = e;
                max = m;
            }
            else {  // If sequence of same length, returning which starts first.
                if(m == max) {
                    if(elementIndexMap[s] < elementIndexMap[start]) {
                        start = s;
                        end = e;
                        max = m;
                    }
                }
            }
            it++;
        }
    }
    vector<int> ans;
    ans.push_back(start);
    if(start != end) {    // Edge case
        ans.push_back(end);
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
    vector<int> ans = longestConsecutiveIncreasingSequence(arr, n);
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    delete []arr;
    return 0;
}