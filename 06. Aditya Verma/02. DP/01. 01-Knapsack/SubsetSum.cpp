#include <iostream>
using namespace std;

// Recursion
bool sumSet(int* arr, int n, int sum) {
    if(sum == 0) {
        return true;
    }
    if(n == 0) {
        return false;
    }
    if(arr[n-1] <= sum) {
        bool choice1 = sumSet(arr, n-1, sum-arr[n-1]);
        bool choice2 = sumSet(arr, n-1, sum);
        return (choice1 || choice2);
    }
    else {
        return sumSet(arr, n-1, sum);
    }
}

// memoization
bool sumSet_mem_help(int* input, int n, int sum, int** arr) {
    if(arr[n][sum] != -1) {  // Controlling recursion calls.
        if(arr[n][sum] == 1) {
            return true;
        }
        else {
            return false;
        }
    }
    if(sum == 0) {
        arr[n][sum] = 1;
        return true;
    }
    if(n == 0 && sum != 0) {
        arr[n][sum] = 0;
        return false;
    }
    if(input[n-1] <= sum) {
        bool choice1 = sumSet_mem_help(input, n-1, sum-input[n-1], arr);
        bool choice2 = sumSet_mem_help(input, n-1, sum, arr);
        bool ans = (choice1 || choice2);
        if(ans == true) {
            arr[n][sum] = 1;
        }
        else {
            arr[n][sum] = 0;
        }
        return ans;
    }
    else {
        bool ans = sumSet_mem_help(input, n-1, sum, arr);
        if(ans == true) {
            arr[n][sum] = 1;
        }
        else {
            arr[n][sum] = 0;
        }
        return ans;
    }
}

bool sumSet_mem(int* input, int n, int sum) {
    int **arr = new int*[n+1];
    for(int i=0; i<n+1; i++) {
        arr[i] = new int [sum+1];
        for(int j=0; j<sum+1; j++) {
            arr[i][j] = -1;
        }
    }
    return sumSet_mem_help(input, n, sum, arr);
}

// Top-down
bool sumSet_topdown_help(int* input, int n, int sum, bool** arr) {
    for(int i=0; i<n+1; i++) {
        for(int j=0; j<sum+1; j++) {
            if(i == 0 || j == 0) {
                if(i == 0) {  //  n = 0
                    arr[i][j] = false;
                }
                if(j == 0) {  //  sum = 0
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

bool sumSet_topdown(int* input, int n, int sum) {
    bool **arr = new bool* [n+1];
    for(int i=0; i<n+1; i++) {
        arr[i] = new bool [sum+1];
    }
    bool ans = sumSet_topdown_help(input, n, sum, arr);
    for(int i=0; i<n+1; i++) {
        delete []arr[i];
    }
    delete []arr;
    return ans;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int sum;
    cin >> sum;
    bool ans1 = sumSet(arr, n, sum);
    bool ans2 = sumSet_mem(arr, n, sum);
    bool ans3 = sumSet_topdown(arr, n, sum);
    cout << (ans1 == true ? "true" : "false") << endl;
    cout << (ans2 == true ? "true" : "false") << endl;
    cout << (ans3 == true ? "true" : "false") << endl;
    delete arr;
    return 0;
}