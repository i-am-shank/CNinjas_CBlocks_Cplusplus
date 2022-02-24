#include <iostream>
using namespace std;

int coinChange(int* coin, int n, int sum) {
    if(sum == 0) {
        return 1;
    }
    if(n == 0) {
        return 0;
    }
    if(coin[n-1] <= sum) {
        int choice1 = coinChange(coin, n, sum-coin[n-1]);
        int choice2 = coinChange(coin, n-1, sum);
        return choice1 + choice2;
    }
    else {
        return coinChange(coin, n-1, sum);
    }
}

// Memoization
int coinChange_mem_help(int* coin, int n, int sum, int** arr) {
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
    if(coin[n-1] <= sum) {
        int choice1 = coinChange_mem_help(coin, n, sum-coin[n-1], arr);
        int choice2 = coinChange_mem_help(coin, n-1, sum, arr);
        arr[n][sum] = choice1 + choice2;
        return arr[n][sum];
    }
    else {
        arr[n][sum] = coinChange_mem_help(coin, n-1, sum, arr);
        return arr[n][sum];
    }
}

int coinChange_mem(int* coin, int n, int sum) {
    int **arr = new int*[n+1];
    for(int i=0; i<n+1; i++) {
        arr[i] = new int[sum+1];
        for(int j=0; j<sum+1; j++) {
            arr[i][j] = -1;
        }
    }
    int ans = coinChange_mem_help(coin, n, sum, arr);
    for(int i=0; i<n+1; i++) {
        delete []arr[i];
    }
    delete []arr;
    return ans;
}

// Top-down
int coinChange_td_help(int *coin, int n, int sum, int** arr) {
    for(int i=1; i<n+1; i++) {
        for(int j=1; j<sum+1; j++) {
            if(coin[i-1] <= j) {
                arr[i][j] = arr[i][j-coin[i-1]] + arr[i-1][j];
            }
            else {
                arr[i][j] = arr[i-1][j];
            }
        }
    }
    return arr[n][sum];
}

int coinChange_td(int *coin, int n, int sum) {
    int **arr = new int*[n+1];
    for(int i=0; i<n+1; i++) {
        arr[i] = new int[sum+1];
        for(int j=0; j<sum+1; j++) {
            if(i == 0 && j!=0) {
                arr[i][j] = 0;
            }
            if(j == 0) {
                arr[i][j] = 1;
            }
        }
    }
    int ans = coinChange_td_help(coin, n, sum, arr);
    for(int i=0; i<n+1; i++) {
        delete []arr[i];
    }
    delete []arr;
    return ans;
}

int main() {
    int n;
    cin >> n;
    int *coin = new int[n];
    for(int i=0; i<n; i++){
        cin >> coin[i];
    }
    int sum;
    cin >> sum;
    int numWays1 = coinChange(coin, n, sum);
    int numWays2 = coinChange_mem(coin, n, sum);
    int numWays3 = coinChange_td(coin, n, sum);
    cout << numWays1 << endl;
    cout << numWays2 << endl;
    cout << numWays3 << endl;
    delete []coin;
    return 0;
}