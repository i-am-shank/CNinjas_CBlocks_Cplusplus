// Time Complexity = O(N^2)
// Space Complexity = O(N)


#include <iostream>
using namespace std;

// Algorithm (Insertion Sort) :-
//      1. For each element, count no. of inserted array elements less than element.
//      2. Shift all the elements from (count  __to__  end) by 1 place towards end.
//      3. Recursion call for next element.

void insertionSort(int* &arr, int start, int end, int* &ans, int size) {
    if(start > end) {
        return;
    }
    int ele = arr[start], count = 0;
    for(int i=0; i<size; i++) {
        if(ans[i] < ele) {
            count ++;
        }
    }
    if(size > 0) {
        for(int i=size-1; i>=count; i--) {
            ans[i+1] = ans[i];
        }
    }
    ans[count] = ele;
    insertionSort(arr, start+1, end, ans, size+1);
    return;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int *ans = new int[n];
    insertionSort(arr, 0, n-1, ans, 0);
    for(int i=0; i<n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    delete []arr;
    delete []ans;
    return 0;
}