#include <iostream>
using namespace std;

bool splitArrayHelp(int *input, int start, int end, int lSum, int rSum) {
    if(start > end) {
        if(lSum == rSum) {
            return true;
        }
        return false;
    }
    if(input[start] % 5 == 0) {
        lSum += input[start];
        return splitArrayHelp(input, start+1, end, lSum, rSum);
    }
    else if(input[start] % 3 == 0) {
        rSum += input[start];
        return splitArrayHelp(input, start+1, end, lSum, rSum);
    }
    else {
        bool smallAns1 = splitArrayHelp(input, start+1, end, lSum+input[start], rSum);
        bool smallAns2 = splitArrayHelp(input, start+1, end, lSum, rSum+input[start]);
        return (smallAns1 || smallAns2);
    }
}

bool splitArray(int *input, int size) {
    return splitArrayHelp(input, 0, size-1, 0, 0);
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    bool ans = splitArray(arr, n);
    cout << (ans == true ? "True" : "False") << endl;
    delete []arr;
    return 0;
}