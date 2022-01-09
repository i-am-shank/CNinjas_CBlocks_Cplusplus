#include <iostream>
#include <vector>
#include <math.h>
#include <climits>
using namespace std;

// BRUTE-FORCE
// Time Complexity = O(a^N)
// Space Complexity = O(N^2) ..N-sized vector in each recursion, N values.. recursion

int minCount_bf(int n) {
    if(n <= 1) {
        return n;
    }
    vector<int> smallValues;
    for(int i=1; pow(i, 2) <= n ; i++) {
        int temp = n - pow(i,2);
        smallValues.push_back(temp);
    }
    int min = INT_MAX;
    for(int i=0; i<smallValues.size(); i++) {
        int temp = minCount_bf(smallValues[i]);
        if(temp < min) {
            min = temp;
        }
    }
    return min + 1;
}

// Memoization
// Time Complexity = O(NlogN)
// Space Complexity = O(N)

int minCount_mem_helper(int n, int *arr) {
    if(n <= 1) {
        arr[n] = n;
        return arr[n];
    }
    vector<int> smallValues;
    for(int i=1; pow(i,2)<=n; i++) {
        int temp = n - pow(i,2);
        smallValues.push_back(temp);
    }
    int min = INT_MAX;
    for(int i=0; i<smallValues.size(); i++) {
        int temp;
        if(arr[smallValues[i]] == -1) {
            arr[smallValues[i]] = minCount_mem_helper(smallValues[i], arr);
        }
        temp = arr[smallValues[i]];
        if(temp < min) {
            min = temp;
        }
    }
    return min+1;
}

int minCount_mem(int n) {
    int *arr = new int[n+1];
    for(int i=0; i<n+1; i++) {
        arr[i] = -1;
    }
    int ans = minCount_mem_helper(n, arr);
    delete []arr;
    return ans;
}

// DP
// Time Complexity = O(NlogN)
// Space Complexity = O(N)

int minCount(int n) {
    int *arr = new int[n+1];
    arr[0] = 0;
    arr[1] = 1;
    for(int i=2; i<n+1; i++) {
        int min = INT_MAX;
        for(int j=1; pow(j,2)<=i; j++) {
            int tempIndex = i - pow(j,2);
            int tempValue = arr[tempIndex];
            if(tempValue < min) {
                min = tempValue;
            }
        }
        arr[i] = min + 1;
    }
    return arr[n];
}

int main() {
    int n;
    cin >> n;
    int ans_bf = minCount_bf(n);
    int ans_mem = minCount_mem(n);
    int ans_dp = minCount(n);
    cout << "ans_bf : " << ans_bf << endl;
    cout << "ans_mem : " << ans_mem << endl;
    cout << "ans_dp : " << ans_dp << endl;
    return 0;
}