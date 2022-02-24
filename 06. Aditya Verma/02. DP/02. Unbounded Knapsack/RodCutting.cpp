#include <iostream>
using namespace std;

// Recursion
int rodCutting(int* length, int* price, int n, int lRod) {
    if(n == 0 || lRod == 0) {
        return 0;
    }
    if(length[n-1] <= lRod) {
        int choice1 = price[n-1] + rodCutting(length, price, n, lRod-length[n-1]);
        int choice2 = rodCutting(length, price, n-1, lRod);
        return max(choice1, choice2);
    }
    else {
        return rodCutting(length, price, n-1, lRod);
    }
}

// Memoization
int rodCutting_mem_help(int* length, int* price, int n, int lRod, int** arr) {
    if(arr[n][lRod] != -1) {
        return arr[n][lRod];
    }
    if(n==0 || lRod==0) {
        arr[n][lRod] = 0;
        return 0;
    }
    if(length[n-1] <= lRod) {
        int choice1 = price[n-1] + rodCutting_mem_help(length, price, n, lRod-length[n-1], arr);
        int choice2 = rodCutting_mem_help(length, price, n-1, lRod, arr);
        arr[n][lRod] = max(choice1, choice2);
        return arr[n][lRod];
    }
    else {
        arr[n][lRod] = rodCutting_mem_help(length, price, n-1, lRod, arr);
        return arr[n][lRod];
    }
}

int rodCutting_mem(int* length, int* price, int n, int lRod) {
    int** arr = new int*[n+1];
    for(int i=0; i<n+1; i++) {
        arr[i] = new int[lRod+1];
        for(int j=0; j<lRod+1; j++) {
            arr[i][j] = -1;
        }
    }
    int ans = rodCutting_mem_help(length, price, n, lRod, arr);
    for(int i=0; i<n+1; i++) {
        delete []arr[i];
    }
    delete []arr;
    return ans;
}

// Top-down
int rodCutting_td_help(int* length, int* price, int n, int lRod, int** arr) {
    for(int i=1; i<n+1; i++) {
        for(int j=1; j<lRod+1; j++) {
            if(length[i-1] <= j) {
                arr[i][j] = max(price[i-1]+ arr[i][j-length[i-1]] , arr[i-1][j]);
            }
            else {
                arr[i][j] = arr[i-1][j];
            }
        }
    }
    return arr[n][lRod];
}

int rodCutting_td(int* length, int* price, int n, int lRod) {
    int** arr = new int*[n+1];
    for(int i=0; i<n+1; i++) {
        arr[i] = new int[lRod+1];
        for(int j=0; j<lRod+1; j++) {
            if(i==0 || j==0) {
                arr[i][j] = 0;
            }
        }
    }
    int ans = rodCutting_td_help(length, price, n, lRod, arr);
    for(int i=0; i<n+1; i++) {
        delete []arr[i];
    }
    delete []arr;
    return ans;
}

int main() {
    int n;
    cin >> n;
    int *length = new int[n];
    for(int i=0; i<n; i++) {
        cin >> length[i];
    }
    int *price = new int[n];
    for(int i=0; i<n; i++) {
        cin >> price[i];
    }
    int lRod;
    cin >> lRod;  // Length of rod.
    int maxProfit1 = rodCutting(length, price, n, lRod);
    int maxProfit2 = rodCutting_mem(length, price, n, lRod);
    int maxProfit3 = rodCutting_td(length, price, n, lRod);
    cout << maxProfit1 << endl;
    cout << maxProfit2 << endl;
    cout << maxProfit3 << endl;
    delete []length;
    delete []price;
    return 0;
}