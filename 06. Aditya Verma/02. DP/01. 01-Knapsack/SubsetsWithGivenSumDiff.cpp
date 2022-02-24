#include <iostream>
using namespace std;

//  subSum1 - subSum2 = diff
//  subSum1 + subSum2 = sum
//  Calculating :
//  subSum1 = (sum + diff) / 2   ..   reduced to "Count Subsets for a sum" problem.

// Top-down approach
int countSubsetsSum_help(int *input, int n, int sum, int** arr) {
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

int countSubsetsSum(int* input, int n, int sum) {
    int **arr = new int*[n+1];
    for(int i=0; i<n+1; i++) {
        arr[i] = new int[sum+1];
    }
    return countSubsetsSum_help(input, n, sum, arr);
}

int countSubsets(int* input, int n, int diff) {
    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += input[i];
    }
    int count = countSubsetsSum(input, n, (sum+diff)/2);
    return count;
}

int main() {
    int n;
    cin >> n;
    int* input = new int[n];
    for(int i=0; i<n; i++) {
        cin >> input[i];
    }
    int diff;
    cin >> diff;
    int count = countSubsets(input, n, diff);
    cout << count << endl;
    delete []input;
    return 0;
}