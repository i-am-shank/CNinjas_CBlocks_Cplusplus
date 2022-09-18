#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        priority_queue<int> maxHeap;
        for(int i=l; i<=r; i++) {
            maxHeap.push(arr[i]);
            if(maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        int ans = maxHeap.top();
        return ans;
    }
};
 
int main() {
    Solution solve;
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int arr[100000];
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
        int ans = solve.kthSmallest(arr, 0, n-1, k);
        cout << ans << endl;
    }
    return 0;
}