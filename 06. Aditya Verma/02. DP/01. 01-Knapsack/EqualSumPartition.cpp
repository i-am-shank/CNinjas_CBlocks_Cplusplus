#include <iostream>
using namespace std;

// Recursion
bool subSetSum(int *input, int n, int sum) {
    if(sum == 0) {
        return true;
    }
    if(n == 0) {
        return false;
    }
    if(input[n-1] <= sum) {
        bool choice1 = subSetSum(input, n-1, sum-input[n-1]);
        bool choice2 = subSetSum(input, n-1, sum);
        return (choice1 || choice2);
    }
    else {
        return subSetSum(input, n-1, sum);
    }
}

// Top-down
bool subSetSum_topdown_help(int *input, int n, int sum, bool** arr) {
    for(int i=0; i<n+1; i++) {
        for(int j=0; j<sum+1; j++) {
            if(i==0 || j==0) {
                if(i==0) {
                    arr[i][j] = false;
                }
                if(j==0) {
                    arr[i][j] = true;
                }
            }
            else {
                if(input[i-1] <= j) {
                    bool choice1 = arr[i-1][j-input[i-1]];
                    bool choice2 = arr[i-1][j];
                    arr[i][j] = (choice1 || choice2);
                }
                else {
                    arr[i][j] = arr[i-1][j];
                }
            }
        }
    }
    return arr[n][sum];
}

bool subSetSum_topdown(int *input, int n, int sum) {
    bool** arr = new bool* [n+1];
    for(int i=0; i<n+1; i++) {
        arr[i] = new bool[sum+1];
    }
    return subSetSum_topdown_help(input, n, sum, arr);
}

bool equalSum(int *input, int n, int sum) {
    if(sum % 2 == 0) { // even sum
        return subSetSum_topdown(input, n, sum/2);
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    int *input = new int[n];
    int sum = 0;
    for(int i=0; i<n; i++) {
        cin >> input[i];
        sum += input[i];
    }
    bool ans = equalSum(input, n, sum);  // Possible when sum is even.
          // And find subsetSum for (sum / 2).
    cout << (ans == true ? "true" : "false") << endl;
    delete []input;
    return 0;
}