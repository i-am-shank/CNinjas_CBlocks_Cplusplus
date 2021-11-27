#include <iostream>
using namespace std;

void merge(int *arr1, int size1, int* arr2, int size2) {
    int i=0, j=0, k=0;
    int *temp = new int[size1+size2];
    while(i<size1 && j<size2) {
        if(arr1[i]<=arr2[j]) {
            temp[k++] = arr1[i++];
        }
        else {
            temp[k++] = arr2[j++];
        }
    }
    while(i<size1) {
        temp[k++] = arr1[i++];
    }
    while(j<size2) {
        temp[k++] = arr2[j++];
    }
    for (int i=0; i<size1+size2; i++) {
        arr1[i] = temp[i];
    }
    delete [] temp;
    return;
}

void mergeSort(int *arr, int size) {
    if(size < 2) {
        return;
    }
    int mid = (size)/ 2;
    mergeSort(arr, mid);
    mergeSort(arr, size-mid);
    merge(arr, mid, arr+mid, size-mid);
    return;
}

void intersection(int *arr1, int *arr2, int n, int m) {
    mergeSort(arr1, n);
    mergeSort(arr2, m);
    int i=0, j=0;
    while(i<n && j<m) {
        if(arr1[i] == arr2[j]) {
            cout << arr1[i] << endl;
            i++;
            j++;
        }
        else if(arr1[i] < arr2[j]) {
            i++;
        }
        else {
            j++;
        }
    }
    cout << endl;
    return;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n;
        int *arr1 = new int[n];
        for (int i=0; i<n; i++) {
            cin >> arr1[i];
        }
        cin >> m;
        int *arr2 = new int[m];
        for (int i=0; i<m; i++) {
            cin >> arr2[i];
        }
        intersection(arr1, arr2, n, m);
        delete []arr1;
        delete []arr2;
    }
    return 0;
}