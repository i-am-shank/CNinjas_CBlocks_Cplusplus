#include <iostream>
using namespace std;

// Recursion
int knapsack(int* weights, int* values, int w, int n) {
    if(n==0 || w==0) {  // Base case .. if capacity of knapsack is 0 or weights are 0.
        return 0;
    }
    if(weights[n-1] <= w) {
        int choice1 = values[n-1] + knapsack(weights, values, w-weights[n-1], n-1); //taken
        int choice2 = knapsack(weights, values, w, n-1); // not taken
        return max(choice1, choice2);  // max value obtaining from both ways.
    }
    else {
        return knapsack(weights, values, w, n-1); // can't take last weight.
    }
}

// Memoization
int knapsack_mem_helper(int* weights, int* values, int w, int n, int** arr) {
    if(arr[n][w] != -1) {  // using memory to avoid repeated recursion calls.
        return arr[n][w];
    }
    if(n==0 || w==0) {
        arr[n][w] = 0;
        return 0;
    }
    if(weights[n-1] <= w) {
        int choice1 = values[n-1] + knapsack(weights, values, w-weights[n-1], n-1);
        int choice2 = knapsack(weights, values, w, n-1);
        arr[n][w] = max(choice1, choice2);
        return arr[n][w];
    }
    else {
        arr[n][w] = knapsack(weights, values, w, n-1);
        return arr[n][w];
    }
}

int knapsack_mem(int* weights, int* values, int w, int n) {
    int **arr = new int* [n+1];
    for(int i=0; i<n+1; i++) {
        arr[i] = new int[w+1];
        for(int j=0; j<w+1; j++) {
            arr[i][j] = -1;
        }
    }
    return knapsack_mem_helper(weights, values, w, n, arr);
}

// Top-down
int knapsack_topdown_help(int* weights, int* values, int w, int n, int** arr) {
    for(int i=1; i<n+1; i++) {  //  Transformation in Recursion code.
        for(int j=1; j<w+1; j++) {  //   n -> i   &&   w -> j
            if(weights[i-1] <= j) {
                arr[i][j] = max(values[i-1]+ arr[i-1][j-weights[i-1]] , arr[i-1][j]);
            }
            else {
                arr[i][j] = arr[i-1][j];
            }
        }
    }
    return arr[n][w];
}

int knapsack_topdown(int* weights, int* values, int w, int n) {
    int **arr = new int* [n+1];
    for(int i=0; i<n+1; i++) {
        arr[i] = new int[w+1];
        for(int j=0; j<w+1; j++) {
            if(i==0 || j==0) {
                arr[i][j] = 0;  // Initialisation
            }
        }
    }
    return knapsack_topdown_help(weights, values, w, n, arr);
}

int main() {
    int n;
    cin >> n;
    int* weights = new int[n];
    int* values = new int[n];
    for(int i=0; i<n; i++) {
        cin >> weights[i];
    }
    for(int i=0; i<n; i++) {
        cin >> values[i];
    }
    int w;
    cin >> w;
    int maxValue1 = knapsack(weights, values, w, n);
    int maxValue2 = knapsack_mem(weights, values, w, n);
    int maxValue3 = knapsack_topdown(weights, values, w, n);
    cout << maxValue1 << endl;
    cout << maxValue2 << endl;
    cout << maxValue3 << endl;
    delete []weights;
    delete []values;
}