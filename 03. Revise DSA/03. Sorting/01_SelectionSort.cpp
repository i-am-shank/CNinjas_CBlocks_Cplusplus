// Time Complexity = O(N^2)
// Space Complexity = O(1)


#include <iostream>
using namespace std;

// Algorithm (Selection Sort) :-
//    1. Search smallest element.
//    2. Swap with element at starting index.
//    3. Recursion call for index (start+1  __to__  end)

void selectionSort(int*& arr, int start, int end) {
    if(start > end) {
        return;
    }
    int smallestI = start;
    for(int i=start; i<=end; i++) {
        if(arr[i] < arr[smallestI]) {
            smallestI = i;
        }
    }
    int temp = arr[smallestI];
    arr[smallestI] = arr[start];
    arr[start] = temp;
    selectionSort(arr, start+1, end);
    return;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    selectionSort(arr, 0, n-1);
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete []arr;
    return 0;
}