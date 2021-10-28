// Time Complexity = O(N**2)  ..  O(N) for each test case.
// Space Complexity = O(N**2)  ..  O(N) for each test case.


#include <iostream>
#include <math.h>
using namespace std;

void sumOfTwoArrays(int *input1, int size1, int *input2, int size2, int *output) {
    int i=size1-1, j=size2-1, carry=0, k=max(size1, size2), sum;
    while (i>=0 && j>=0) {
        sum = input1[i--] + input2[j--] + carry;
        output[k--] = sum % 10;
        carry = sum / 10; 
    }
    while (i >= 0) {
        sum = input1[i--] + carry;
        output[k--] = sum % 10;
        carry = sum / 10;
    }
    while (j >= 0) {
        sum = input2[j--] + carry;
        output[k--] = sum % 10;
        carry = sum / 10;
    }
    output[0] = carry;
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n;
        int* input1 = new int[n];
        for (int i=0; i<n; i++) {
            cin >> input1[i];
        }
        cin >> m;
        int* input2 = new int[m];
        for (int i=0; i<m; i++) {
            cin >> input2[i];
        }
        int* output = new int[n+m];
        sumOfTwoArrays(input1, n, input2, m, output);
        for (int i=0; i<max(n, m)+1 ; i++) {
            cout << output[i] << " ";
        }
        cout << endl;
        delete []input1;
        delete []input2;
        delete []output;
    }
    return 0;
}