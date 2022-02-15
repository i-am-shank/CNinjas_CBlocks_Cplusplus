// Time Complexity = O(N)
// Space Complexity = O(N)


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int maxProfit = 0, minV = arr[0];
    for(int i=0; i<n; i++) {
        if(arr[i] < minV) {
            minV = arr[i];
        }
        int profit = arr[i] - minV;
        if(profit > maxProfit) {
            maxProfit = profit;
        }
    }
    cout << maxProfit << endl;
    delete []arr;
    return 0;
}