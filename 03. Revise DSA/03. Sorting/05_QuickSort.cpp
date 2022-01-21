// Time Complexity = O(NlogN)
// Space Complexity = O(1)


#include <iostream>
using namespace std;

void quickSortHelper(int* input, int s, int e) {
    if(s >= e) {
        return;
    }
    int mid = (s+e) / 2;
    int i=s, j=e, ele = input[mid];
    while(i<j) {
        while(input[i] < ele) {
            i++;
        }
        while(input[j] > ele) {
            j--;
        }
        int temp = input[i];
        input[i] = input[j];
        input[j] = temp;
    }
    quickSortHelper(input, s, mid-1);
    quickSortHelper(input, mid+1, e);
    return;
}

void quickSort(int input[], int size) {
    if(size <= 1) {
        return;
    }
    return quickSortHelper(input, 0, size-1);
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    quickSort(arr, n);
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    delete []arr;
    return 0;
}