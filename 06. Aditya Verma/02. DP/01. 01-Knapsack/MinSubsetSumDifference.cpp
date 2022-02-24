#include <iostream>
using namespace std;

bool subSetSum(int* input, int n, int sum, bool** arr) {
    for(int i=0; i<n+1; i++) {
        for(int j=0; j<sum+1; j++) {
            if(i==0 || j==0) {
                if(i == 0) {
                    arr[i][j] = false;
                }
                if(j == 0) {
                    arr[i][j] = true;
                }
            }
            else {
                if(input[i-1] <= j) {
                    arr[i][j]  =  arr[i-1][j-input[i-1]]  ||  arr[i-1][j];
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

bool subSetSum(int* input, int n, int sum) {
    bool** arr = new bool*[n+1];
    for(int i=0; i<n+1; i++) {
        arr[i] = new bool[sum+1];
    }
    return subSetSum(input, n, sum, arr);
}

int minSubsetDiff(int* input, int n) {
    if(n == 0) {
        return 0;
    }
    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += input[i];
    }
    int diff;
    for(int i=sum/2; i>=0; i--) {  // Find smaller of pair of sumset-sums.
        bool ans = subSetSum(input, n, i);  // Minimise (subsetSum1 - subsetSum2)
        if(ans == true) {  //  ..Surely subsetSum2 will be smaller of the pair.
            diff = sum - (2 * i);  // Minimise  ((sum - subsetSum2) - subsetSum2)
            break;                 //        =  (sum - (2 * subsetSum2))
        }               // When found, no need to search for smaller sums.. 
    }
    return diff;
}

int main() {
    int n;
    cin >> n;
    int *input = new int[n];
    for(int i=0; i<n; i++) {
        cin >> input[i];
    }
    int ans = minSubsetDiff(input, n);
    cout << ans << endl;
    delete []input;
    return 0;
}