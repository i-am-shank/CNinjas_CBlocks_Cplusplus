#include <iostream>
using namespace std;

// Recursion
int unboundedKnapsack(int* value, int* weights, int n, int w) {
    if(n==0 || w==0) {
        return 0;
    }
    if(weights[n-1] <= w) {
        int choice1 = value[n-1] + unboundedKnapsack(value, weights, n, w-weights[n-1]);
        int choice2 = unboundedKnapsack(value, weights, n-1, w);
        return max(choice1, choice2);
    }
    else {
        return unboundedKnapsack(value, weights, n-1, w);
    }
}

// Memoization
int unboundedKnapsack_m_help(int* value, int* weights, int n, int w, int **arr) {
    if(arr[n][w] != -1) {
        return arr[n][w];
    }
    if(n==0 || w==0) {
        arr[n][w] = 0;
        return 0;
    }
    if(weights[n-1] <= w) {
        int choice1 = value[n-1] + unboundedKnapsack_m_help(value,weights,n,w-weights[n-1],arr);
        int choice2 = unboundedKnapsack_m_help(value, weights, n-1, w, arr);
        arr[n][w] = max(choice1, choice2);
        return arr[n][w];
    }
    else {
        arr[n][w] = unboundedKnapsack_m_help(value, weights, n-1, w, arr);
        return arr[n][w];
    }
}

int unboundedKnapsack_m(int* value, int* weights, int n, int w) {
    int **arr = new int*[n+1];
    for(int i=0; i<n+1; i++) {
        arr[i] = new int[w+1];
        for(int j=0; j<w+1; j++) {
            arr[i][j] = -1;
        }
    }
    int ans = unboundedKnapsack_m_help(value, weights, n, w, arr);
    for(int i=0; i<n+1; i++) {
        delete []arr[i];
    }
    delete []arr;
    return ans;
}

// Top-down approach
int unboundedKnapsack_td_help(int* value, int* weights, int n, int w, int** arr) {
    for(int i=0; i<n+1; i++) {
        for(int j=0; j<w+1; j++) {
            if(i==0 || j==0) {
                arr[i][j] = 0;
            }
        }
    }
    for(int i=1; i<n+1; i++) {
        for(int j=1; j<w+1; j++) {
            if(weights[i-1] <= j) {
                arr[i][j] = max(value[i-1] + arr[i][j-weights[i-1]] , arr[i-1][j]);
            }
            else {
                arr[i][j] = arr[i-1][j];
            }
        }
    }
    return arr[n][w];
}

int unboundedKnapsack_td(int* value, int* weights, int n, int w) {
    int **arr = new int* [n+1];
    for(int i=0; i<n+1; i++) {
        arr[i] = new int [w+1];
    }
    int ans = unboundedKnapsack_td_help(value, weights, n, w, arr);
    for(int i=0; i<n+1; i++) {
        delete []arr[i];
    }
    delete []arr;
    return ans;
}

int main() {
    int n;
    cin >> n;
    int *value = new int[n];
    for(int i=0; i<n; i++) {
        cin >> value[i];
    }
    int *weights = new int [n];
    for(int i=0; i<n; i++) {
        cin >> weights[i];
    }
    int w;  // Capacity of Knapsack
    cin >> w;
    int maxValue1 = unboundedKnapsack(value, weights, n, w);
    int maxValue2 = unboundedKnapsack_m(value, weights, n, w);
    int maxValue3 = unboundedKnapsack_td(value, weights, n, w);
    cout << maxValue1 << endl;
    cout << maxValue2 << endl;
    cout << maxValue3 << endl;
    delete []value;
    delete []weights;
    return 0;
}