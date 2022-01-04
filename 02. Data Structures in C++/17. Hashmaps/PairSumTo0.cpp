// Time Complexity = O(N)
// Space Complexity = O(N)


#include <iostream>
#include <unordered_map>
using namespace std;

int pairSum(int *arr, int n) {
    unordered_map<int , int> ourmap;
    int num = 0;
    for(int i=0; i<n; i++) {
        int complement = -arr[i];
        if(ourmap.count(complement) > 0) {
            num += ourmap.at(complement);
        }
        ourmap[arr[i]]++;
    }
    return num;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int ans = pairSum(arr, n);
    cout << ans << endl;
    return 0;
}