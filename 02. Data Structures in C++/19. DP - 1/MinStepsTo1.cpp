#include <iostream>
using namespace std;

// Brute-force approach
// Time complexity = O(3^N)
// Space complexity = O(3^N)

int countMinStepsToOne(int n) {
    if(n == 1) {  // edge case
        return 0;
    }
    if(n <= 3) {  // base case
        return 1;
    }
    int ans1, ans2 = INT_MAX, ans3 = INT_MAX;
    if(n % 3 == 0) {
        ans3 = countMinStepsToOne(n/3);
    }
    if(n % 2 == 0) {
        ans2 = countMinStepsToOne(n/2);
    }
    ans1 = countMinStepsToOne(n-1);
    return min(ans1 , min(ans2, ans3)) + 1;
}

// Memoization
// Time Complexity = O(N)
// Space Complexity = O(N)

int countMinStepsToOne_memo_helper(int n, int* arr) {
    if(n == 1) {
        arr[n] = 0;
        return arr[n];
    }
    if(n <= 3) {
        arr[n] = 1;
    }
    int ans1, ans2 = INT_MAX, ans3 = INT_MAX;
    if(n % 3 == 0) {
        if(arr[n/3] == -1) {
            arr[n/3] = countMinStepsToOne_memo_helper(n/3, arr);
        }
        ans3 = arr[n/3];
    }
    if(n % 2 == 0) {
        if(arr[n/2] == -1) {
            arr[n/2] = countMinStepsToOne_memo_helper(n/2, arr);
        }
        ans2 = arr[n/2];
    }
    if(arr[n-1] == -1) {
        arr[n-1] = countMinStepsToOne_memo_helper(n-1, arr);
    }
    ans1 = arr[n-1];
    return min(ans1 , min(ans2, ans3)) + 1;
}

int countMinStepsToOne_memo(int n) {
    int *arr = new int[n+1];
    for(int i=0; i<n+1; i++) {
        arr[i] = -1;
    }
    int ans = countMinStepsToOne_memo_helper(n, arr);
    delete []arr;
    return ans;
}

int main() {
    int n;
    cin >> n;
    int ans1 = countMinStepsToOne(n);
    int ans2 = countMinStepsToOne_memo(n);
    cout << "ans1 : " << ans1 << endl;
    cout << "ans2 : " << ans2 << endl;
    return 0;
}