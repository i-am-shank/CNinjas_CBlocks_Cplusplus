// Time Complexity = O(1)
// Space Complexity = O(1)


#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        long row, col;    //  row , column
        cin >> row >> col;
        long maxEdge = max(row, col);
        long ans = (maxEdge - 1) * (maxEdge - 1);    //  Minimum value should be greater than this.
        if(maxEdge % 2 == 0) {    //  even maxEdge   =   row --> column  (No. arrangement order)
            if(maxEdge == row) {
                ans += (maxEdge  +  (maxEdge - col));
            }
            else {
                ans += row;
            }
        }
        else {    //  odd maxEdge   =   column --> row  (No. arrangement order)
            if(maxEdge == row) {
                ans += col;
            }
            else {
                ans += (maxEdge  +  (maxEdge - row));
            }
        }
        cout << ans << endl;
    }
    return 0;
}