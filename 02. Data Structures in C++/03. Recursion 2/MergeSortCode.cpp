// Time Complexity = O(NlogN)
// Space Complexity = O(N)


#include <iostream>
using namespace std;

void merge(int input1[], int size1, int input2[], int size2) {
    int temp[size1 + size2], i=0, j=0, k=0;
    while (i<size1 && j<size2) {
        if (input1[i] <= input2[j]) {
            temp[k++] = input1[i++];
        }
        else {
            temp[k++] = input2[j++];
        }
    }
    while (i < size1) {
        temp[k++] = input1[i++];
    }
    while (j < size1) {
        temp[k++] = input2[j++];
    }
    for (int l=0; l<k; l++) {
        input1[l] = temp[l];
    }
    return;
}

void mergeSort(int input[], int size) {
    if (size < 2) {
        return;
    }
    int mid = size/2;
    mergeSort(input, mid);
    mergeSort(input+mid, size-mid);
    merge(input, mid, input+mid, size-mid);
    return;
}

int main() {
    int size;
    cin >> size;
    int *input = new int [size];
    for (int i=0; i<size; i++) {
        cin >> input[i];
    }
    mergeSort(input, size);
    for (int i=0; i<size; i++) {
        cout << input[i] << ' ';
    }
    delete []input;
    return 0;
}