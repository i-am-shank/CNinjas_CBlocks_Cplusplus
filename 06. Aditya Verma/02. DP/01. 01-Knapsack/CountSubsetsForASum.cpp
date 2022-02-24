#include <iostream>
using namespace std;

// Recursion
int countSubsets(int* input, int n, int sum) {
    if(sum == 0) {
        return 1;
    }
    if(n == 0) {
        return 0;
    }
    if(input[n-1] <= sum) {
        int count1 = countSubsets(input, n-1, sum-input[n-1]);
        int count2 = countSubsets(input, n-1, sum);
        return (count1 + count2);
    }
    else {
        return countSubsets(input, n-1, sum);
    }
}

// memoization
int countSubsets_mem_help(int* input, int n, int sum, int** arr) {
    if(arr[n][sum] != -1) {
        return arr[n][sum];
    }
    if(sum == 0) {
        arr[n][sum] = 1;
        return 1;
    }
    if(n == 0 && sum != 0) {
        arr[n][sum] = 0;
        return 0;
    }
    if(input[n-1] <= sum) {
        int count1 = countSubsets_mem_help(input, n-1, sum-input[n-1], arr);
        int count2 = countSubsets_mem_help(input, n-1, sum, arr);
        arr[n][sum] = count1 + count2;
        return arr[n][sum];
    }
    else {
        arr[n][sum] = countSubsets_mem_help(input, n-1, sum, arr);
        return arr[n][sum];
    }
}

int countSubsets_mem(int* input, int n, int sum) {
    int **arr = new int*[n+1];
    for(int i=0; i<n+1; i++) {
        arr[i] = new int[sum+1];
        for(int j=0; j<sum+1; j++) {
            arr[i][j] = -1;
        }
    }
    int ans = countSubsets_mem_help(input, n, sum, arr);
    for(int i=0; i<n+1; i++) {
        delete []arr[i];
    }
    delete []arr;
    return ans;
}

// top-down
int countSubsets_topdown_help(int* input, int n, int sum, int** arr) {
    for(int i=0; i<n+1; i++) {
        for(int j=0; j<sum+1; j++) {
            if(i==0 || j==0) {
                if(i == 0) {
                    arr[i][j] = 0;
                }
                if(j == 0) {
                    arr[i][j] = 1;
                }
            }
            else {
                if(input[i-1] <= j) {
                    arr[i][j] = arr[i-1][j-input[i-1]] + arr[i-1][j];
                }
                else {
                    arr[i][j] = arr[i-1][j];
                }
            }
        }
    }
    int ans = arr[n][sum];
    for(int i=0; i<n+1; i++) {
        delete []arr[i];
    }
    delete []arr;
    return ans;
}

int countSubsets_topdown(int* input, int n, int sum) {
    int **arr = new int*[n+1];
    for(int i=0; i<n+1; i++) {
        arr[i] = new int[sum+1];
    }
    return countSubsets_topdown_help(input, n, sum, arr);
}

int main() {
    int n;
    cin >> n;
    int *input = new int[n];
    for(int i=0; i<n; i++) {
        cin >> input[i];
    }
    int sum;
    cin >> sum;
    int count1 = countSubsets(input, n, sum);
    int count2 = countSubsets_mem(input, n, sum);
    int count3 = countSubsets_topdown(input, n, sum);
    cout << count1 << endl;
    cout << count2 << endl;
    cout << count3 << endl;
    delete []input;
    return 0;
}