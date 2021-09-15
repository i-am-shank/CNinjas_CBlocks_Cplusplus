// Time Complexity = O(n)
// Space Complexity = O(1)

#include <iostream>
using namespace std;

int main(){
    int x, t, j = 1, count=1;
    cin >> x;
    while (count <= x){
        t = (3*j) + 2;
        j++;
        if (t % 4 != 0){
            cout << t << " ";
            count++;
        }
    }
    cout << endl;
}