#include <iostream>
#include <climits>
using namespace std;

int coinChange(int* coin, int n, int sum) {
    if(n == 0) {  // 0 coins
        return INT_MAX-1;
    }
    if(sum == 0) {  // 0 sum required
        return 0;
    }
    if(n == 1) {  // 1 coin  ..  and a non-zero sum required.
        if(sum % coin[0] == 0) {  // divisible
            return sum / coin[0];
        }
        else {
            return INT_MAX-1;
        }
    }
    if(coin[n-1] <= sum) {
        int choice1 = 1 + coinChange(coin, n, sum-coin[n-1]);  // coin taken   ..  + 1
        int choice2 = coinChange(coin, n-1, sum);
        return min(choice1, choice2);  // Minimum no. of coins needed ..  min( , )
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
    if(n == 0) {
        arr[n][sum] = INT_MAX - 1;
        return arr[n][sum];
    }
    if(sum == 0) {
        arr[n][sum] = 0;
        return arr[n][sum];
    }
    if(n == 1) {
        if(sum % coin[n-1] == 0) {
            arr[n][sum] = sum / coin[n-1];
        }
        else {
            arr[n][sum] = INT_MAX - 1;
        }
        return arr[n][sum];
    }
    if(coin[n-1] <= sum) {
        int choice1 = 1 + coinChange_mem_help(coin, n, sum-coin[n-1], arr);
        int choice2 = coinChange_mem_help(coin, n-1, sum, arr);
        arr[n][sum] = min(choice1, choice2);
        return arr[n][sum];
    }
    else {
        arr[n][sum] = coinChange_mem_help(coin, n-1, sum, arr);
        return arr[n][sum];
    }
}

int coinChange_mem(int* coin, int n, int sum) {
    int** arr = new int*[n+1];
    for(int i=0; i<n+1; i++) {
        arr[i] = new int[sum+1];
        for(int j=0; j<sum+1; j++) {
            arr[i][j] = -1;
        }
    }
    return coinChange_mem_help(coin, n, sum, arr);
}

// Top-down approach
int coinChange_td_help(int* coin, int n, int sum, int** arr) {
    for(int i=2; i<n+1; i++) {
        for(int j=1; j<sum+1; j++) {
            if(coin[i-1] <= j) {
                int choice1 = arr[i][j-coin[i-1]] + 1;
                int choice2 = arr[i-1][j];
                arr[i][j] = min(choice1, choice2);
            }
            else {
                arr[i][j] = arr[i-1][j];
            }
        }
    }
    return arr[n][sum];
}

int coinChange_td(int* coin, int n, int sum) {
    int **arr = new int*[n+1];
    for(int i=0; i<n+1; i++) {
        arr[i] = new int[sum+1];
        for(int j=0; j<sum+1; j++) {
            if(i == 0) {
                arr[i][j] = INT_MAX - 1;
            }
            if(j == 0 && i!=0) {
                arr[i][j] = 0;
            }
            if(i == 1) {
                if(sum % coin[i-1] == 0){
                    arr[i][j] = sum / coin[i-1];
                }
                else {
                    arr[i][j] = INT_MAX -1;
                }
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

// 3
// 1 2 3
// 5

int main() {
    int n;
    cin >> n;
    int *coin = new int[n];
    for(int i=0; i<n; i++) {
        cin >> coin[i];
    }
    int sum;
    cin >> sum;
    int minCoins1 = coinChange(coin, n, sum);
    int minCoins2 = coinChange_mem(coin, n, sum);
    int minCoins3 = coinChange_td(coin, n, sum);
    cout << minCoins1 << endl;
    cout << minCoins2 << endl;
    cout << minCoins3 << endl;
    delete []coin;
    return 0;
}