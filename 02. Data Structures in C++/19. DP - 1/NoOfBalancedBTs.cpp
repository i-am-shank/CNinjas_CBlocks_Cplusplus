#include <iostream>
#include <math.h>
using namespace std;

// BRUTE-FORCE
// Time Complexity = O(3^N)
// Space Complexity = O(3^N)

int balancedBTs_bf(int n) {
    if(n < 3 && n >= 1) {
        int ans = pow(2,n) - 1;
        return ans;
    }
    int ans1 = balancedBTs_bf(n-1);
    int ans2 = balancedBTs_bf(n-2);
    return ((ans1*ans1) + (2 *(ans1*ans2)));
}

// MEMOIZATION

int balancedBTs_mem_helper(int n, int* arr) {
    if(n<3 && n>=1) {
        if(arr[n] == -1) {
            arr[n] = pow(2,n) - 1;
        }
        return arr[n];
    }
    if(arr[n-1] == -1) {
        arr[n-1] = balancedBTs_mem_helper(n-1, arr);
    }
    if(arr[n-2] == -1) {
        arr[n-2] = balancedBTs_mem_helper(n-2, arr);
    }
    int ans1 = arr[n-1];
    int ans2 = arr[n-2];
    return ((ans1*ans1) + (2 *(ans1*ans2)));
}

int balancedBTs_mem(int n) {
    int *arr = new int[n+1];
    for(int i=0; i<n+1; i++) {
        arr[i] = -1;
    }
    int ans = balancedBTs_mem_helper(n, arr);
    delete []arr;
    return ans;
}

// DP
// Time Complexity = O(N)
// Space Complexity = O(N)

int balancedBTs_dp(int n) {
    int *arr = new int[n+1];
    if(n < 3) {
        return pow(2,n) - 1;
    }
    for(int i=0; i<3; i++) {
        arr[i] = pow(2,i) - 1;
    }
    for(int i=3; i<n+1; i++) {
        arr[i] = (arr[i-1]*arr[i-1]) + (2 * (arr[i-1]*arr[i-2]));
    }
    return arr[n];
}

int main() {
    int h;
    cin >> h;
    int x = pow(10,9) + 7;
    int ans_bf = balancedBTs_bf(h) % x;
    int ans_mem = balancedBTs_mem(h) % x;
    int ans_dp = balancedBTs_dp(h) % x;
    cout << "ans_bf : " << ans_bf << endl;
    cout << "ans_mem : " << ans_mem << endl;
    cout << "ans_dp : " << ans_dp << endl;
    return 0;
}