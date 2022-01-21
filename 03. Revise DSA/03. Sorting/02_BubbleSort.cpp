// Time Complexity = O(N^2)
// Space Complexity = O(1)


#include <iostream>
using namespace std;

// Algorithm (Bubble Sort) :-
//      1. From i=start to i+1=end , swap consecutive pairs(bubbles) --> (i & i+1).
//      2. After 1st iteration, largest element at end. (reverse of Selection sort)
//      3. Recursion call for index (start  __to__  end-1).

void bubbleSort(int* &arr, int start, int end) {
    if(start >= end) {
        return;
    }
    for(int i=start; i<end; i++) {
        if(arr[i] > arr[i+1]) {
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
    bubbleSort(arr, start, end-1);
    return;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    bubbleSort(arr, 0, n-1);
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete []arr;
    return 0;
}