// Time Complexity = O(N*2)
// Space Complexity = O(N)


#include <iostream>
using namespace std;

void Leaders(int* arr,int len) {
    bool flag;
    int temp;
    for (int i=0; i<len; i++) {
        temp = arr[i];
        flag = true;
        for (int j=(i+1); j<len; j++) {
            if (temp < arr[j]) {
                flag = false;
                break;
            }
        }
        if (flag == true) {
            cout << temp << ' ';
        }
    }
    return;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int [n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    Leaders(arr, n);
    delete []arr;
    return 0;
}