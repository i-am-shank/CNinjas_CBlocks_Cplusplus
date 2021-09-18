// Time Complexity = O(n)
// Space Complexity = O(1)


#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, i, ele, l=INT_MIN, sl=INT_MIN;
    cin >> n;
    if (n==0 || n==1){
        cout << INT_MIN;
        return 0;
    }
    for (i=1; i<=n; i++){
        cin >> ele;
        if (ele > l){
            sl = l;
            l = ele;
        }
        else if (ele > sl && ele != l){
            sl = ele;
        }
        else {
            continue;
        }
    }
    cout << sl << endl;
}