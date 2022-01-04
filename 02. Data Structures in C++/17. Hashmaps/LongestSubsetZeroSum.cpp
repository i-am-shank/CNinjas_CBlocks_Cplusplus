// Time Complexity = O(N)
// Space Complexity = O(N)


#include <iostream>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    unordered_map <int, int> ourmap;  // Value = sum , Keys = index
    int maxLength = 0;
    int sum = 0;
    ourmap[0] = -1;  // Inserting Base case value.  ..   ZERO sum at start of array.
    for(int i=0; i<n; i++) {
        sum += arr[i];
        if(ourmap.find(sum) != ourmap.end()) {  // same sum-value was found previously,
            int l = i - ourmap[sum];  // means, the subset in between sums to ZERO.
            if(l > maxLength) {
                maxLength = l;
            }
        }
        else {
            ourmap[sum] = i;  // Storing the index, where sum-values were found first
        }
    }
    return maxLength;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int length = lengthOfLongestSubsetWithZeroSum(arr, n);
    cout << length << endl;
    delete []arr;
    return 0;
}