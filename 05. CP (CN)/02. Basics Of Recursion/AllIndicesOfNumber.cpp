// Time Complexity = O(N)
// Space Complexity = O(N)


#include <bits/stdc++.h>
using namespace std;

int allIndexesHelper(int input[], int size, int x, int currIndex, int output[]) {
    if(currIndex == size) {
        return 0;
    }
    int smallAns = allIndexesHelper(input+1, size, x, currIndex+1, output);
    if(input[0] == x) {
        output[smallAns] = currIndex;
        return (smallAns + 1);
    }
    return smallAns;
}

int allIndexes(int input[], int size, int x, int output[]) {
    int count = allIndexesHelper(input, size, x, 0, output);
    int *temp = new int[count];
    for(int i=0; i<count; i++) {
        temp[count-1-i] = output[i];
    }
    for(int i=0; i<count; i++) {
        output[i] = temp[i];
    }
    delete []temp;
    return count;
}

int main() {
    int n, x;
    cin >> n;
    int *input = new int[n];
    for(int i=0; i<n; i++) {
        cin >> input[i];
    }
    cin >> x;
    int *output = new int[n];
    int count = allIndexes(input, n, x, output);
    for(int i=0; i<count; i++) {
        cout << output[i] << " ";
    }
    cout << endl;
    delete []input;
    delete []output;
    return 0;
}