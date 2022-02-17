// Time Complexity = O(logN)
// Space Complexity = O(logN)
//        .. O(1) space waiting in each recursion call.


#include <bits/stdc++.h>
using namespace std;

int count(int n){
    if(n == 0){
        return 0;
    }
    int smallAns = count(n / 10);
    return smallAns + 1;
}

int main() {
    int n;
    cin >> n;
    int ans = count(n);
    cout << ans << endl;
    return 0;
}