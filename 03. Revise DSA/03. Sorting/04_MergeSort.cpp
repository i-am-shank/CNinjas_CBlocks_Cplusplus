// Time Complexity = O(NlogN)
// Space Complexity = O(N)


#include <iostream>
using namespace std;

void merge(int* arr1, int size1, int* arr2, int size2) {
    int i=0, j=0, k=0;
    int *arr = new int[size1 + size2];
    while(i<size1 && j<size2) {
        if(arr1[i] <= arr2[j]) {
            arr[k++] = arr1[i++];
        }
        else{
            arr[k++] = arr2[j++];
        }
    }
    while(i < size1) {
        arr[k++] = arr1[i++];
    }
    while(j < size2) {
        arr[k++] = arr2[j++];
    }
    for(int l=0; l<k; l++) {
        arr1[l] = arr[l];
    }
    delete []arr;
    return;
}

void mergeSort(int input[], int size) {
    if(size <= 1) {
        return;
    }
    int mid = size / 2;
    mergeSort(input, mid);
    mergeSort(input+mid, size-mid);
    merge(input, mid, input+mid, size-mid);
    return;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    mergeSort(arr, n);
    for(int i=0 ; i<n; i++) {
        cout << arr[i] << " ";
    }
    delete []arr;
    return 0;
}