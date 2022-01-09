#include <iostream>
#include <climits>
using namespace std;

// DP .. iterative method
// Time Complexity = O(N)
// Space Complexity = O(N)

int countStepsToOne(int n) {
    int *arr = new int[n+1];
    arr[0] = INT_MAX;
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 1;
    for(int i=4; i<n+1; i++) {
        int mini = INT_MAX;
        if(i%3 == 0) {
            mini = min(mini, min(arr[i-1], arr[i/3]));
        }
        if(i%2 == 0) {
            mini = min(mini, min(arr[i-1], arr[i/2]));
        }
        if(i%3 != 0 && i%2 != 0) {
            mini = arr[i-1];
        }
        arr[i] = mini + 1;
    }
    return arr[n];
}

int main() {
    int n;
    cin >> n;
    int ans = countStepsToOne(n);
    cout << ans << endl;
    return 0;
}