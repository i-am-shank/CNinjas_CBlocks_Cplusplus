#include <iostream>
using namespace std;

// We can positify or negatify any no. of elements.. to reach target sum.
// a[0] - a[1] + a[2] + a[3] - a[4]  ...  (a[0] + a[2] + a[3])  -  (a[1] + a[4])
// Seems like Subset-sum difference is given ..instead of target sum.

int countSubsets_help(int *input, int n, int sum, int** arr) {
    for(int i=0; i<n+1; i++) {
        for(int j=0; j<sum+1; j++) {
            if(i==0 || j==0) {
                if(i == 0) {  // 0 elements in input array..
                    arr[i][j] = 0;
                }
                if(j == 0) {  // we have to find subsets with sum 0.
                    arr[i][j] = 1;
                }
            }
            else {
                if(input[i-1] <= j) {
                    arr[i][j]  =  arr[i-1][j-input[i-1]]  +  arr[i-1][j];
                }
                else {
                    arr[i][j]  =  arr[i-1][j];
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

int countSubsets(int* input, int n, int sum) {
    int **arr = new int*[n+1];
    for(int i=0; i<n+1; i++) {
        arr[i] = new int[sum+1];
    }
    return countSubsets_help(input, n, sum, arr);
}

int targetSum(int *input, int n, int sum) {
    // Actually target sum here is .. given subsetSum difference.
    // subSum1 - subSum2 = diff
    // subSum1 + subSum2 = sum
    // subSum1 = (sum + diff) / 2   ..   reduced to "count subsets with given sum". 
    int inputSum = 0;
    for(int i=0; i<n; i++) {
        inputSum += input[i];
    }
    return countSubsets(input, n, (inputSum + sum) / 2);
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
    int count = targetSum(input, n, sum);
    cout << count << endl;
    delete []input;
    return 0;
}