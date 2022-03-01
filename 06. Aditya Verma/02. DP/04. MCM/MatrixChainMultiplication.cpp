#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int mcm_help(int* input, int start, int end) {
    if(start >= end) {
        return 0;
    }
    int minCost = INT_MAX;
    for(int k = start ; k < end ; k++) {
        int cost = input[start-1] * input[k] * input[end];
        int temp = mcm_help(input, start, k) + mcm_help(input, k+1, end) + cost;
        minCost = min(temp, minCost);
    }
    return minCost;
}

int mcm(int* input, int n) {
    int i = 1;
    int j = n-1;
    return mcm_help(input, i, j);
}

int mcm_mem_help(int *input, int s, int e, int** arr) {
    if(arr[s][e] != -1) {
        return arr[s][e];
    }
    for(int i=0; i<e+2; i++) {
        for(int j=0; j<e+2; j++) {
            if(i >= j) {
                arr[i][j] = 0;
            }
        }
    }
    int minCost = INT_MAX;
    for(int k=s; k<e; k++) {
        int cost = input[s-1] * input[k] * input[e];
        int left, right;
        if(arr[s][k] != -1) {    // Calculating left
            left = arr[s][k];
        }
        else {
            left = mcm_mem_help(input, s, k, arr);
            arr[s][k] = left;
        }
        if(arr[k+1][e] != -1) {    // Calculating right
            right = arr[k+1][e];
        }
        else {
            right = mcm_mem_help(input, k+1, e, arr);
            arr[k+1][e] = right;
        }
        int temp = left + right + cost;
        minCost = min(minCost, temp);
    }
    arr[s][e] = minCost;
    return minCost;
}

int mcm_mem(int* input, int n) {    // Memoization
    int i=1;
    int j= n-1;
    int **arr = new int*[n+1];
    for(int i=0; i<n+1; i++) {
        arr[i] = new int[n+1];
        for(int j=0; j<n+1; j++) {
            arr[i][j] = -1;
        }
    }
    int ans = mcm_mem_help(input, i, j, arr);
    for(int i=0; i<n+1; i++) {
        delete []arr[i+1];
    }
    delete []arr;
    return ans;
}

int main() {
    int n;
    cin >> n;
    int *input = new int[n];
    for(int i=0; i<n; i++) {
        cin >> input[i];
    }
    int minCost = mcm(input, n);
    int minCost2 = mcm_mem(input, n);
    cout << minCost << endl;
    cout << minCost2 << endl;
    delete []input;
    return 0;
}