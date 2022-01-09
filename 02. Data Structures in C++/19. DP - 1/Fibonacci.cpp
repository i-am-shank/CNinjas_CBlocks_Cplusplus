#include <iostream>
using namespace std;

// brute-force approach --> general loops OR recursion
int fibonacci(int n) {
    if(n == 0 || n==1) {
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

// Memoization
int fibonacci_mem_helper(int n, int *arr) {
    if(n==0 || n==1) {
        arr[n] = n;
        return arr[n];
    }
    if(arr[n-1] == 0) {
        arr[n-1] = fibonacci_mem_helper(n-1, arr);
    }
    if(arr[n-2] == 0) {
        arr[n-2] = fibonacci_mem_helper(n-2, arr);
    }
    return arr[n-1] + arr[n-2];
}

int fibonacci_mem(int n) {
    int *arr = new int[n+1];
    for(int i=0; i<n+1; i++) {
        arr[i] = 0;
    }
    return fibonacci_mem_helper(n, arr);
}

// DP  -->  iterative method
int fibonacci_dp(int n) {
    int *arr = new int[n+1];
    arr[0] = 0;
    arr[1] = 1;
    for(int i=2; i<=n; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }
    int ans = arr[n];
    delete []arr;
    return ans;
}

int main() {
    int n;
    cin >> n;
    int ans1 = fibonacci(n);
    int ans2 = fibonacci_mem(n);
    int ans3 = fibonacci_dp(n);
    cout << "ans1 : " << ans1 << endl;
    cout << "ans2 : " << ans2 << endl;
    cout << "ans3 : " << ans3 << endl;
    return 0;
}