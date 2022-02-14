// Time Complexity = O(N)
// Space Complexity = O(N)


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;
    int *arr = new int[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    bool flag = false;
    int start = 0, end = 0, sum = 0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
        if(sum == target) {
            flag = true;
            end = i;
            break;
        }
        else if(sum < target) {
            continue;
        }
        else {
            if(arr[i] == target) {
                start = i;
                end = i;
                flag = true;
                break;
            }
            else if(arr[i] > target) {
                sum = 0;
                start = i+1;
            }
            else {
                sum = arr[i];
                start = i;
            }
        }
    }
    if(flag == true) {
        cout << "true" << endl;
        for(int i=start; i<=end; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "false" << endl;
    }
    delete []arr;
    return 0;
}