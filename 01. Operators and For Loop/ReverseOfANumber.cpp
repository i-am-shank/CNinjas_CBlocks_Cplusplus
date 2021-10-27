// Time Complexity = O(n)
// Space Complexity = O(1)

#include <iostream>
using namespace std;

int main(){
    int n, rev=0, u;
    cin >> n;
    while (n > 0){
        u = n%10;
        rev = (rev*10) + u;
        n /= 10;
    }
    cout << rev << endl;
}