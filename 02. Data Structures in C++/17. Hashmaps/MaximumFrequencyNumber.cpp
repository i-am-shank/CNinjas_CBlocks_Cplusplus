// Time Complexity = O(N)
// Space Complexity = O(N)


#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

int highestFrequency(int arr[], int n) {
    unordered_map<int, int> ourmap;
    for(int i=0; i<n; i++) {
        if(ourmap.count(arr[i]) > 0) {
            ourmap[arr[i]] ++;
        }
        else {
            ourmap[arr[i]] = 1;
        }
    }
    int highest_freq = ourmap.at(arr[0]), ans=arr[0];
    /*unordered_map <int, int> :: iterator it;    ..    This approach fails for 1 case.
    for (it=ourmap.begin(); it!=ourmap.end(); it++) {
        if(it->second > highest_freq) {
            ans = it->first;
            highest_freq = it->second;
        }
    }*/
    for (int i=0; i<n; i++) {
        if(ourmap[arr[i]] > highest_freq) {
            ans = arr[i];
            highest_freq = ourmap[arr[i]];
        }
    }
    return ans;
}

int main() {
    int size;
    cin >> size;
    int arr[size];
    for (int i=0; i<size; i++) {
        cin >> arr[i];
    }
    int ans = highestFrequency(arr, size);
    cout << ans << endl;
    return 0;
}