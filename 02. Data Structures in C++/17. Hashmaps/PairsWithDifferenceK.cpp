// Time Complexity = O(N)
// Space Complexity = O(N)


#include <iostream>
#include <unordered_map>
using namespace std;

int getPairsWithDifferenceK(int *arr, int n, int k) {
    unordered_map <int, int> ourmap;
    int count = 0;
    for(int i=0; i<n; i++) {
        count += ourmap[arr[i] + k];
        if(k != 0) {
            count += ourmap[arr[i] - k];
        }
        if(ourmap.find(arr[i]) != ourmap.end()) {
            ourmap[arr[i]] ++;
        }
        else {
            ourmap[arr[i]] = 1;
        }
    }
    return count;
}

int main() {
    int n, k;
    cin >> n;
    int *arr = new int[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cin >> k;
    int count = getPairsWithDifferenceK(arr, n, k);
    cout << count << endl;
    delete []arr;
    return 0;
}