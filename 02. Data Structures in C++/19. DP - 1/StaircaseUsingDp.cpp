#include <iostream>
using namespace std;

// BRUTE-FORCE method
// Time Complexity = (3^N)
// Space complexity = O(N)

long staircase_bf(int n) {
    if(n <= 2 && n >= 0) {
        return n;
    }
    if(n == 3) {
        return 4;
    }
    int ans = staircase_bf(n-1) + staircase_bf(n-2) + staircase_bf(n-3);
    return ans;
}

// MEMOIZATION
// Time Complexity = O(N)
// Space Complexity = O(N)

long staircase_mem_helper(int n, long* arr) {
    if(n<=2 && n>=0) {
        arr[n] = n;
        return n;
    }
    if(n == 3) {
        arr[n] = 4;
        return arr[n];
    }
    if(arr[n-1] == -1) {
        arr[n-1] = staircase_mem_helper(n-1, arr);
    }
    if(arr[n-2] == -1) {
        arr[n-2] = staircase_mem_helper(n-2, arr);
    }
    if(arr[n-3] == -1) {
        arr[n-3] = staircase_mem_helper(n-3, arr);
    }
    return arr[n-1] + arr[n-2] + arr[n-3];
}

long staircase_mem(int n) {
    long *arr = new long[n+1];
    for(int i=0; i<n+1; i++) {
        arr[i] = -1;
    }
    long ans = staircase_mem_helper(n, arr);
    delete []arr;
    return ans;
}

// DP
// Time Complexity = O(N)
// Space Complexity = O(N)

long staircase(int n) {
    long *arr = new long[n+1];
    for(int i=0; i<=2 && i<n+1; i++) {
        arr[i] = i;
    }
    if(n > 3) {
        arr[3] = 4;
    }
    for(int i=4 ; i<n+1; i++) {
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
    }
    long ans = arr[n];
    delete []arr;
    return ans;
}

int main() {
    int n;
    cin >> n;
    long ans1 = staircase_bf(n);
    long ans2 = staircase_mem(n);
    long ans3 = staircase(n);
    cout << "ans1 : " << ans1 << endl;
    cout << "ans2 : " << ans2 << endl;
    cout << "ans3 : " << ans3 << endl;
    return 0;
}