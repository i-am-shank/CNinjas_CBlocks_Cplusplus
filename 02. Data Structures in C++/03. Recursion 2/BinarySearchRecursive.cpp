// Time Complexity = O(logN)
// Space Complexity = O(N)


#include <iostream>
using namespace std;

int binarySearchHelper(int input[], int start, int end, int element) {
    if (start > end) {
        return -1;
    }
    int mid = (start+end) / 2;
    if (input[mid] == element) {
        return mid;
    }
    else if (input[mid] < element) {
        return binarySearchHelper(input, mid+1, end, element);
    }
    else {
        return binarySearchHelper(input, start, mid-1, element);
    }
}

int binarySearch(int input[], int size, int element) {
    return binarySearchHelper(input, 0, size-1, element);
}

int main() {
    int size, element, ans;
    cin >> size;
    int *input = new int[size];
    for (int i=0; i<size; i++) {
        cin >> input[i];
    }
    cin >> element;
    ans = binarySearch(input, size, element);
    cout << ans << endl;
    delete []input;
    return 0;
}