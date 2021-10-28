// Time Complexity = O(N)
// Space Complexity = O(1)


#include <iostream>
using namespace std;

void print(int n) {
    if (n == 1) {
        cout << n << " ";
        return;
    }
    print(n-1);
    cout << n << " ";
    return;
}

int main() {
    int n;
    cin >> n;
    print(n);
    return 0;
}